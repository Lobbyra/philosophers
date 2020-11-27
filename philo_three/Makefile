# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/11/26 16:24:46 by jecaudal          #+#    #+#              #
#    Updated: 2020/11/27 15:43:35 by jecaudal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		=	philo_three

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
				./ripper.c			\
				./lst_new.c			\
				./philo_gen.c		\
				./philo_life.c		\
				./philo_monitor.c

CFLAGS		+=	-Wall -Wextra -Werror -pthread -I ../lib

CC			=	gcc

%.o : %.c
	$(CC) $(CFLAGS) $< -c

OBJS		=	$(SRCS:.c=.o)

all			:	$(NAME)

$(NAME)		:	$(OBJS) $(LIB_OBJS)
				$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LIB_OBJS)

asan		:	$(OBJS) $(LIB_OBJS)
				$(CC) -o $(NAME) -fsanitize=address $(CFLAGS) $(OBJS) $(LIB_OBJS)


clean		:
				rm -rf $(OBJS)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all
