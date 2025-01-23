/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 01:42:16 by jonathro          #+#    #+#             */
/*   Updated: 2025/01/23 01:59:23 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

unsigned long get_z(unsigned long point)
{
    return (point >> 32);
}

unsigned long get_color(unsigned long point)
{
    return (point & COLOR_MASK);
}

void set_camera_props(t_camera *camera, t_map *map)
{
    double width_distance;
    double height_distance;

    if (!camera || !map || map->row_size == 0 || map->col_size == 0)
    {
        ft_putstr_fd("Error: Invalid camera or map properties.\n", FDF_STDERR);
        return;
    }

    width_distance = (double)(PADDED_WIDTH) / map->row_size;
    height_distance = (double)(PADDED_HEIGHT) / map->col_size;

    if (width_distance > height_distance)
    {
        camera->distance = height_distance;
    }
    else
    {
        camera->distance = width_distance;
    }
    camera->height = 5.0;
    camera->zoom = 0.7;
    camera->x_y_coef = -0.4;
    camera->y_z_coef = -0.9;
    camera->z_x_coef = 0.0;
}

void set_point(t_point *point, int x, int y, int z)
{
    point->x = x;
    point->y = y;
    point->z = z;
}

void render_point(t_vars *vars, t_point *point)
{
    t_camera *camera;

    if (!vars || !point)
    {
        ft_putstr_fd("Error: Invalid vars or point in render_point.\n", FDF_STDERR);
        return;
    }

    camera = &(vars->camera);

    point->x = (point->x - vars->anchor_x) * camera->distance;
    point->y = (point->y - vars->anchor_y) * camera->distance;
    point->z = point->z * camera->height;

    rotate_x_y(camera, point);
    rotate_y_z(camera, point);
    rotate_z_x(camera, point);

    zoom(camera, point);
    translate(vars, point);
}
