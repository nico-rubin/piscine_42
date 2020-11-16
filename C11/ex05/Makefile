# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nrubin <marvin@42.fr>                      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/10/01 12:37:57 by nrubin            #+#    #+#              #
#    Updated: 2020/10/01 18:04:56 by nrubin           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = do-op
SRCS = $(addprefix ./, do_op.c ops.c utils.c)
HEAD = $(addprefix ./, ft.h)
OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Wextra -Werror
RM = rm -f

all :			${NAME}

${NAME}    :	${OBJS}
				gcc -o ${NAME} ${OBJS}

.c.o :
				${CC} -c ${CFLAGS} -o $@ $< -I ${HEAD}

clean :
				${RM} ${OBJS}

fclean :		clean
				${RM} ${NAME}

re :			fclean all

.PHONY: all clean fclean re
