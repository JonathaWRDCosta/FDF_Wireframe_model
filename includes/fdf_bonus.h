/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/28 01:29:54 by jonathro          #+#    #+#             */
/*   Updated: 2025/01/28 06:11:22 by jonathro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "libft.h"
#include "mlx.h"
# include <stddef.h>
# include <unistd.h>
# include <stdlib.h>
# include <math.h>
# include <limits.h>
# include <X11/keysym.h>
# include <X11/X.h>
#include <fcntl.h>

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define WIN_TITLE "FdF by jonatha"
#define ANIMATION_STEP 0.01
#define ANIMATION_DELAY 10000
# define SCALE 20  // Ajuste conforme necessário

# define PADDED_WIDTH 1800
# define PADDED_HEIGHT 900

# define BUFFER_SIZE 99999

# define COLOR_MASK 4294967295U
# define LINE_COLOR 0xFFFFFF
# define BG_COLOR 0x000000

# define FDF_EXIT_ERROR 1
# define FDF_EXIT_SUCCESS 0
# define FDF_STDERR 2

# define BANNER_FILEPATH "./assets/banner.xpm"

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	void	*banner_img_ptr;
	char	*data_addr;
	int	bits_per_pixel;
	int	size_line;
	int	endian;
} t_mlx;

typedef struct s_vars
{
	t_mlx			*mlx;

	unsigned long	**map;
	int				col_size;
	int				row_size;

	int				anchor_x;
	int				anchor_y;
	int				map_x;
	int				map_y;

	double			distance;
	double			height;
	double			zoom;
	double			x_y_coef;
	double			y_z_coef;
	double			z_x_coef;

	int				is_animating;
} t_vars;

typedef struct s_point
{
	int	x;
	int	y;
	int	z;
} t_point;

int				init_map(t_vars *vars, char *filename);
char			*get_raw_map(char *filename);
unsigned long	**split_raw_map(char *raw_map);
void			init_renderer(t_vars *vars);
void			render_map(t_vars *vars);
void			set_camera_props(t_vars *vars);
void			set_point(t_point *point, int x, int y, int z);
void			render_point(t_vars *vars, t_point *point);
void			zoom(t_vars *vars, t_point *point);
void			translate(t_vars *vars, t_point *point);
void			rotate_z_x(t_vars *vars, t_point *point);
void			rotate_y_z(t_vars *vars, t_point *point);
void			rotate_x_y(t_vars *vars, t_point *point);

void			draw_background(t_vars *vars);
int				init_win(t_vars *vars);
void			destroy_win(t_mlx *mlx);
int				destroy_handler(t_mlx *mlx);
int				keypress_handler(int keycode, t_vars *vars);
int				animation_loop(t_vars *vars);

void			free_str_arr(char **arr);
void			free_ulong_arr(unsigned long **arr);
unsigned long	get_z(unsigned long point);
unsigned long	get_color(unsigned long point);
unsigned int	atoi_hex(char *str);
int				ft_abs(int n);

#endif