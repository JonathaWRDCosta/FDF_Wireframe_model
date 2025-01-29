/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 01:59:39 by jonathro          #+#    #+#             */
/*   Updated: 2025/01/29 00:57:36 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <X11/Xlib.h>
#include <stdlib.h>

static int	handle_error(t_mlx *mlx)
{
	destroy_win(mlx);
	return (-1);
}

static int	set_img_props(t_mlx *mlx)
{
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->img_ptr)
		return (handle_error(mlx));
	mlx->data_addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel,
			&mlx->size_line, &mlx->endian);
	if (!mlx->data_addr)
		return (handle_error(mlx));
	return (0);
}

static int	set_win_props(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
		return (handle_error(mlx));
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			WIN_TITLE);
	if (!mlx->win_ptr)
		return (handle_error(mlx));
	return (0);
}

static void	set_hooks(t_mlx *mlx)
{
	mlx_hook(mlx->win_ptr, DestroyNotify, 0, destroy_handler, mlx);
	mlx_key_hook(mlx->win_ptr, key_handler, mlx);
}

int	init_win(t_vars *vars)
{
	t_mlx	mlx;

	mlx = {0};
	vars->mlx = &mlx;
	if (set_win_props(vars->mlx) == -1)
		return (-1);
	if (set_img_props(vars->mlx) == -1)
		return (-1);
	set_hooks(&mlx);
	init_renderer(vars);
	if (mlx_loop(mlx.mlx_ptr) == -1)
	{
		ft_putstr_fd("Error: mlx_loop failed.\n", FDF_STDERR);
		destroy_win(&mlx);
		return (-1);
	}
	destroy_win(&mlx);
	return (0);
}
