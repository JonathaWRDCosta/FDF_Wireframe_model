/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:34:57 by jonatha           #+#    #+#             */
/*   Updated: 2025/01/16 18:36:58 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <stdlib.h>
#include <limits.h>

// Calculates the length of an unsigned long array terminated with NULL
static size_t	ulong_arr_len(unsigned long *arr)
{
	size_t	i;

	if (!arr)
		return (0);
	i = 0;
	while (arr[i])
		i++;
	return (i);
}

// Converts a string "z,color" into an unsigned long point value
static unsigned long	get_point(char *point)
{
	unsigned long	ret;
	unsigned int	color;
	char			**point_attrs;
	int				z;

	if (!point || !*point)
		return (ULONG_MAX);

	point_attrs = ft_split(point, ',');
	if (!point_attrs)
		return (ULONG_MAX);

	z = ft_atoi(point_attrs[0]);
	if (!*(point_attrs + 1))
		color = LINE_COLOR;
	else
		color = atoi_hex(point_attrs[1] + 2); // Skip "0x"

	ret = (((unsigned long)z) << 32) | (color);
	free_str_arr(point_attrs);
	return (ret);
}

// Converts a map row string into an array of unsigned long values
static unsigned long	*get_map_row(char *map_row)
{
	unsigned long	*row;
	char			**str_row;
	size_t			row_len;
	size_t			i;

	if (!map_row || !*map_row)
		return (NULL);

	str_row = ft_split(map_row, ' ');
	if (!str_row)
		return (NULL);

	row_len = ulong_arr_len((unsigned long *)str_row);
	row = malloc(sizeof(unsigned long) * (row_len + 1));
	if (!row)
	{
		free_str_arr(str_row);
		return (NULL);
	}

	i = 0;
	while (str_row[i])
	{
		row[i] = get_point(str_row[i]);
		if (row[i] == ULONG_MAX)
		{
			ft_putstr_fd("Error: Invalid point in map row.\n", STDERR_FILENO);
			free(row);
			free_str_arr(str_row);
			return (NULL);
		}
		i++;
	}
	row[row_len] = ULONG_MAX;
	free_str_arr(str_row);
	return (row);
}

// Converts the raw map string into a 2D array of unsigned long values
unsigned long	**split_raw_map(char *raw_map)
{
	unsigned long	**map;
	char			**str_map;
	size_t			col_size;
	size_t			i;

	if (!raw_map || !*raw_map)
		return (NULL);

	str_map = ft_split(raw_map, '\n');
	if (!str_map)
		return (NULL);

	col_size = ulong_arr_len((unsigned long *)str_map);
	map = malloc((col_size + 1) * sizeof(unsigned long *));
	if (!map)
	{
		free_str_arr(str_map);
		return (NULL);
	}

	i = 0;
	while (str_map[i])
	{
		map[i] = get_map_row(str_map[i]);
		if (!map[i])
		{
			ft_putstr_fd("Error: Failed to parse map row.\n", STDERR_FILENO);
			free_ulong_arr(map);
			free_str_arr(str_map);
			return (NULL);
		}
		i++;
	}
	map[col_size] = NULL;

	free_str_arr(str_map);
	return (map);
}
