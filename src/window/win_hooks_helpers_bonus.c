/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_hooks_helpers_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 03:28:28 by jonathro          #+#    #+#             */
/*   Updated: 2025/02/03 01:29:18 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	transformation_keys(int keycode, t_vars *vars)
{
	if (keycode == XK_e)
		vars->x_y_coef += 0.1;
	else if (keycode == XK_q)
		vars->x_y_coef -= 0.1;
	else if (keycode == XK_w)
		vars->y_z_coef += 0.1;
	else if (keycode == XK_s)
		vars->y_z_coef -= 0.1;
	else if (keycode == XK_a)
		vars->z_x_coef -= 0.1;
	else if (keycode == XK_d)
		vars->z_x_coef += 0.1;
	else if (keycode == XK_Right)
		vars->map_x += 5;
	else if (keycode == XK_Left)
		vars->map_x -= 5;
	else if (keycode == XK_Up)
		vars->map_y += 5;
	else if (keycode == XK_Down)
		vars->map_y -= 5;
}

void	reset_camera_props(t_vars *vars)
{
	vars->x_y_coef = 0;
	vars->y_z_coef = 0;
	vars->z_x_coef = 0;
}

void	projection_keys(int keycode, t_vars *vars)
{
	if (!vars)
		return ;
	if (keycode == XK_n)
		vars->zoom += 0.1;
	else if (keycode == XK_m && vars->zoom > 0.2)
		vars->zoom -= 0.1;
	else if (keycode == XK_j)
		vars->height -= 0.5;
	else if (keycode == XK_k)
		vars->height += 0.5;
	else if (keycode == XK_r)
	{
		vars->is_animating = 0;
		set_camera_props(vars);
	}
	else if (keycode == XK_t)
	{
		vars->is_animating = 0;
		reset_camera_props(vars);
	}
}

void	handle_exit(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		vars->is_animating = 0;
		destroy_handler(vars->mlx);
	}
}

void	toggle_animation(int keycode, t_vars *vars)
{
	if (keycode == XK_space)
		vars->is_animating = !vars->is_animating;
}
