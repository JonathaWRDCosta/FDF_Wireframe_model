/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_utils_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:50:43 by jonathro          #+#    #+#             */
/*   Updated: 2025/02/03 02:11:39 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "libft.h"
#include <limits.h>
#include <stdlib.h>

size_t	count_tokens(char **tokens)
{
	size_t	len;

	len = 0;
	while (tokens[len])
		len++;
	return (len);
}

static unsigned long	get_point(char *point)
{
	unsigned long	ret;
	unsigned int	color;
	char			**point_attrs;
	int				z;

	if (!point)
		return (ULONG_MAX);
	point_attrs = ft_split(point, ',');
	if (!point_attrs)
		return (ULONG_MAX);
	z = ft_atoi(point_attrs[0]);
	if (*(point_attrs + 1))
		color = atoi_hex(*(point_attrs + 1));
	else
		color = LINE_COLOR;
	ret = (((unsigned long)z) << 32) | color;
	free_str_arr(point_attrs);
	return (ret);
}

static void	fill_row(unsigned long *row, char **tokens, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		row[i] = get_point(tokens[i]);
		i++;
	}
}

static unsigned long	*get_map_row(char *map_row)
{
	unsigned long	*row;
	char			**tokens;
	size_t			len;

	if (!map_row)
		return (NULL);
	tokens = ft_split(map_row, ' ');
	if (!tokens)
		return (NULL);
	len = count_tokens(tokens);
	row = malloc(sizeof(unsigned long) * (len + 1));
	if (!row)
	{
		free_str_arr(tokens);
		return (NULL);
	}
	fill_row(row, tokens, len);
	row[len] = ULONG_MAX;
	free_str_arr(tokens);
	return (row);
}

unsigned long	**build_map_from_lines(char **lines)
{
	unsigned long	**map;
	size_t			count;
	size_t			i;

	count = count_tokens(lines);
	map = malloc((count + 1) * sizeof(unsigned long *));
	if (!map)
		return (NULL);
	i = 0;
	while (i < count)
	{
		map[i] = get_map_row(lines[i]);
		if (!map[i])
		{
			while (i > 0)
			{
				free(map[--i]);
			}
			free(map);
			return (NULL);
		}
		i++;
	}
	map[count] = NULL;
	return (map);
}
