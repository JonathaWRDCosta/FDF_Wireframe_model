/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:41:44 by jonathro          #+#    #+#             */
/*   Updated: 2025/01/29 00:53:03 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <limits.h>
#include <stdlib.h>

static void	calculate_map_properties(t_vars *vars)
{
	int	row_length;
	int	col_length;

	row_length = 0;
	col_length = 0;
	while (vars->map.data[0][row_length] != ULONG_MAX)
		row_length++;
	vars->map.row_size = row_length;
	vars->anchor_x = row_length / 2;
	while (vars->map.data[col_length])
		col_length++;
	vars->map.col_size = col_length;
	vars->anchor_y = col_length / 2;
}

int	init_map(t_vars *vars, char *filename)
{
	char	*raw_map;

	raw_map = get_raw_map(filename);
	if (!raw_map)
	{
		ft_putstr_fd("Error: Failed to read the map file.\n", FDF_STDERR);
		return (-1);
	}
	vars->map.data = split_raw_map(raw_map);
	free(raw_map);
	if (!vars->map.data)
	{
		ft_putstr_fd("Error: Failed to parse the map.\n", FDF_STDERR);
		return (-1);
	}
	calculate_map_properties(vars);
	return (0);
}
