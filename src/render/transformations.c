/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transformations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:42:36 by jonathro          #+#    #+#             */
/*   Updated: 2025/01/29 00:57:18 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

void	zoom(t_camera *camera, t_point *point)
{
	if (!camera || !point)
	{
		ft_putstr_fd("Error: Invalid camera or point in zoom.\n", FDF_STDERR);
		return ;
	}
	point->x *= camera->zoom;
	point->y *= camera->zoom;
	point->z *= camera->zoom;
}

void	translate(t_vars *vars, t_point *point)
{
	if (!vars || !point)
	{
		ft_putstr_fd("Error: Invalid vars or point in translate.\n",
			FDF_STDERR);
		return ;
	}
	point->x += vars->anchor_x;
	point->y -= vars->anchor_y;
}

void	rotate_z_x(t_camera *camera, t_point *point)
{
	double	original_z;
	double	original_x;

	if (!camera || !point)
	{
		ft_putstr_fd("Error: Invalid camera or point in rotate_z_x.\n",
			FDF_STDERR);
		return ;
	}
	original_z = point->z;
	original_x = point->x;
	point->z = original_z * cos(camera->z_x_coef) + original_x *
		-sin(camera->z_x_coef);
	point->x = original_z * sin(camera->z_x_coef) + original_x
		* cos(camera->z_x_coef);
}

void	rotate_y_z(t_camera *camera, t_point *point)
{
	double	original_y;
	double	original_z;

	if (!camera || !point)
	{
		ft_putstr_fd("Error: Invalid camera or point in rotate_y_z.\n",
			FDF_STDERR);
		return ;
	}
	original_y = point->y;
	original_z = point->z;
	point->y = original_z * sin(camera->y_z_coef) + original_y
		* cos(camera->y_z_coef);
	point->z = original_z * cos(camera->y_z_coef) + original_y *
		-sin(camera->y_z_coef);
}

void	rotate_x_y(t_camera *camera, t_point *point)
{
	double	original_x;
	double	original_y;

	if (!camera || !point)
	{
		ft_putstr_fd("Error: Invalid camera or point in rotate_x_y.\n",
			FDF_STDERR);
		return ;
	}
	original_x = point->x;
	original_y = point->y;
	point->x = original_x * cos(camera->x_y_coef) + original_y *
		-sin(camera->x_y_coef);
	point->y = original_x * sin(camera->x_y_coef) + original_y
		* cos(camera->x_y_coef);
}
