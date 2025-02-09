NAME        = fdf
BONUS_NAME  = fdf_bonus

CC          = cc
CFLAGS      = -Wall -Wextra -Werror
RM          = rm -rf

# Diretórios
SRC_DIR     = src
OBJ_DIR     = obj
LIBS_DIR    = libraries
INC_DIR     = includes

# Bibliotecas
LIBFT_DIR   = $(LIBS_DIR)/libft
LIBFT       = $(LIBFT_DIR)/lib/libft.a
MLX_DIR     = $(LIBS_DIR)/minilibx-linux
MLX_LIB     = $(MLX_DIR)/libmlx.a

# MiniLibX Download
MLX_URL     = https://cdn.intra.42.fr/document/document/27219/minilibx-linux.tgz
MLX_TGZ     = $(LIBS_DIR)/minilibx-linux.tgz

# Includes
INC         = -I$(INC_DIR) -I$(LIBFT_DIR)/include -I$(MLX_DIR)

# Flags das Bibliotecas
LIBS        = -L$(LIBFT_DIR)/lib -lft -L$(MLX_DIR) -lmlx -lXext -lX11 -lm

# Arquivos fonte
SRCS        = $(SRC_DIR)/fdf.c \
              $(SRC_DIR)/utils.c \
              $(SRC_DIR)/map/init_map.c \
              $(SRC_DIR)/map/parse_map.c \
              $(SRC_DIR)/map/parse_map_utils.c \
              $(SRC_DIR)/map/read_map.c \
              $(SRC_DIR)/render/init_renderer.c \
              $(SRC_DIR)/render/render_map.c \
              $(SRC_DIR)/render/render_utils.c \
              $(SRC_DIR)/render/transformations.c \
              $(SRC_DIR)/window/init_win.c \
              $(SRC_DIR)/window/win_hooks.c \
              $(SRC_DIR)/window/win_utils.c

BONUS_SRCS  = $(SRC_DIR)/fdf_bonus.c \
              $(SRC_DIR)/utils_bonus.c \
              $(SRC_DIR)/map/init_map_bonus.c \
              $(SRC_DIR)/map/parse_map_bonus.c \
              $(SRC_DIR)/map/parse_map_utils_bonus.c \
              $(SRC_DIR)/map/read_map_bonus.c \
              $(SRC_DIR)/render/init_renderer_bonus.c \
              $(SRC_DIR)/render/render_map_bonus.c \
              $(SRC_DIR)/render/render_utils_bonus.c \
              $(SRC_DIR)/render/transformations_bonus.c \
              $(SRC_DIR)/render/rotations_bonus.c \
              $(SRC_DIR)/window/init_win_bonus.c \
              $(SRC_DIR)/window/init_win_utils_bonus.c \
              $(SRC_DIR)/window/win_hooks_bonus.c \
              $(SRC_DIR)/window/win_hooks_helpers_bonus.c \
              $(SRC_DIR)/window/win_utils_bonus.c

# Transformando os caminhos dos fontes para os objetos dentro de OBJ_DIR
OBJS       = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(SRCS:.c=.o))
BONUS_OBJS = $(patsubst $(SRC_DIR)/%, $(OBJ_DIR)/%, $(BONUS_SRCS:.c=.o))

# Regras principais
all: $(LIBFT) $(MLX_LIB) $(NAME)

bonus: $(LIBFT) $(MLX_LIB) $(BONUS_NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBS) -o $(NAME)

$(BONUS_NAME): $(BONUS_OBJS)
	$(CC) $(CFLAGS) $(BONUS_OBJS) $(LIBS) -o $(BONUS_NAME)

# Compilação dos arquivos .c em .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) $(INC) -c $< -o $@

# Compilação do Libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Compilação do MiniLibX (evita recompilar toda vez)
$(MLX_LIB): $(MLX_DIR)
	@if [ ! -f "$(MLX_LIB)" ]; then \
		echo "Compilando MiniLibX..."; \
		make -C $(MLX_DIR); \
	fi

# Download do MiniLibX (somente se não existir)
$(MLX_DIR):
	@if [ ! -d "$(MLX_DIR)" ]; then \
		echo "Baixando MiniLibX..."; \
		mkdir -p $(LIBS_DIR); \
		wget -O $(MLX_TGZ) $(MLX_URL); \
		tar -xzf $(MLX_TGZ) -C $(LIBS_DIR); \
		rm $(MLX_TGZ); \
	fi

# Limpeza
clean:
	$(RM) $(OBJS) $(BONUS_OBJS)
	make -C $(LIBFT_DIR) clean
	@if [ -d "$(MLX_DIR)" ]; then make -C $(MLX_DIR) clean; fi

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME)
	make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all bonus clean fclean re mlx