/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_hooks_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 03:28:28 by jonathro          #+#    #+#             */
/*   Updated: 2025/01/28 03:28:29 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf_bonus.h"

int	animation_loop(t_vars *vars)
{
	if (!vars || !vars->mlx || !vars->mlx->mlx_ptr || !vars->mlx->win_ptr)
		return (0); // Verifica se os ponteiros necessários são válidos

	if (vars->is_animating)
	{
		mlx_clear_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr);

		// Atualiza o coeficiente de rotação
		vars->z_x_coef += ANIMATION_STEP;

		// Redesenha a janela
		draw_background(vars);
		render_map(vars);

		// Coloca a imagem atualizada na janela
		mlx_put_image_to_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr,
			vars->mlx->banner_img_ptr, 0, 0);

		// Adiciona um pequeno atraso para controlar a taxa de atualização
		usleep(ANIMATION_DELAY);
	}
	return (1);
}

int	destroy_handler(t_mlx *mlx)
{
	if (!mlx || !mlx->mlx_ptr)
		return (1);
	mlx_loop_end(mlx->mlx_ptr);
	return (0);
}


static void	transformation_keys(int keycode, t_vars *vars)
{
	if (keycode == XK_e)
		vars->x_y_coef += 0.1;
	else if (keycode == XK_q)
		vars->x_y_coef -= 0.1;
	else if (keycode == XK_w)
		vars->y_z_coef += 0.1;
	else if (keycode == XK_s)
		vars->y_z_coef -= 0.1;
	else if (keycode == XK_a)
		vars->z_x_coef -= 0.1;
	else if (keycode == XK_d)
		vars->z_x_coef += 0.1;
	else if (keycode == XK_Right)
		vars->map_x += 5;
	else if (keycode == XK_Left)
		vars->map_x -= 5;
	else if (keycode == XK_Up)
		vars->map_y += 5;
	else if (keycode == XK_Down)
		vars->map_y -= 5;
}

static void	reset_camera_props(t_vars *vars)
{
	vars->x_y_coef = 0;
	vars->y_z_coef = 0;
	vars->z_x_coef = 0;
}

static void	projection_keys(int keycode, t_vars *vars)
{
	if (!vars)
		return; // Garante que vars não é nulo

	if (keycode == XK_n)
		vars->zoom += 0.1; // Aumenta o zoom
	else if (keycode == XK_m && vars->zoom > 0.2)
		vars->zoom -= 0.1; // Reduz o zoom
	else if (keycode == XK_j)
		vars->height -= 0.5; // Diminui a altura
	else if (keycode == XK_k)
		vars->height += 0.5; // Aumenta a altura
	else if (keycode == XK_r)
	{
		vars->is_animating = 0;
		set_camera_props(vars); // Reseta as propriedades da câmera
	}
	else if (keycode == XK_t)
	{
		vars->is_animating = 0;
		reset_camera_props(vars); // Reseta os coeficientes
	}
}

static void	handle_exit(int keycode, t_vars *vars)
{
	if (keycode == XK_Escape)
	{
		vars->is_animating = 0;
		destroy_handler(vars->mlx); // Use a versão com o prefixo 
	}
}

static void	toggle_animation(int keycode, t_vars *vars)
{
	if (keycode == XK_space)
		vars->is_animating = !vars->is_animating;
}

int	keypress_handler(int keycode, t_vars *vars)
{
	if (!vars || !vars->mlx)
		return (0); // Evita segfaults se vars ou mlx forem inválidos

	// Manipulação de teclas de transformação e projeção
	transformation_keys(keycode, vars); // Use a versão renomeada
	projection_keys(keycode, vars);    // Use a versão renomeada

	// Verifica teclas específicas (Escape e espaço)
	handle_exit(keycode, vars);
	toggle_animation(keycode, vars);

	// Atualiza o fundo, renderiza o mapa e exibe na janela
	draw_background(vars); // Use a versão renomeada
	render_map(vars);      // Use a versão renomeada
	mlx_put_image_to_window(vars->mlx->mlx_ptr, vars->mlx->win_ptr,
		vars->mlx->banner_img_ptr, 0, 0);

	return (0);
}
