
NAME = so_long
RM				=	rm -f
# Src directory
SRC_PATH = ./src
LIB_PATH		=	./libs/libft
# List of files
SRC = free_all.c handler_map.c render_map.c so_long.c

LIBFT_SRC		=	ft_isalnum.c ft_isalpha.c ft_isdigit.c ft_strlen.c ft_isascii.c \
					ft_isprint.c ft_memset.c ft_bzero.c ft_memcpy.c ft_memmove.c \
					ft_toupper.c ft_tolower.c ft_strchr.c \
					ft_strrchr.c ft_memchr.c ft_atoi.c ft_strdup.c \
					ft_strlcpy.c ft_strlcat.c ft_calloc.c ft_memcmp.c ft_strnstr.c \
					ft_substr.c ft_strncmp.c ft_strjoin.c ft_strtrim.c ft_split.c ft_itoa.c \
					ft_strmapi.c ft_striteri.c ft_putchar_fd.c ft_putstr_fd.c ft_putendl_fd.c \
					ft_putnbr_fd.c	ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c \
					ft_lstdelone.c ft_lstiter.c ft_lstclear.c ft_lstmap.c get_next_line_bonus.c \
					ft_trans.c ft_itoa_c.c ft_utils_printf.c ft_printf.c ft_itoa_hex.c ft_itoa_ptr.c \
					ft_itoa_unsigned.c

# Compilators and flags
CC = clang
CFLAGS = -Wall -Wextra -Werror -g

OBJ				=	$(addprefix $(SRC_PATH)/, $(SRC:.c=.o))
LIB_OBJ			=	$(addprefix $(LIB_PATH)/, $(LIBFT_SRC:.c=.o))

# Link flags
LDFLAGS = -lX11 -lXext -lmlx

# Main rule
all: $(NAME)

# Compile the game
$(NAME): $(OBJ) $(LIB_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_OBJ) $(LDFLAGS) -o $(NAME)

$(SRC_PATH)/%.o: $(SRC_PATH)/%.c $(INC_PATH)/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_PATH)/%.o: $(LIB_PATH)/%.c $(LIB_PATH)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

# Cleaning
clean:
	$(RM) $(OBJ) $(BONUS_OBJ) $(LIB_OBJ)

fclean: clean
	$(RM) $(NAME) $(BONUS_NAME) $(LIB_OBJ)

# Rebuild
re: fclean all

.PHONY: all clean fclean re
