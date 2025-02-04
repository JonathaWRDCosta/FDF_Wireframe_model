NAME		= fdf
BONUS_NAME	= fdf_bonus

CC			= cc
CFLAGS		= -Wall -Wextra -Werror -g -fsanitize=address
RM			= rm -f

# Directories
SRC_DIR		= src
BUILD_DIR	= build
LIBS_DIR	= libraries
INC_DIR		= includes

# Libraries
LIBFT_DIR	= $(LIBS_DIR)/libft
LIBFT		= $(LIBFT_DIR)/lib/libft.a
MLX_DIR		= $(LIBS_DIR)/minilibx-linux
MLX			= $(MLX_DIR)/libmlx.a

# MiniLibX Download
MLX_URL		= https://cdn.intra.42.fr/document/document/27219/minilibx-linux.tgz
MLX_TGZ		= $(LIBS_DIR)/minilibx-linux.tgz

# Include paths
INC			= -I$(INC_DIR) -I$(LIBFT_DIR)/include -I$(MLX_DIR)

# Library flags
LIBS		= -L$(LIBFT_DIR)/lib -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Source files
SRCS		= src/fdf.c \
			  src/utils.c \
			  src/map/init_map.c \
			  src/map/parse_map.c \
			  src/map/parse_map_utils.c \
			  src/map/read_map.c \
			  src/render/init_renderer.c \
			  src/render/render_map.c \
			  src/render/render_utils.c \
			  src/render/transformations.c \
			  src/window/init_win.c \
			  src/window/win_hooks.c \
			  src/window/win_utils.c

BONUS_SRCS	= src/fdf_bonus.c \
			  src/utils_bonus.c \
			  src/map/init_map_bonus.c \
			  src/map/parse_map_bonus.c \
			  src/map/parse_map_utils_bonus.c \
			  src/map/read_map_bonus.c \
			  src/render/init_renderer_bonus.c \
			  src/render/render_map_bonus.c \
			  src/render/render_utils_bonus.c \
			  src/render/transformations_bonus.c \
			  src/render/rotations_bonus.c \
			  src/window/init_win_bonus.c \
			  src/window/init_win_utils_bonus.c \
			  src/window/win_hooks_bonus.c \
			  src/window/win_hooks_helpers_bonus.c \
			  src/window/win_utils_bonus.c

# Object files
OBJS		= $(SRCS:%.c=%.o)
BONUS_OBJS	= $(BONUS_SRCS:%.c=%.o)

all: $(MLX) $(NAME)

bonus: $(MLX) $(BONUS_NAME)

# Main compilation
$(NAME): $(LIBFT) $(MLX) $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(BONUS_NAME): $(LIBFT) $(MLX) $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBS) -o $(BONUS_NAME)

# Compile source files
%.o: %.c
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# MiniLibX Download and Compilation
$(MLX):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "Downloading MiniLibX..."; \
		mkdir -p $(LIBS_DIR); \
		wget -O $(MLX_TGZ) $(MLX_URL); \
		tar -xzf $(MLX_TGZ) -C $(LIBS_DIR); \
		rm $(MLX_TGZ); \
	fi
	make -C $(MLX_DIR)

# Compile libraries
$(LIBFT):
	make -C $(LIBFT_DIR)

clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	make -C $(LIBFT_DIR) clean
	@if [ -d "$(MLX_DIR)" ]; then make -C $(MLX_DIR) clean; fi

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_DIR) fclean
	rm -rf $(MLX_DIR)

re: fclean all

.PHONY: all bonus clean fclean re mlx
