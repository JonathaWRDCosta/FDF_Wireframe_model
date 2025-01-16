/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:51:06 by jonatha           #+#    #+#             */
/*   Updated: 2025/01/16 18:51:13 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>
#include <unistd.h>

// Fills the background with the specified color
void	draw_background(t_vars *vars)
{
	int	*background;
	int	i;

	if (!vars || !vars->mlx || !vars->mlx->data_addr)
	{
		ft_putstr_fd("Error: Invalid variables in draw_background.\n", STDERR_FILENO);
		return;
	}

	background = (int *)(vars->mlx->data_addr);
	i = 0;
	while (i < WIN_HEIGHT * WIN_WIDTH)
	{
		background[i] = BG_COLOR;
		i++;
	}

	ft_putstr_fd("Background drawn successfully.\n", STDOUT_FILENO);
}

// Frees all resources associated with the window and MiniLibX context
void	destroy_win(t_mlx *mlx)
{
	if (!mlx)
		return;

	if (mlx->img_ptr)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		ft_putstr_fd("Image destroyed.\n", STDOUT_FILENO);
	}

	if (mlx->win_ptr)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_putstr_fd("Window destroyed.\n", STDOUT_FILENO);
	}

	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		ft_putstr_fd("Display destroyed.\n", STDOUT_FILENO);
		free(mlx->mlx_ptr);
		ft_putstr_fd("MiniLibX context freed.\n", STDOUT_FILENO);
	}
}
