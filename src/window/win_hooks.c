/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 01:59:53 by jonathro          #+#    #+#             */
/*   Updated: 2025/02/03 00:57:21 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <X11/keysym.h>

int	destroy_handler(t_mlx *mlx)
{
	if (!mlx || !mlx->mlx_ptr)
	{
		ft_putstr_fd("Error: Invalid mlx pointer in destroy_handler.\n",
			FDF_STDERR);
		return (1);
	}
	mlx_loop_end(mlx->mlx_ptr);
	return (0);
}

int	key_handler(int keycode, t_mlx *mlx)
{
	if (!mlx)
	{
		ft_putstr_fd("Error: Invalid mlx pointer in key_handler.\n",
			FDF_STDERR);
		return (1);
	}
	if (keycode == XK_Escape)
	{
		destroy_handler(mlx);
	}
	else
	{
		ft_putstr_fd("Info: Unhandled key pressed.\n", FDF_STDERR);
	}
	return (0);
}
