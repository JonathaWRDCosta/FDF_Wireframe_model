/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_renderer.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:46:36 by jonatha           #+#    #+#             */
/*   Updated: 2025/01/16 18:46:38 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Initializes the rendering process
void	init_renderer(t_vars *vars)
{
	if (!vars || !vars->mlx)
	{
		ft_putstr_fd("Error: Invalid renderer variables.\n", STDERR_FILENO);
		return;
	}

	// Set initial camera properties
	set_camera_props(vars);

	// Draw the background
	draw_background(vars);

	// Render the map
	render_map(vars);

	ft_putstr_fd("Renderer initialized successfully.\n", STDOUT_FILENO);
}
