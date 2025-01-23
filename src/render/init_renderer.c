/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 01:58:24 by jonathro          #+#    #+#             */
/*   Updated: 2025/01/23 01:58:25 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void init_renderer(t_vars *vars)
{
    if (!vars)
    {
        ft_putstr_fd("Error: vars is NULL in init_renderer.\n", FDF_STDERR);
        return;
    }

    ft_putstr_fd("Initializing renderer...\n", FDF_STDERR);

    set_camera_props(&(vars->camera), &(vars->map));
    ft_putstr_fd("Camera properties set.\n", FDF_STDERR);

    draw_background(vars);
    ft_putstr_fd("Background drawn.\n", FDF_STDERR);

    render_map(vars);
    ft_putstr_fd("Map rendered.\n", FDF_STDERR);
}
