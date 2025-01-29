/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:42:45 by jonathro          #+#    #+#             */
/*   Updated: 2025/01/29 00:57:59 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <stdlib.h>

void	draw_background(t_vars *vars)
{
	int	*background;
	int	i;

	if (!vars || !vars->mlx || !vars->mlx->data_addr)
	{
		ft_putstr_fd("Error: Invalid vars or data_addr in draw_background.\n",
			FDF_STDERR);
		return ;
	}
	background = (int *)(vars->mlx->data_addr);
	i = 0;
	while (i < WIN_HEIGHT * WIN_WIDTH)
	{
		background[i] = BG_COLOR;
		i++;
	}
}

void	destroy_win(t_mlx *mlx)
{
	if (!mlx)
	{
		ft_putstr_fd("Error: Invalid mlx pointer in destroy_win.\n",
			FDF_STDERR);
		return ;
	}
	if (mlx->img_ptr)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		ft_putstr_fd("Info: Image destroyed.\n", FDF_STDERR);
	}
	if (mlx->win_ptr)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		ft_putstr_fd("Info: Window destroyed.\n", FDF_STDERR);
	}
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		ft_putstr_fd("Info: Display destroyed.\n", FDF_STDERR);
		free(mlx->mlx_ptr);
	}
}
