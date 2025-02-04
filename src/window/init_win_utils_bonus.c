/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win_utils_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 01:28:13 by jonathro          #+#    #+#             */
/*   Updated: 2025/02/03 01:28:23 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

static int	create_image(t_mlx *mlx)
{
	mlx->img_ptr = mlx_new_image(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	if (!mlx->img_ptr)
		return (-1);
	mlx->data_addr = mlx_get_data_addr(mlx->img_ptr, &mlx->bits_per_pixel,
			&mlx->size_line, &mlx->endian);
	if (!mlx->data_addr)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		mlx->img_ptr = NULL;
		return (-1);
	}
	return (0);
}

static int	load_banner_image(t_mlx *mlx)
{
	int	img_width;
	int	img_height;

	mlx->banner_img_ptr = mlx_xpm_file_to_image(mlx->mlx_ptr, BANNER_FILEPATH,
			&img_width, &img_height);
	if (!mlx->banner_img_ptr)
		return (-1);
	return (0);
}

static int	set_img_props(t_mlx *mlx)
{
	if (!mlx || !mlx->mlx_ptr)
		return (-1);
	if (create_image(mlx) == -1)
	{
		destroy_win(mlx);
		return (-1);
	}
	if (load_banner_image(mlx) == -1)
	{
		destroy_win(mlx);
		return (-1);
	}
	return (0);
}

static int	set_win_props(t_mlx *mlx)
{
	if (!mlx)
		return (-1);
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
	{
		destroy_win(mlx);
		return (-1);
	}
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			WIN_TITLE);
	if (!mlx->win_ptr)
	{
		destroy_win(mlx);
		return (-1);
	}
	return (0);
}

int	setup_win_bonus(t_mlx *mlx)
{
	if (set_win_props(mlx) == -1)
		return (-1);
	if (set_img_props(mlx) == -1)
		return (-1);
	return (0);
}
