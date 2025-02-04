/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:41:05 by jonathro          #+#    #+#             */
/*   Updated: 2025/02/03 01:43:26 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <limits.h>
#include <stdlib.h>

static unsigned long	get_point(char *point)
{
	unsigned long	ret;
	unsigned int	color;
	char			**point_attrs;
	int				z;

	point_attrs = ft_split(point, ',');
	if (!point_attrs)
		return (ULONG_MAX);
	z = ft_atoi(point_attrs[0]);
	if (point_attrs[1])
		color = atoi_hex(point_attrs[1] + 2);
	else
		color = LINE_COLOR;
	ret = (((unsigned long)z) << 32) | color;
	free_str_arr(point_attrs);
	return (ret);
}

static size_t	count_str_row(char **str_row)
{
	size_t	i;

	i = 0;
	while (str_row[i])
		i++;
	return (i);
}

static int	fill_map_row(char **str_row, unsigned long *row, size_t row_len)
{
	size_t	i;

	i = 0;
	while (i < row_len)
	{
		row[i] = get_point(str_row[i]);
		if (row[i] == ULONG_MAX)
			return (-1);
		i++;
	}
	return (0);
}

unsigned long	*get_map_row(char *map_row)
{
	unsigned long	*row;
	char			**str_row;
	size_t			row_len;

	str_row = ft_split(map_row, ' ');
	if (!str_row)
		return (NULL);
	row_len = count_str_row(str_row);
	row = malloc(sizeof(unsigned long) * (row_len + 1));
	if (!row)
	{
		free_str_arr(str_row);
		return (NULL);
	}
	if (fill_map_row(str_row, row, row_len) == -1)
	{
		free(row);
		free_str_arr(str_row);
		return (NULL);
	}
	row[row_len] = ULONG_MAX;
	free_str_arr(str_row);
	return (row);
}

unsigned long	**build_map_from_lines(char **lines)
{
	unsigned long	**map;
	size_t			col_size;
	size_t			i;

	col_size = 0;
	while (lines[col_size])
		col_size++;
	map = malloc((col_size + 1) * sizeof(unsigned long *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < col_size)
	{
		map[i] = get_map_row(lines[i]);
		if (!map[i])
		{
			while (i > 0)
				free(map[--i]);
			free(map);
			return (NULL);
		}
		i++;
	}
	map[col_size] = NULL;
	return (map);
}
