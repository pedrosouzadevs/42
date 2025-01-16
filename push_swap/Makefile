NAME			=	push_swap
BONUS_NAME		=	checker
RM				=	rm -f
CC				=	cc
CFLAGS			=	-Wall -Wextra -Werror -g3

SRC_PATH		=	./mandatory
BONUS_PATH		=	./bonus
INC_PATH		=	./include
CMD_PATH 		= 	movments/
LIB_PATH		=	./libs/libft
CMD_PATH_BONUS 	= 	./movments_bonus/

SRC				=	$(CMD_PATH)push.c \
					$(CMD_PATH)reverse_rotate.c \
					$(CMD_PATH)rotate.c \
					$(CMD_PATH)swap.c \
					push_swap.c \
					big_sort_utils.c \
					big_sort.c \
					handle_errors.c \
					handle_nodes.c \
					handle_sort.c \
					handle_stacks.c \
					init_push_swap.c \
					small_sort.c \
					validate_arguments.c

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

BONUS_SRC		=	$(CMD_PATH_BONUS)push_bonus.c \
					$(CMD_PATH_BONUS)reverse_rotate_bonus.c \
					$(CMD_PATH_BONUS)rotate_bonus.c \
					$(CMD_PATH_BONUS)swap_bonus.c \
					checker.c \
					handle_errors_bonus.c \
					handle_nodes_bonus.c \
					handle_stacks_bonus.c \
					init_push_swap_bonus.c \
					read_commands_bonus.c \
					validate_arguments_bonus.c

OBJ				=	$(addprefix $(SRC_PATH)/, $(SRC:.c=.o))
BONUS_OBJ		=	$(addprefix $(BONUS_PATH)/, $(BONUS_SRC:.c=.o))
LIB_OBJ			=	$(addprefix $(LIB_PATH)/, $(LIBFT_SRC:.c=.o))


all:			$(NAME)

# $(PRINTF):
# 	make -C $(PRINTF_PATH) -s

$(NAME):$(OBJ) $(LIB_OBJ)
	$(CC) $(CFLAGS) $(OBJ) $(LIB_OBJ) -o $(NAME)

# $(NAME):			$(LIBFT) $(PRINTF) $(OBJ)
# 	$(CC) $(CFLAGS) $(OBJ) -L$(LIB_PATH) -lft -L$(PRINTF_PATH) -lftprintf -o $(NAME)

$(SRC_PATH)/movments/%.o: $(SRC_PATH)/movments/%.c $(INC_PATH)/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(SRC_PATH)/%.o: $(SRC_PATH)/%.c $(INC_PATH)/push_swap.h
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_PATH)/%.o: $(LIB_PATH)/%.c $(LIB_PATH)/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

bonus:				$(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJ) $(LIB_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(LIB_OBJ) -o $(BONUS_NAME)

$(BONUS_PATH)/%.o: $(BONUS_PATH)/%.c $(INC_PATH)/checker.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUS_OBJ) $(LIB_OBJ)

fclean:				clean
	$(RM) $(NAME) $(BONUS_NAME) $(LIB_OBJ)

re:					fclean all

.PHONY:		all bonus clean fclean re
