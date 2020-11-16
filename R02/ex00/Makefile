# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ali <marvin@42.fr>                         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/15 09:49:15 by ali               #+#    #+#              #
#    Updated: 2020/09/27 09:30:18 by ali              ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc
SRCS = 	ft_utils2.c ft_utils.c ft_error.c ft_fill.c ft_display.c \
		ft_search.c ft_stock_dico.c ft_stock_dico2.c main.c \
		ft_utils4.c ft_utils3.c ft_get_sizeof_malloc.c ft_check_empty_str.c \
		ft_set_number.c
OBJS = $(SRCS:.c=.o)
CFLAGS = -Wall -Wextra -Werror
NAME = rush-02
RM = rm -rf

%.o:%.c
			$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)	
			$(CC) -o $(NAME) $(OBJS)

all:		$(NAME)

clean:
			$(RM) $(OBJS)

fclean:		clean
			$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re
.SUFFIXES:	.c.o.h
