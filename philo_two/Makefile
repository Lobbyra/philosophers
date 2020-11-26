# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 12:18:22 by jecaudal          #+#    #+#              #
#    Updated: 2020/11/26 15:10:19 by jecaudal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo_two

LIB_SRCS	=	../lib/print.c			\
				../lib/l_atoi.c			\
				../lib/l_isnum.c		\
				../lib/gettime.c		\
				../lib/parsing.c		\
				../lib/l_strcmp.c		\
				../lib/l_strrev.c		\
				../lib/l_strlen.c		\
				../lib/l_isspace.c		\
				../lib/l_memcpy_n.c		\
				../lib/parsing_utils.c

LIB_OBJS	=	$(LIB_SRCS:.c=.o)

SRCS		=	./main.c			\
				./lst_new.c			\
				./philo_gen.c		\
				./philo_life.c		\
				./philo_monitor.c

CC			=	gcc

OBJS		=	$(SRCS:.c=.o)

CFLAGS		+=	-Wall -Wextra -Werror -pthread -I ../lib

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(LIB_OBJS)
				$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIB_OBJS)

clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all
