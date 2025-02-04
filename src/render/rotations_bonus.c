/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 00:35:59 by jonathro          #+#    #+#             */
/*   Updated: 2025/02/03 00:47:32 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"
#include <math.h>

static void	rotate(double coef, double *a, double *b)
{
	double	original_a;

	original_a = *a;
	*a = original_a * cos(coef) + *b * -sin(coef);
	*b = original_a * sin(coef) + *b * cos(coef);
}

void	rotate_z_x(t_vars *vars, t_point *point)
{
	double	x;
	double	z;

	if (!vars || !point)
		return ;
	z = (double)point->z;
	x = (double)point->x;
	rotate(vars->z_x_coef, &z, &x);
	point->z = (int)z;
	point->x = (int)x;
}

void	rotate_y_z(t_vars *vars, t_point *point)
{
	double	y;
	double	z;

	if (!vars || !point)
		return ;
	y = (double)point->y;
	z = (double)point->z;
	rotate(vars->y_z_coef, &y, &z);
	point->y = (int)y;
	point->z = (int)z;
}

void	rotate_x_y(t_vars *vars, t_point *point)
{
	double	x;
	double	y;

	if (!vars || !point)
		return ;
	x = (double)point->x;
	y = (double)point->y;
	rotate(vars->x_y_coef, &x, &y);
	point->x = (int)x;
	point->y = (int)y;
}
