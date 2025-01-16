/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:47:37 by jonatha           #+#    #+#             */
/*   Updated: 2025/01/16 18:47:55 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <X11/Xlib.h>
#include <stdlib.h>
#include <stdio.h>

// Sets image properties for rendering
static int	set_img_props(t_mlx *mlx)
{
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->img_ptr)
	{
		ft_putstr_fd("Error: Failed to create image.\n", STDERR_FILENO);
		destroy_win(mlx);
		return (-1);
	}

	mlx->data_addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel,
			&mlx->size_line, &mlx->endian);
	if (!mlx->data_addr)
	{
		ft_putstr_fd("Error: Failed to get image data address.\n", STDERR_FILENO);
		destroy_win(mlx);
		return (-1);
	}
	return (0);
}

// Sets window properties for the main application
static int	set_win_props(t_mlx *mlx)
{
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
	{
		ft_putstr_fd("Error: Failed to initialize MiniLibX.\n", STDERR_FILENO);
		destroy_win(mlx);
		return (-1);
	}

	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT, WIN_TITLE);
	if (!mlx->win_ptr)
	{
		ft_putstr_fd("Error: Failed to create window.\n", STDERR_FILENO);
		destroy_win(mlx);
		return (-1);
	}
	return (0);
}

// Initializes the window and rendering context
int	init_win(t_vars *vars)
{
	t_mlx	mlx;

	// Validate input
	if (!vars)
	{
		ft_putstr_fd("Error: Invalid variables passed to init_win.\n", STDERR_FILENO);
		return (-1);
	}

	// Initialize variables
	vars->mlx = &mlx;
	mlx.mlx_ptr = NULL;
	mlx.win_ptr = NULL;
	mlx.img_ptr = NULL;

	// Set window and image properties
	if (set_win_props(vars->mlx) == -1)
		return (-1);
	if (set_img_props(vars->mlx) == -1)
		return (-1);

	// Set event hooks
	mlx_hook(mlx.win_ptr, DestroyNotify, 0, destroy_handler, &mlx);
	mlx_key_hook(mlx.win_ptr, key_handler, &mlx);

	// Initialize the renderer and start the event loop
	init_renderer(vars);
	mlx_loop(mlx.mlx_ptr);

	// Clean up resources
	destroy_win(&mlx);
	return (0);
}
