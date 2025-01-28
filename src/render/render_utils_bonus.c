/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 03:29:15 by jonathro          #+#    #+#             */
/*   Updated: 2025/01/28 06:11:32 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

unsigned long	get_z(unsigned long point)
{
	return (point >> 32);
}

unsigned long	get_color(unsigned long point)
{
	return (point & COLOR_MASK);
}

void	set_camera_props(t_vars *vars)
{
	double	width_distance;
	double	height_distance;

	if (!vars)
		return;

	width_distance = (double)(PADDED_WIDTH) / vars->row_size;
	height_distance = (double)(PADDED_HEIGHT) / vars->col_size;
	vars->distance = (width_distance > height_distance) ? height_distance : width_distance;
	vars->height = -5;
	vars->zoom = 0.7;
	vars->x_y_coef = -0.4;
	vars->y_z_coef = -0.9;
	vars->z_x_coef = 0;
	vars->map_x = 200;
	vars->map_y = 50;
	vars->is_animating = 0;
}

void	set_point(t_point *point, int x, int y, int z)
{
	if (!point)
		return;

	point->x = x;
	point->y = y;
	point->z = z;
}

void	render_point(t_vars *vars, t_point *point)
{
	if (!vars || !point)
		return;

	point->x = (point->x - vars->anchor_x) * vars->distance;
	point->y = (point->y - vars->anchor_y) * vars->distance;
	point->z = point->z * vars->height;

	rotate_x_y(vars, point);
	rotate_y_z(vars, point);
	rotate_z_x(vars, point);
	translate(vars, point);
	zoom(vars, point);
}

