/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:39:34 by jonathro          #+#    #+#             */
/*   Updated: 2025/02/04 00:14:49 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <limits.h>
#include <stdlib.h>

size_t	ulong_arr_len(unsigned long *arr)
{
	size_t	i;

	i = 0;
	while (arr[i] != ULONG_MAX)
		i++;
	return (i);
}

unsigned long	**split_raw_map(char *raw_map)
{
	unsigned long	**map;
	char			**lines;
	size_t			col_size;

	lines = ft_split(raw_map, '\n');
	if (!lines)
	{
		ft_putstr_fd("Error: Failed to split raw map.\n", FDF_STDERR);
		return (NULL);
	}
	col_size = 0;
	while (lines[col_size])
		col_size++;
	map = build_map_from_lines(lines);
	free_str_arr(lines);
	if (!map)
	{
		ft_putstr_fd("Error: Failed to allocate memory for map.\n", FDF_STDERR);
		return (NULL);
	}
	return (map);
}
