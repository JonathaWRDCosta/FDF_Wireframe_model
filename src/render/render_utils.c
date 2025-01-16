/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:45:15 by jonatha           #+#    #+#             */
/*   Updated: 2025/01/16 18:45:17 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

// Extracts the Z (height) value from an encoded point
unsigned long	get_z(unsigned long point)
{
	return (point >> 32);
}

// Extracts the color value from an encoded point
unsigned long	get_color(unsigned long point)
{
	return (point & COLOR_MASK);
}

// Sets initial camera properties based on map dimensions
void	set_camera_props(t_vars *vars)
{
	double	width_distance;
	double	height_distance;

	// Calculate proportional distances for rows and columns
	width_distance = (double)(PADDED_WIDTH) / vars->row_size;
	height_distance = (double)(PADDED_HEIGHT) / vars->col_size;

	// Choose the smaller distance to maintain aspect ratio
	vars->distance = (width_distance > height_distance)
		? height_distance
		: width_distance;

	// Initialize other camera properties
	vars->height = 5;       // Elevation scaling factor
	vars->zoom = 0.7;       // Zoom level
	vars->x_y_coef = -0.4;  // Rotation around X-Y plane
	vars->y_z_coef = -0.9;  // Rotation around Y-Z plane
	vars->z_x_coef = 0;     // Rotation around Z-X plane
	vars->map_x = 0;        // Horizontal offset
	vars->map_y = 0;        // Vertical offset
}

// Initializes a point with X, Y, Z coordinates
void	set_point(t_point *point, int x, int y, int z)
{
	point->x = x;
	point->y = y;
	point->z = z;
}

// Applies transformations to a point for rendering
void	render_point(t_vars *vars, t_point *point)
{
	// Scale and center the point based on the map's anchor and distance
	point->x = (point->x - vars->anchor_x) * vars->distance;
	point->y = (point->y - vars->anchor_y) * vars->distance;
	point->z = point->z * vars->height;

	// Apply rotations
	rotate_x_y(vars, point);
	rotate_y_z(vars, point);
	rotate_z_x(vars, point);

	// Apply translation and zoom
	translate(vars, point);
	zoom(vars, point);
}
