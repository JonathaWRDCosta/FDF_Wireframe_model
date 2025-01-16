/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:49:26 by jonatha           #+#    #+#             */
/*   Updated: 2025/01/16 18:49:37 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <X11/keysym.h>
#include <stdlib.h>
#include <unistd.h>

// Handles the window close event
int	destroy_handler(t_mlx *mlx)
{
	if (!mlx || !mlx->mlx_ptr)
		return (0);

	// Free resources and end the loop
	if (mlx->img_ptr)
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
	if (mlx->win_ptr)
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
	mlx_loop_end(mlx->mlx_ptr);

	ft_putstr_fd("Window closed successfully.\n", STDOUT_FILENO);
	return (0);
}

// Handles key press events
int	key_handler(int keycode, t_mlx *mlx)
{
	if (!mlx)
		return (0);

	// Close the window on Escape key
	if (keycode == XK_Escape)
	{
		ft_putstr_fd("Escape key pressed. Closing window...\n", STDOUT_FILENO);
		destroy_handler(mlx);
	}

	// Example: Add more controls here
	// if (keycode == XK_Up)
	//     // Handle up arrow key
	// if (keycode == XK_Left)
	//     // Handle left arrow key

	return (0);
}
