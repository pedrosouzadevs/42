
NAME = so_long

# Src directory
SRC_DIR = ./src

# List of files
SRC = so_long.c

# Compilators and flags
CC = clang
CFLAGS = -Wall -Wextra -Werror -Ilibft


# Link flags
LDFLAGS = -lX11 -lXext -lmlx

# Main rule
all: $(LIBFT) $(NAME)

# Compile the game
$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(NAME)


# Cleaning
clean:
	rm -rf $(NAME)

fclean: clean
	rm -rf $(NAME)

# Rebuild
re: fclean all

.PHONY: all clean fclean re
