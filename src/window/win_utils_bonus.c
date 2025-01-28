/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_utils_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 03:28:13 by jonathro          #+#    #+#             */
/*   Updated: 2025/01/28 03:28:14 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

void	draw_background(t_vars *vars)
{
	int	*background;
	int	pixels;
	int	i;

	if (!vars || !vars->mlx || !vars->mlx->data_addr)
		return; // Prevenção de segfaults

	background = (int *)(vars->mlx->data_addr);
	pixels = WIN_HEIGHT * WIN_WIDTH; // Total de pixels na tela
	i = 0;
	while (i < pixels)
	{
		background[i] = BG_COLOR; // Define a cor de fundo
		i++;
	}
}


void	destroy_win(t_mlx *mlx)
{
	if (!mlx)
		return; // Verifica se mlx é nulo para evitar segfaults

	// Libera a imagem do banner, se existir
	if (mlx->banner_img_ptr)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->banner_img_ptr);
		mlx->banner_img_ptr = NULL;
	}

	// Libera a imagem principal, se existir
	if (mlx->img_ptr)
	{
		mlx_destroy_image(mlx->mlx_ptr, mlx->img_ptr);
		mlx->img_ptr = NULL;
	}

	// Fecha a janela, se existir
	if (mlx->win_ptr)
	{
		mlx_destroy_window(mlx->mlx_ptr, mlx->win_ptr);
		mlx->win_ptr = NULL;
	}

	// Destroi o display, se inicializado
	if (mlx->mlx_ptr)
	{
		mlx_destroy_display(mlx->mlx_ptr);
		free(mlx->mlx_ptr); // Libera o ponteiro principal
		mlx->mlx_ptr = NULL;
	}
}

