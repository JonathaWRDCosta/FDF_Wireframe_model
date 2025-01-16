# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jonathro <jonathro@student.42porto.com>    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/11/20 11:07:06 by jonathro          #+#    #+#              #
#    Updated: 2024/11/21 13:12:21 by jonathro         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Compiler and Flags
CC = cc
CFLAGS = -Wall -Werror -Wextra

# Directories
SRCDIR = srcs
OBJDIR = objs
INCDIR = include
LIBDIR = lib

# Library
NAME = $(LIBDIR)/libft.a

# Source files (organized by subdirectories)
SRC = character/ft_isalnum.c character/ft_isalpha.c character/ft_isascii.c \
      character/ft_isdigit.c character/ft_isprint.c \
      conversion/ft_atoi.c conversion/ft_itoa.c conversion/ft_tolower.c \
      conversion/ft_toupper.c \
      file/ft_putchar_fd.c file/ft_putendl_fd.c file/ft_putnbr_fd.c \
      file/ft_putstr_fd.c \
      memory/ft_bzero.c memory/ft_calloc.c memory/ft_memchr.c \
      memory/ft_memcmp.c memory/ft_memcpy.c memory/ft_memmove.c \
      memory/ft_memset.c \
      string/ft_split.c string/ft_strchr.c string/ft_strdup.c \
      string/ft_striteri.c string/ft_strjoin.c string/ft_strlcat.c \
      string/ft_strlcpy.c string/ft_strlen.c string/ft_strmapi.c \
      string/ft_strncmp.c string/ft_strnstr.c string/ft_strrchr.c \
      string/ft_strtrim.c string/ft_substr.c

BONUS_SRC = list/ft_lstadd_back_bonus.c list/ft_lstadd_front_bonus.c list/ft_lstclear_bonus.c \
            list/ft_lstdelone_bonus.c list/ft_lstiter_bonus.c list/ft_lstlast_bonus.c \
            list/ft_lstmap_bonus.c list/ft_lstnew_bonus.c list/ft_lstsize_bonus.c

# Prepend directories
FULL_SRC = $(addprefix $(SRCDIR)/, $(SRC))
FULL_BONUS_SRC = $(addprefix $(SRCDIR)/, $(BONUS_SRC))

# Object files
OBJS = $(addprefix $(OBJDIR)/, $(SRC:.c=.o))
BONUS_OBJS = $(addprefix $(OBJDIR)/, $(BONUS_SRC:.c=.o))

# Default Target
all: $(NAME)

# Build the library
$(NAME): $(OBJS)
	@mkdir -p $(OBJDIR) $(LIBDIR)
	@echo "Archiving library $(NAME)"
	@ar rcs $@ $^

# Compile source files into object files
$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@mkdir -p $(dir $@)  # Create subdirectories for object files
	@echo "Compiling $(notdir $<) -> $(notdir $@)"
	@$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $@

# Bonus target
bonus: $(OBJS) $(BONUS_OBJS)
	@mkdir -p $(OBJDIR) $(LIBDIR)
	@echo "Archiving bonus objects into library $(NAME)"
	@ar rcs $(NAME) $(OBJS) $(BONUS_OBJS)

# Clean up
clean:
	rm -rf $(OBJDIR)
	@echo "Cleaned object files."

fclean: clean
	rm -f $(NAME)
	@echo "Cleaned library file."

re: fclean all

.PHONY: all bonus clean fclean re
