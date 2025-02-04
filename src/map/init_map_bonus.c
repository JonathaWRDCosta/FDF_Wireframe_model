/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 23:54:44 by jonatha          #+#    #+#             */
/*   Updated: 2025/01/29 00:52:56 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	get_row_size(unsigned long **map)
{
	int	row_size;

	row_size = 0;
	while (map[0][row_size] != ULONG_MAX)
		row_size++;
	return (row_size);
}

static int	get_col_size(unsigned long **map)
{
	int	col_size;

	col_size = 0;
	while (map[col_size])
		col_size++;
	return (col_size);
}

static void	init_map_props(t_vars *vars)
{
	if (!vars || !vars->map || !vars->map[0])
		return ;
	vars->row_size = get_row_size(vars->map);
	vars->anchor_x = vars->row_size / 2;
	vars->col_size = get_col_size(vars->map);
	vars->anchor_y = vars->col_size / 2;
}

int	init_map(t_vars *vars, char *filename)
{
	char	*raw_map;

	if (!vars || !filename)
		return (-1);
	raw_map = get_raw_map(filename);
	if (!raw_map)
		return (-1);
	vars->map = split_raw_map(raw_map);
	free(raw_map);
	if (!vars->map)
		return (-1);
	init_map_props(vars);
	return (0);
}
