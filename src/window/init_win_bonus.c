/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 03:28:43 by jonathro          #+#    #+#             */
/*   Updated: 2025/02/03 01:31:51 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	init_win(t_vars *vars)
{
	if (!vars)
		return (-1);
	vars->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!vars->mlx)
		return (-1);
	vars->mlx->mlx_ptr = NULL;
	vars->mlx->win_ptr = NULL;
	vars->mlx->img_ptr = NULL;
	vars->mlx->banner_img_ptr = NULL;
	if (setup_win_bonus(vars->mlx) == -1)
	{
		free(vars->mlx);
		return (-1);
	}
	mlx_hook(vars->mlx->win_ptr, DestroyNotify, 0, destroy_handler, vars->mlx);
	mlx_hook(vars->mlx->win_ptr, KeyPress, KeyPressMask,
		keypress_handler, vars);
	init_renderer(vars);
	mlx_loop_hook(vars->mlx->mlx_ptr, animation_loop, vars);
	mlx_loop(vars->mlx->mlx_ptr);
	destroy_win(vars->mlx);
	free(vars->mlx);
	return (0);
}
