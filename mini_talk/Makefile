# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 14:09:56 by pedro-hm          #+#    #+#              #
#    Updated: 2025/01/29 13:26:26 by pedro-hm         ###   ########.fr        #
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

SRC_CLIENT_BONUS = printf/ft_printf.c \
			printf/ft_itoa_hex.c \
			printf/ft_utils.c \
			printf/ft_itoa.c \
			printf/ft_itoa_unsigned.c \
			printf/ft_itoa_ptr.c \
			printf/ft_trans.c \
			Bonus/utils_bonus.c \
			Bonus/client_bonus.c

SRC_SERVER_BONUS = printf/ft_printf.c \
			printf/ft_itoa_hex.c \
			printf/ft_utils.c \
			printf/ft_itoa.c \
			printf/ft_itoa_unsigned.c \
			printf/ft_itoa_ptr.c \
			printf/ft_trans.c \
			Bonus/utils_bonus.c \
			Bonus/server_bonus.c


HEADER = -I printf/ft_printf.h minitalk.h
HEADER_BONUS = -I printf/ft_printf.h Bonus/minitalk_bonus.h

OBJ_CLIENT = ${SRC_CLIENT:.c=.o}
OBJ_SERVER = ${SRC_SERVER:.c=.o}

OBJ_CLIENT_BONUS = ${SRC_CLIENT_BONUS:.c=.o}
OBJ_SERVER_BONUS = ${SRC_SERVER_BONUS:.c=.o}

CC = cc

CCFLAGS = -Wall -Wextra -Werror

NAME_CLIENT = client
NAME_SERVER = server
NAME_CLIENT_BONUS = client_bonus
NAME_SERVER_BONUS = server_bonus

.c.o:
	${CC} ${CCFLAGS} -c $< -o $@

all: ${NAME_CLIENT} ${NAME_SERVER}

$(NAME_CLIENT): ${OBJ_CLIENT}
	${CC} ${CCFLAGS} ${OBJ_CLIENT} -o ${NAME_CLIENT}

$(NAME_SERVER): ${OBJ_SERVER}
	${CC} ${CCFLAGS} ${OBJ_SERVER} -o ${NAME_SERVER}

bonus: ${NAME_CLIENT_BONUS} ${NAME_SERVER_BONUS}

$(NAME_CLIENT_BONUS): ${OBJ_CLIENT_BONUS}
	${CC} ${CCFLAGS} ${OBJ_CLIENT_BONUS} -o ${NAME_CLIENT_BONUS}

$(NAME_SERVER_BONUS): ${OBJ_SERVER_BONUS}
	${CC} ${CCFLAGS} ${OBJ_SERVER_BONUS} -o ${NAME_SERVER_BONUS}

clean:
	rm -f ${OBJ_CLIENT} ${OBJ_SERVER} ${OBJ_CLIENT_BONUS} ${OBJ_SERVER_BONUS}

fclean: clean
	rm -f ${NAME_CLIENT} ${NAME_SERVER} ${NAME_CLIENT_BONUS} ${NAME_SERVER_BONUS}

re: fclean all

.PHONY: all clean fclean re bonus
