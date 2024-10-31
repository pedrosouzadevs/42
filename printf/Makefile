# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 14:09:56 by pedro-hm          #+#    #+#              #
#    Updated: 2024/10/31 18:53:53 by pedro-hm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_itoa_hex.c ft_utils.c ft_itoa.c ft_itoa_unsigned.c ft_itoa_ptr.c ft_trans.c

HEADER = ft_printf.h

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
