/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonatha <jonatha@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:16:04 by jonatha           #+#    #+#             */
/*   Updated: 2025/01/16 19:14:38 by jonatha          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "libft.h"
# include <stddef.h>
# include <math.h>

// Configurações da Janela
# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define WIN_TITLE "FDF Jonatha Costa"

# define PADDED_WIDTH 1800
# define PADDED_HEIGHT 900

// Configurações de Cores e Buffer
# define BUFFER_SIZE 4096
# define COLOR_MASK 0xFFFFFFFF
# define LINE_COLOR 0x00D4D4D8
# define BG_COLOR 0x0009090B

// Estrutura do MiniLibX
typedef struct s_mlx
{
	void	*mlx_ptr;        // Contexto do MiniLibX
	void	*win_ptr;        // Ponteiro para a janela
	void	*img_ptr;        // Ponteiro para a imagem
	char	*data_addr;      // Dados da imagem
	int		bits_per_pixel;  // Bits por pixel
	int		size_line;       // Tamanho de uma linha na imagem
	int		endian;          // Endianness da imagem
}				t_mlx;

// Estruturas do Programa
typedef struct s_vars
{
	t_mlx           *mlx;       // Estrutura do MiniLibX
	unsigned long   **map;      // Mapa 2D do terreno
	int             col_size;   // Número de colunas no mapa
	int             row_size;   // Número de linhas no mapa

	int             anchor_x;   // Posição do âncora no eixo X
	int             anchor_y;   // Posição do âncora no eixo Y
	int             map_x;      // Deslocamento horizontal do mapa
	int             map_y;      // Deslocamento vertical do mapa

	double          distance;   // Distância entre pontos
	double          height;     // Escala de altura
	double          zoom;       // Fator de zoom
	double          x_y_coef;   // Rotação no plano X-Y
	double          y_z_coef;   // Rotação no plano Y-Z
	double          z_x_coef;   // Rotação no plano Z-X
}   t_vars;

typedef struct s_point
{
	int x;
	int y;
	int z;
	unsigned int color; // Cor associada ao ponto
}   t_point;

// Funções principais
int             init_map(t_vars *vars, char *filename);
char            *get_raw_map(char *filename);
unsigned long   **split_raw_map(char *raw_map);
void            init_renderer(t_vars *vars);
void            render_map(t_vars *vars);

// Funções utilitárias
void            free_str_arr(char **arr);
void            free_ulong_arr(unsigned long **arr);
unsigned int atoi_hex(char *str);
void set_camera_props(t_vars *vars);
void draw_background(t_vars *vars);
void set_point(t_point *point, int x, int y, int z);
unsigned long get_z(unsigned long point);
void render_point(t_vars *vars, t_point *point);
unsigned long get_color(unsigned long point);
void destroy_win(t_mlx *mlx);
int destroy_handler(t_mlx *mlx);
int key_handler(int keycode, t_mlx *mlx);
int mlx_loop_end(void *mlx_ptr);

// Transformações
void            zoom(t_vars *vars, t_point *point);
void            translate(t_vars *vars, t_point *point);
void            rotate_x_y(t_vars *vars, t_point *point);
void            rotate_y_z(t_vars *vars, t_point *point);
void            rotate_z_x(t_vars *vars, t_point *point);

#endif
