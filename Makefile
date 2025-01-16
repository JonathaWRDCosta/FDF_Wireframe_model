# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonatha <jonatha@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/16 17:14:26 by jonatha           #+#    #+#              #
#    Updated: 2025/01/16 19:09:57 by jonatha          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and flags
CC      = cc
CFLAGS = -Wall -Wextra -Werror -Iincludes -Ilibraries/libft/include -Ilibraries/minilibx_macos -I/opt/X11/include

# Directories
SRCDIR  = src
OBJDIR  = obj
LIBFTDIR = libraries/libft
MLXDIR  = libraries/minilibx_macos

# Libraries
LIBFT   = $(LIBFTDIR)/lib/libft.a
MLX     = $(MLXDIR)/libmlx.a
LIBS    = $(LIBFT) $(MLX) -framework OpenGL -framework AppKit

# Files
NAME    = fdf
SRC     = $(wildcard $(SRCDIR)/**/*.c $(SRCDIR)/*.c)
OBJ     = $(patsubst $(SRCDIR)/%.c, $(OBJDIR)/%.o, $(SRC))

# Rules
all: $(NAME)

# Build the executable
$(NAME): $(OBJ) $(LIBFT)
	@$(MAKE) -C $(MLXDIR)
	$(CC) $(CFLAGS) $(OBJ) $(LIBS) -o $@
	@echo "✅ $(NAME) compiled successfully!"

# Compile object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Build Libft
$(LIBFT):
	@$(MAKE) -C $(LIBFTDIR)

# Clean object files
clean:
	@rm -rf $(OBJDIR)
	@$(MAKE) -C $(LIBFTDIR) clean
	@$(MAKE) -C $(MLXDIR) clean
	@echo "🧹 Cleaned object files."

# Clean everything
fclean: clean
	@rm -f $(NAME)
	@$(MAKE) -C $(LIBFTDIR) fclean
	@echo "🧹 Cleaned everything."

# Rebuild everything
re: fclean all

.PHONY: all clean fclean re
