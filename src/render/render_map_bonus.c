/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 03:29:24 by jonathro          #+#    #+#             */
/*   Updated: 2025/01/29 00:55:20 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static void	put_pixel(t_vars *vars, int x, int y, unsigned long color)
{
	int	i;
	int	center_x;
	int	center_y;

	if (!vars || !vars->mlx || !vars->mlx->data_addr)
		return ;
	center_x = WIN_WIDTH / 2;
	center_y = WIN_HEIGHT / 2;
	if ((center_x + x) >= 0 && (center_x + x) < WIN_WIDTH && (center_y + y) >= 0
		&& (center_y + y) < WIN_HEIGHT)
	{
		i = ((center_x + x) * (vars->mlx->bits_per_pixel / 8)) + ((center_y + y)
				* vars->mlx->size_line);
		if (i >= 0 && i + 2 < (WIN_WIDTH * WIN_HEIGHT
				* (vars->mlx->bits_per_pixel / 8)))
		{
			vars->mlx->data_addr[i] = (unsigned char)(color);
			vars->mlx->data_addr[i + 1] = (unsigned char)(color >> 8);
			vars->mlx->data_addr[i + 2] = (unsigned char)(color >> 16);
		}
	}
}

static void	draw_line(t_vars *vars, t_point p1, t_point p2, unsigned long color)
{
	double	x0;
	double	y0;
	double	dx;
	double	dy;
	int		steps;
	int		i;

	if (!vars)
		return ;
	dx = p2.x - p1.x;
	dy = p2.y - p1.y;
	if (ft_abs(dx) > ft_abs(dy))
		steps = ft_abs(dx);
	else
		steps = ft_abs(dy);
	x0 = p1.x;
	y0 = p1.y;
	i = 0;
	while (i <= steps)
	{
		put_pixel(vars, (int)x0, (int)y0, color);
		x0 += dx / (double)steps;
		y0 += dy / (double)steps;
		i++;
	}
}

static void	set_lines(t_vars *vars, int x, int y, unsigned long point)
{
	t_point			left_point;
	t_point			top_point;
	t_point			curr_point;
	unsigned long	left_color;
	unsigned long	top_color;

	if (!vars || !vars->map)
		return ;
	set_point(&curr_point, x, y, get_z(point));
	render_point(vars, &curr_point);
	if (x > 0)
	{
		set_point(&left_point, x - 1, y, get_z(vars->map[y][x - 1]));
		render_point(vars, &left_point);
		left_color = get_color(vars->map[y][x - 1]);
		draw_line(vars, curr_point, left_point, left_color);
	}
	if (y > 0)
	{
		set_point(&top_point, x, y - 1, get_z(vars->map[y - 1][x]));
		render_point(vars, &top_point);
		top_color = get_color(vars->map[y - 1][x]);
		draw_line(vars, curr_point, top_point, top_color);
	}
}

static void	render_cell(t_vars *vars, int i, int j)
{
	if (!vars || !vars->map || vars->map[i][j] == ULONG_MAX)
		return ;
	set_lines(vars, j, i, vars->map[i][j]);
}

void	render_map(t_vars *vars)
{
	int				i;
	int				j;
	unsigned long	**map;

	if (!vars || !vars->map || !vars->mlx)
		return ;
	map = vars->map;
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j] != ULONG_MAX)
		{
			render_cell(vars, i, j);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr,
		vars->mlx->img_ptr, 0, 0);
}
