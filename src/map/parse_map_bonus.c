/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:54:56 by jonatha          #+#    #+#             */
/*   Updated: 2025/02/03 02:07:29 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include "libft.h"
#include <stdlib.h>

unsigned long	**split_raw_map(char *raw_map)
{
	unsigned long	**map;
	char			**lines;

	if (!raw_map)
		return (NULL);
	lines = ft_split(raw_map, '\n');
	if (!lines)
		return (NULL);
	map = build_map_from_lines(lines);
	free_str_arr(lines);
	return (map);
}
