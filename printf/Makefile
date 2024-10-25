# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 14:09:56 by pedro-hm          #+#    #+#              #
#    Updated: 2024/10/23 16:18:24 by pedro-hm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/23 14:09:56 by pedro-hm          #+#    #+#              #
#    Updated: 2024/10/23 16:18:24 by pedro-hm         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC = ft_printf.c ft_puthex.c ft_printf_utils.c

HEADER = libft/libft.h ft_printf.h

LIBFT = libft/libft.a

OBJ = ${SRC:.c=.o}

CC = cc

CCFLAGS = -Wall -Wextra -Werror
NAME = libftprintf.a

.c.o:
	${CC} ${CCFLAGS} -c $< -o $@

all: ${LIBFT} ${NAME}

${LIBFT}:
	make -C libft

$(NAME): ${OBJ}
	ar rcs ${NAME} ${OBJ} ${LIBFT}
# $(NAME): ${OBJ}
# 	 ar rcs ${NAME} ${OBJ} ${HEADER}

clean:
	rm -f ${OBJ}
	make -C libft clean

fclean: clean
	rm -f ${NAME}
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re
# SRC = ft_printf.c ft_puthex.c

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
