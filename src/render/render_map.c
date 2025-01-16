/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 18:41:44 by jonatha           #+#    #+#             */
/*   Updated: 2025/01/16 18:41:46 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <limits.h>

// Draws a pixel on the screen at (x, y) with the specified color
static void	put_pixel(t_vars *vars, int x, int y, unsigned long color)
{
	int	i;

	if ((WIN_WIDTH / 2) + x >= 0
		&& (WIN_WIDTH / 2) + x < WIN_WIDTH
		&& (WIN_HEIGHT / 2) + y >= 0
		&& (WIN_HEIGHT / 2) + y < WIN_HEIGHT)
	{
		i = (((WIN_WIDTH / 2) + x) * (vars->mlx->bits_per_pixel / 8))
			+ (((WIN_HEIGHT / 2) + y) * vars->mlx->size_line);
		vars->mlx->data_addr[i] = color;
		vars->mlx->data_addr[i + 1] = color >> 8;
		vars->mlx->data_addr[i + 2] = color >> 16;
	}
}

// Draws a line between two points using linear interpolation
static void	draw_line(t_vars *vars, t_point p1, t_point p2, unsigned long color)
{
	double	current_x;
	double	current_y;
	int		steps;
	int		i;

	current_x = p1.x;
	current_y = p1.y;
	steps = abs(p2.y - p1.y);
	if (abs(p2.x - p1.x) > steps)
		steps = abs(p2.x - p1.x);

	for (i = 0; i <= steps; i++)
	{
		put_pixel(vars, (int)current_x, (int)current_y, color);
		current_x += (p2.x - p1.x) / (double)steps;
		current_y += (p2.y - p1.y) / (double)steps;
	}
}

// Sets and draws lines connecting the current point to its left and top neighbors
static void	set_lines(t_vars *vars, int x, int y, unsigned long point)
{
	t_point	left_point;
	t_point	top_point;
	t_point	curr_point;

	set_point(&curr_point, x, y, get_z(point));
	render_point(vars, &curr_point);

	if (x > 0)
	{
		set_point(&left_point, x - 1, y, get_z(vars->map[y][x - 1]));
		render_point(vars, &left_point);
		draw_line(vars, curr_point, left_point, get_color(vars->map[y][x - 1]));
	}

	if (y > 0)
	{
		set_point(&top_point, x, y - 1, get_z(vars->map[y - 1][x]));
		render_point(vars, &top_point);
		draw_line(vars, curr_point, top_point, get_color(vars->map[y - 1][x]));
	}
}

// Renders the entire map to the screen
void	render_map(t_vars *vars)
{
	int	i;
	int	j;

	if (!vars || !vars->map)
	{
		ft_putstr_fd("Error: Invalid map or variables.\n", STDERR_FILENO);
		return;
	}

	for (i = 0; vars->map[i]; i++)
	{
		for (j = 0; vars->map[i][j] != ULONG_MAX; j++)
		{
			set_lines(vars, j, i, vars->map[i][j]);
		}
	}

	mlx_put_image_to_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr,
		vars->mlx->img_ptr, 0, 0);
}
