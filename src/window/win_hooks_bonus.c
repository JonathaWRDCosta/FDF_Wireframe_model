/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 03:28:28 by jonathro          #+#    #+#             */
/*   Updated: 2025/02/03 01:02:38 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	animation_loop(t_vars *vars)
{
	if (!vars || !vars->mlx || !vars->mlx->mlx_ptr || !vars->mlx->win_ptr)
		return (0);
	if (vars->is_animating)
	{
		mlx_clear_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr);
		vars->z_x_coef += ANIMATION_STEP;
		draw_background(vars);
		render_map(vars);
		mlx_put_image_to_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr,
			vars->mlx->banner_img_ptr, 0, 0);
		usleep(ANIMATION_DELAY);
	}
	return (1);
}

int	destroy_handler(t_mlx *mlx)
{
	if (!mlx || !mlx->mlx_ptr)
		return (1);
	mlx_loop_end(mlx->mlx_ptr);
	return (0);
}

int	keypress_handler(int keycode, t_vars *vars)
{
	if (!vars || !vars->mlx)
		return (0);
	transformation_keys(keycode, vars);
	projection_keys(keycode, vars);
	handle_exit(keycode, vars);
	toggle_animation(keycode, vars);
	draw_background(vars);
	render_map(vars);
	mlx_put_image_to_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr,
		vars->mlx->banner_img_ptr, 0, 0);
	return (0);
}
