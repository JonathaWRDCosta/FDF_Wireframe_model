/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 01:58:31 by jonathro          #+#    #+#             */
/*   Updated: 2025/01/29 00:56:12 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx.h"
#include <limits.h>

static void	put_pixel(t_vars *vars, int x, int y, unsigned long color)
{
	int	i;
	int	adjusted_x;
	int	adjusted_y;

	adjusted_x = (WIN_WIDTH / 2) + x;
	adjusted_y = (WIN_HEIGHT / 2) + y;
	if (adjusted_x >= 0 && adjusted_x < WIN_WIDTH && adjusted_y >= 0
		&& adjusted_y < WIN_HEIGHT)
	{
		i = (adjusted_x * vars->mlx->bits_per_pixel / 8) + (adjusted_y
				* vars->mlx->size_line);
		vars->mlx->data_addr[i] = color;
		vars->mlx->data_addr[++i] = color >> 8;
		vars->mlx->data_addr[++i] = color >> 16;
	}
	printf("Pixel -> X: %d, Y: %d, Cor: %#lx\n", x, y, color);
}

static void	draw_line(t_vars *vars, t_point p1, t_point p2, unsigned long color)
{
	double	x0;
	double	y0;
	int		steps;
	double	x_inc;
	double	y_inc;

	x0 = p1.x;
	y0 = p1.y;
	steps = abs(p2.y - p1.y);
	if (abs(p2.x - p1.x) > steps)
		steps = abs(p2.x - p1.x);
	if (steps == 0)
		return ;
	x_inc = (p2.x - p1.x) / (double)steps;
	y_inc = (p2.y - p1.y) / (double)steps;
	for (int i = 0; i <= steps; i++)
	{
		put_pixel(vars, (int)x0, (int)y0, color);
		x0 += x_inc;
		y0 += y_inc;
	}
}

static void	set_lines(t_vars *vars, int x, int y, unsigned long point)
{
	t_point curr_point, left_point, top_point;
	set_point(&curr_point, x, y, get_z(point));
	render_point(vars, &curr_point);
	if (x > 0 && vars->map.data[y][x - 1] != ULONG_MAX)
	{
		set_point(&left_point, x - 1, y, get_z(vars->map.data[y][x - 1]));
		render_point(vars, &left_point);
		draw_line(vars, curr_point, left_point, get_color(vars->map.data[y][x
				- 1]));
	}
	if (y > 0 && vars->map.data[y - 1][x] != ULONG_MAX)
	{
		set_point(&top_point, x, y - 1, get_z(vars->map.data[y - 1][x]));
		render_point(vars, &top_point);
		draw_line(vars, curr_point, top_point, get_color(vars->map.data[y
				- 1][x]));
	}
}

void	render_map(t_vars *vars)
{
	if (!vars->map.data)
	{
		ft_putstr_fd("Error: Map data is NULL in render_map.\n", FDF_STDERR);
		return ;
	}
	for (int i = 0; vars->map.data[i]; i++)
	{
		for (int j = 0; vars->map.data[i][j] != ULONG_MAX; j++)
		{
			set_lines(vars, j, i, vars->map.data[i][j]);
		}
	}
	mlx_put_image_to_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr,
		vars->mlx->img_ptr, 0, 0);
}
