NAME	:= so_long
CFLAGS	:= -Wextra -Wall -Werror -Wunreachable-code -fPIE
LIBMLX	:= ./MLX42

HEADERS	:= -I ./include -I $(LIBMLX)/include
LIBS	:= $(LIBMLX)/build/libmlx42.a -ldl -lglfw -pthread -lm
LIB_PATH		=	./libs/libft
SRC = free_all.c handler_map.c render_map.c so_long.c
SRC_PATH = ./src

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

OBJ				=	$(addprefix $(SRC_PATH)/, $(SRC:.c=.o))
LIB_OBJ			=	$(addprefix $(LIB_PATH)/, $(LIBFT_SRC:.c=.o))

all: libmlx $(NAME)

libmlx:
	@cmake $(LIBMLX) -B $(LIBMLX)/build && make -C $(LIBMLX)/build -j4

%.o: %.c
	@$(CC) $(CFLAGS) -o $@ -c $< $(HEADERS) && printf "Compiling: $(notdir $<)"

$(NAME): $(OBJ) $(LIB_OBJ)
	@$(CC) $(OBJ) $(LIB_OBJ) $(LIBS) $(HEADERS) -pie -o $(NAME)

clean:
	@rm -rf $(OBJ)
	@rm -rf $(LIB_OBJ)
	@rm -rf $(LIBMLX)/build

fclean: clean
	@rm -rf $(NAME)

re: clean all

.PHONY: all, clean, fclean, re, libmlx
