# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 14:09:56 by pedro-hm          #+#    #+#              #
#    Updated: 2024/10/25 18:05:11 by pedro-hm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# CC		:= cc

# NAME = libftprintf.a

# CFLAGS	:= -Wall -Wextra -Werror -g3

# # HEADERS	:= -I includes/ -I libs/libft/
# HEADERS	:= includes/ libs/libft/

# LIBFT	:= libs/libft/libft.a

# SRC = ft_printf.c ft_puthex.c ft_count.c ft_printf_utils.c

# OBJ		:= $(SRC:%.c=%.o)

# %.o: &.c
# 	$(CC) $(CFLAGS) -c $< -o $@ $(HEADER)

# all: $(NAME)

# $(NAME): $(LIBFT) $(OBJ)
# 	$(CC) $(CFLAGS) $(OBJ) -o $@ -Llibs/libft -lft

# $(LIBFT):
# 	@make -C libs/libft/

# clean:
# 	rm -rf $(OBJ)
# 	make -C libs/libft clean

# fclean: clean
# 	rm -rf $(NAME)
# 	make -C libs/libft fclean

# re:	clean all

# PHONY: all, clean, fclean, re
SRC = ft_printf.c ft_puthex.c ft_printf_utils.c ft_count.c

HEADER = includes/ft_printf.h

LIBFT = libs/libft/libft.a

OBJ = ${SRC:.c=.o}

CC = cc

CCFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

.c.o:
	${CC} ${CCFLAGS} -c $< -o $@

all: ${LIBFT} ${NAME}

${LIBFT}:
	make -C libs/libft

$(NAME): ${OBJ}
	ar rcs ${NAME} ${OBJ} ${LIBFT}
# $(NAME): ${OBJ}
# 	 ar rcs ${NAME} ${OBJ} ${HEADER}

clean:
	rm -f ${OBJ}
	make -C libs/libft clean

fclean: clean
	rm -f ${NAME}
	make -C libs/libft fclean

re: fclean all

.PHONY: all clean fclean re
# SRC = ft_printf.c ft_puthex.c ft_printf_utils.c ft_count.c

# HEADER = -Ilibft -I.
# # HEADER = libft/libft.h ft_printf.h

# LIBFT = libft/libft.a

# OBJ = ${SRC:.c=.o}

# CC = cc

# CCFLAGS = -Wall -Wextra -Werror
# NAME = libftprintf.a

# .c.o:
# 	${CC} ${CCFLAGS} -c $< -o $@

# all: ${NAME}

# $(NAME): ${OBJ}
# 	cc ${CCFLAGS} ${OBJ} ${LIBFT} -o ${NAME} ${HEADER}
# # $(NAME): ${OBJ} ${OBJ_BONUS}
# # 	 ar rcs ${NAME} ${OBJ} ${OBJ_BONUS} ${HEADER}

# clean:
# 	rm -f ${OBJ}

# fclean: clean
# 	rm -f ${NAME}

# re: fclean all


# .PHONY: all clean fclean re
