# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcatalan@student.42barcelona.com <mcata    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 11:11:59 by mcatalan          #+#    #+#              #
#    Updated: 2024/06/03 10:02:40 by mcatalan@st      ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
GDBFLAG = -g

# Colors
RED = \033[0;31m
GREEN = \033[0;32m
YELLOW = \033[0;33m
BLUE = \033[0;34m
RESET = \033[0m

# Directories
SRC_DIR = src
OBJ_DIR = obj
LIBFT_DIR = ./includes/libft
MLX_DIR = ./includes/minilibx_macos

# Source files and corresponding object files
SRC_FILES =		src/main.c					\
				src/init.c					\
				src/utils/prints.c			\
				src/utils/errors.c			\
				src/utils/frees.c			\
				src/parsing/parsing.c		\
				src/parsing/get_info.c		\
				src/parsing/checker.c		\
				src/parsing/checker_map.c	\
				src/parsing/checker_utils.c	\
				src/parsing/parsing_utils.c	\
				src/parsing/map.c			\


OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Executable name
TARGET = cub3d

# Libraries
LIBS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx -g -framework OpenGL -framework AppKit

# Include directories
INC_DIRS = -I$(LIBFT_DIR)/includes -I$(MLX_DIR) -I$(SRC_DIR)

# Build rules
all: subsystems $(TARGET)
	@echo "$(GREEN)Build finished$(RESET)"

subsystems:
	@make -s -C $(LIBFT_DIR)
	@make -s -C $(MLX_DIR)


$(TARGET): $(OBJ_FILES)
	@echo "$(GREEN)Bulding libs and objets...$(RESET)"
	$(CC) $(CFLAGS) $(GDBFLAG) $(INC_DIRS) $^ -o $@ $(LIBS)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) $(GDBFLAG) $(INC_DIRS) -c $< -o $@

clean:
	@echo "$(RED)Cleaning up objets...$(RESET)"
	@make -s -C $(MLX_DIR) clean
	@make -s -C $(LIBFT_DIR) clean
	@rm -rf $(OBJ_DIR)

fclean: clean
	@echo "$(RED)Cleaning all...$(RESET)"
	@rm -f $(TARGET)
	@echo "$(RED)Cleaning libft...$(RESET)"
	@make -s -C $(LIBFT_DIR) fclean
	@echo "$(RED)Cleaning minilibx...$(RESET)"
	@make -s -C $(MLX_DIR) clean
	@echo "$(RED)Removing obj folder...$(RESET)"

re: fclean all

.PHONY: all clean fclean re
