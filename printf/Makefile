# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 14:09:56 by pedro-hm          #+#    #+#              #
#    Updated: 2024/10/28 18:39:15 by pedro-hm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_itoa_hex.c ft_printf_utils.c ft_printf_utils2.c ft_itoa.c ft_strlcpy.c

HEADER = includes/ft_printf.h

OBJ = ${SRC:.c=.o}

CC = cc

CCFLAGS = -Wall -Wextra -Werror

NAME = libftprintf.a

.c.o:
	${CC} ${CCFLAGS} -c $< -o $@

all: ${NAME}

$(NAME): ${OBJ}
	ar rcs ${NAME} ${OBJ} ${HEADER}

clean:
	rm -f ${OBJ}
fclean: clean
	rm -f ${NAME}

re: fclean all


.PHONY: all clean fclean re
