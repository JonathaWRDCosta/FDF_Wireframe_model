/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_hooks.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 01:59:53 by jonathro          #+#    #+#             */
/*   Updated: 2025/01/23 01:59:54 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"
#include <X11/keysym.h>

int destroy_handler(t_mlx *mlx)
{
    if (!mlx || !mlx->mlx_ptr)
    {
        ft_putstr_fd("Error: Invalid mlx pointer in destroy_handler.\n", FDF_STDERR);
        return (1);
    }

    mlx_loop_end(mlx->mlx_ptr);
    return (0);
}

int key_handler(int keycode, t_mlx *mlx)
{
    if (!mlx)
    {
        ft_putstr_fd("Error: Invalid mlx pointer in key_handler.\n", FDF_STDERR);
        return (1);
    }

    switch (keycode)
    {
        case XK_Escape:
            destroy_handler(mlx);
            break;
        default:
            ft_putstr_fd("Info: Unhandled key pressed.\n", FDF_STDERR);
            break;
    }

    return (0);
}
