/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_renderer_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 03:29:31 by jonathro          #+#    #+#             */
/*   Updated: 2025/01/28 03:30:24 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	init_renderer(t_vars *vars)
{
	if (!vars || !vars->mlx || !vars->mlx->mlx_ptr || !vars->mlx->win_ptr)
		return;

	set_camera_props(vars);
	draw_background(vars);
	render_map(vars);

	mlx_put_image_to_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr,
		vars->mlx->banner_img_ptr, 0, 0);
}

