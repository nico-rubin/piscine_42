# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrubin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/28 11:39:02 by nrubin            #+#    #+#              #
#    Updated: 2020/09/28 12:33:11 by nrubin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a
SRC = $(addprefix ${DIR}/, ft_putchar.c ft_swap.c ft_putstr.c ft_strlen.c ft_strcmp.c)
OBJ = ${SRC:.c=.o}
HEAD = includes
DIR = srcs

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

${NAME} :			${OBJ}
					ar rcs ${NAME} ${OBJ}

.c.o:
					${CC} -c ${CFLAGS} -o $@ $< -I ${HEAD}

all:				${NAME}

clean :
					${RM} ${OBJ}

fclean :			clean
					${RM} ${NAME}

re :				fclean all

.PHONY: all clean fclean re
