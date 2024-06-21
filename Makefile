# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mcatalan <mcatalan@student.42barcelona.    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 11:11:59 by mcatalan          #+#    #+#              #
#    Updated: 2024/06/21 19:32:26 by mcatalan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror
# GDBFLAG = -g
GDBFLAG = -fsanitize=address -g

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
# MLX_DIR = ./includes/minilibx_macos
MLX_DIR = ./includes/minilibx-linux

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
				src/parsing/map_utils.c		\
				src/game/game.c				\
				src/game/movement.c			\
				src/game/rays.c				\
				src/game/game_utils.c		\

OBJ_FILES = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRC_FILES))

# Executable name
TARGET = cub3d

# Libraries
LIBS = -L$(LIBFT_DIR) -lft -L$(MLX_DIR) -lmlx_Linux -L/usr/lib -I$(MLX_DIR) -lXext -lX11 -lm #-lz

# Include directories
INC_DIRS = -I$(LIBFT_DIR)/includes -I$(MLX_DIR) -I$(SRC_DIR)

# Build rules
all: subsystems $(TARGET)
	@echo "$(GREEN)Build finished$(RESET)"

subsystems:
	@make -s -C $(LIBFT_DIR)
	@make -C $(MLX_DIR)


$(TARGET): $(OBJ_FILES)
	@echo "$(GREEN)Building libs and objects...$(RESET)"
	$(CC) $(CFLAGS) $(GDBFLAG) $(INC_DIRS) $^ -o $@ -fPIE $(LIBS)

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
