# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 20:16:54 by asilveir          #+#    #+#              #
#    Updated: 2024/12/09 16:51:20 by asilveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Src directory
SRC_DIR = ./src

# List of files
SRC = $(SRC_DIR)/so_long.c $(SRC_DIR)/setup_game.c $(SRC_DIR)/handle_events.c \
	$(SRC_DIR)/process_inputs.c $(SRC_DIR)/render_map.c $(SRC_DIR)/render_character.c \
	$(SRC_DIR)/background_utils_1.c $(SRC_DIR)/background_utils_2.c $(SRC_DIR)/process_movements.c \
	$(SRC_DIR)/render_collectible.c $(SRC_DIR)/render_door.c $(SRC_DIR)/map_utils.c $(SRC_DIR)/move_up.c \
	$(SRC_DIR)/move_down.c $(SRC_DIR)/move_right.c $(SRC_DIR)/move_left.c $(SRC_DIR)/map_init.c \
	$(SRC_DIR)/map_validation_utils_1.c $(SRC_DIR)/map_validation_utils_2.c $(SRC_DIR)/map_validation_utils_3.c \
	$(SRC_DIR)/flood_fill_utils_1.c $(SRC_DIR)/flood_fill_utils_2.c $(SRC_DIR)/close_game.c

# Compilators and flags
CC = clang
CFLAGS = -Wall -Wextra -Werror -Ilibft

# Libft directories
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Link flags
LDFLAGS = -L$(LIBFT_DIR) -lft -lX11 -lXext -lmlx

# Main rule
all: $(LIBFT) $(NAME)

# Compile the game
$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(LDFLAGS) -o $(NAME)

# Compile Libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Cleaning
clean:
	rm -rf $(NAME)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

# Rebuild
re: fclean all

.PHONY: all clean fclean re
