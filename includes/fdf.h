/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 01:55:44 by jonathro          #+#    #+#             */
/*   Updated: 2025/02/09 12:54:54 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

// Tamanho da Janela
# define WIN_WIDTH 1980
# define WIN_HEIGHT 1080
# define WIN_TITLE "FdF by jonathro"

// Tamanhos de Padding para Ajustes
# define PADDED_WIDTH 1800
# define PADDED_HEIGHT 900
# define BUFFER_SIZE 99999

// Definições de Cores
# define COLOR_MASK 4294967295U
# define LINE_COLOR 0x00D4D4D8
# define BG_COLOR 0x0009090B

// Constantes para Saída
# define FDF_EXIT_ERROR 1
# define FDF_EXIT_SUCCESS 0
# define FDF_STDERR 2

// Struct para Gerenciamento do MiniLibX
typedef struct s_mlx
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*data_addr;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
}					t_mlx;

// Struct para Propriedades do Mapa
typedef struct s_map
{
	unsigned long	**data;
	int				col_size;
	int				row_size;
}					t_map;

// Struct para Propriedades da Câmera
typedef struct s_camera
{
	double			distance;
	double			height;
	double			zoom;
	double			x_y_coef;
	double			y_z_coef;
	double			z_x_coef;
}					t_camera;

// Struct para Representação de um Ponto
typedef struct s_point
{
	int				x;
	int				y;
	int				z;
}					t_point;

// Struct Principal do Programa
typedef struct s_vars
{
	t_mlx			*mlx;
	t_map			map;
	t_camera		camera;
	int				anchor_x;
	int				anchor_y;
	int				offset_x;
	int				offset_y;
}					t_vars;

// Prototipação das Funções
int					init_map(t_vars *vars, char *filename);
char				*get_raw_map(char *filename);
unsigned long		**split_raw_map(char *raw_map);

void				init_renderer(t_vars *vars);
void				render_map(t_vars *vars);
void				set_camera_props(t_camera *camera, t_map *map);
void				set_point(t_point *point, int x, int y, int z);
void				render_point(t_vars *vars, t_point *point);
void				zoom(t_camera *camera, t_point *point);
void				translate(t_vars *vars, t_point *point);
void				rotate_x_y(t_camera *camera, t_point *point);
void				rotate_y_z(t_camera *camera, t_point *point);
void				rotate_z_x(t_camera *camera, t_point *point);

void				draw_background(t_vars *vars);
int					init_win(t_vars *vars);
void				destroy_win(t_mlx *mlx);
int					destroy_handler(t_mlx *mlx);
int					key_handler(int keycode, t_mlx *mlx);

void				free_str_arr(char **arr);
void				free_ulong_arr(unsigned long **arr);
unsigned long		get_z(unsigned long point);
unsigned long		get_color(unsigned long point);
unsigned int		atoi_hex(char *str);
int					abs(int n);
unsigned long		*get_map_row(char *map_row);
unsigned long		**build_map_from_lines(char **lines);

#endif
