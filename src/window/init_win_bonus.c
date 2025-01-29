/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_win_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 03:28:43 by jonathro          #+#    #+#             */
/*   Updated: 2025/01/29 00:57:32 by jonathro         ###   ########.fr       */
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
		return (-1); // Evita segfaults caso mlx seja inválido
	if (create_image(mlx) == -1)
	{
		destroy_win(mlx); // Função para liberar recursos
		return (-1);
	}
	if (load_banner_image(mlx) == -1)
	{
		destroy_win(mlx); // Função para liberar recursos
		return (-1);
	}
	return (0);
}

static int	set_win_props(t_mlx *mlx)
{
	if (!mlx)
		return (-1); // Evita segfaults caso mlx seja inválido
	// Inicializa o MiniLibX
	mlx->mlx_ptr = mlx_init();
	if (!mlx->mlx_ptr)
	{
		destroy_win(mlx); // Usa a função com o prefixo
		return (-1);
	}
	// Cria a nova janela
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIN_WIDTH, WIN_HEIGHT,
			WIN_TITLE);
	if (!mlx->win_ptr)
	{
		destroy_win(mlx); // Libera recursos em caso de falha
		return (-1);
	}
	return (0); // Retorna sucesso
}

int	init_win(t_vars *vars)
{
	if (!vars)
		return (-1); // Verifica se vars é nulo para evitar segfaults
	vars->mlx = (t_mlx *)malloc(sizeof(t_mlx));
	if (!vars->mlx)
		return (-1); // Retorna erro se a alocação falhar
	// Inicializa os membros de mlx
	vars->mlx->mlx_ptr = NULL;
	vars->mlx->win_ptr = NULL;
	vars->mlx->img_ptr = NULL;
	vars->mlx->banner_img_ptr = NULL;
	// Configura a janela
	if (set_win_props(vars->mlx) == -1)
	{
		destroy_win(vars->mlx); // Libera recursos em caso de falha
		free(vars->mlx);
		return (-1);
	}
	// Configura as imagens
	if (set_img_props(vars->mlx) == -1)
	{
		destroy_win(vars->mlx); // Libera recursos em caso de falha
		free(vars->mlx);
		return (-1);
	}
	// Configura os hooks
	mlx_hook(vars->mlx->win_ptr, DestroyNotify, 0, destroy_handler, vars->mlx);
	mlx_hook(vars->mlx->win_ptr, KeyPress, KeyPressMask, keypress_handler,
		vars);
	// Inicializa o renderizador e o loop
	init_renderer(vars);
	mlx_loop_hook(vars->mlx->mlx_ptr, animation_loop, vars);
	mlx_loop(vars->mlx->mlx_ptr);
	// Libera os recursos ao sair do loop
	destroy_win(vars->mlx);
	free(vars->mlx);
	return (0);
}
