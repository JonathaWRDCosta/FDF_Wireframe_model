/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:53:47 by jonatha           #+#    #+#             */
/*   Updated: 2025/01/16 18:54:08 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

// Applies zoom to a point
void	zoom(t_vars *vars, t_point *point)
{
	if (vars->zoom <= 0)
	{
		ft_putstr_fd("Error: Zoom factor must be greater than 0.\n", STDERR_FILENO);
		return;
	}

	point->x *= vars->zoom;
	point->y *= vars->zoom;
	point->z *= vars->zoom;
}

// Translates a point by the specified offsets
void	translate(t_vars *vars, t_point *point)
{
	point->x += vars->map_x;
	point->y -= vars->map_y;
}

// Rotates a point around the Z-X plane
void	rotate_z_x(t_vars *vars, t_point *point)
{
	double	temp_z;

	temp_z = point->z;
	point->z = temp_z * cos(vars->z_x_coef) + point->x * -sin(vars->z_x_coef);
	point->x = temp_z * sin(vars->z_x_coef) + point->x * cos(vars->z_x_coef);
}

// Rotates a point around the Y-Z plane
void	rotate_y_z(t_vars *vars, t_point *point)
{
	double	temp_y;

	temp_y = point->y;
	point->y = point->z * sin(vars->y_z_coef) + temp_y * cos(vars->y_z_coef);
	point->z = point->z * cos(vars->y_z_coef) + temp_y * -sin(vars->y_z_coef);
}

// Rotates a point around the X-Y plane
void	rotate_x_y(t_vars *vars, t_point *point)
{
	double	temp_x;

	temp_x = point->x;
	point->x = temp_x * cos(vars->x_y_coef) + point->y * -sin(vars->x_y_coef);
	point->y = temp_x * sin(vars->x_y_coef) + point->y * cos(vars->x_y_coef);
}
