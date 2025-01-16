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

SRC_CLIENT = printf/ft_printf.c \
			printf/ft_itoa_hex.c \
			printf/ft_utils.c \
			printf/ft_itoa.c \
			printf/ft_itoa_unsigned.c \
			printf/ft_itoa_ptr.c \
			printf/ft_trans.c \
			utils.c \
			client.c

SRC_SERVER = printf/ft_printf.c \
			printf/ft_itoa_hex.c \
			printf/ft_utils.c \
			printf/ft_itoa.c \
			printf/ft_itoa_unsigned.c \
			printf/ft_itoa_ptr.c \
			printf/ft_trans.c \
			utils.c \
			server.c

HEADER = printf/ft_printf.h minitalk.h

OBJ_CLIENT = ${SRC_CLIENT:.c=.o}
OBJ_SERVER = ${SRC_SERVER:.c=.o}

CC = cc

CCFLAGS = -Wall -Wextra -Werror

NAME_CLIENT = client
NAME_SERVER = server

.c.o:
	${CC} ${CCFLAGS} -c $< -o $@

all: ${NAME_CLIENT} ${NAME_SERVER}

$(NAME_CLIENT): ${OBJ_CLIENT}
	${CC} ${CCFLAGS} ${OBJ_CLIENT} -o ${NAME_CLIENT}

$(NAME_SERVER): ${OBJ_SERVER}
	${CC} ${CCFLAGS} ${OBJ_SERVER} -o ${NAME_SERVER}

clean:
	rm -f ${OBJ_CLIENT} ${OBJ_SERVER}

fclean: clean
	rm -f ${NAME_CLIENT} ${NAME_SERVER}

re: fclean all

.PHONY: all clean fclean re
