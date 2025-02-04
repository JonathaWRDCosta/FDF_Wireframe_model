/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 03:28:13 by jonathro          #+#    #+#             */
/*   Updated: 2025/02/03 00:55:14 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_background(t_vars *vars)
{
	int	*background;
	int	pixels;
	int	i;

	if (!vars || !vars->mlx || !vars->mlx->data_addr)
		return ;
	background = (int *)(vars->mlx->data_addr);
	pixels = WIN_HEIGHT * WIN_WIDTH;
	i = 0;
	while (i < pixels)
	{
		background[i] = BG_COLOR;
		i++;
	}
}

void	destroy_win(t_mlx *mlx)
{
	if (!mlx)
		return ;
	if (mlx->banner_img_ptr)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->banner_img_ptr);
		mlx->banner_img_ptr = NULL;
	}
	if (mlx->img_ptr)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		mlx->img_ptr = NULL;
	}
	if (mlx->win_ptr)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->win_ptr = NULL;
	}
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr);
		mlx->mlx_ptr = NULL;
	}
}
