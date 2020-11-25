# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/09/24 18:04:15 by jecaudal          #+#    #+#              #
#    Updated: 2020/11/24 11:11:54 by jecaudal         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

PATH_PHILO_ONE		=	./philo_one/
PATH_PHILO_TWO		=	./philo_two/
PATH_PHILO_THREE	=	./philo_three/

all					:
						@make -sC $(PATH_PHILO_ONE)
						@make -sC $(PATH_PHILO_TWO)
						@make -sC $(PATH_PHILO_THREE)
						@mv $(PATH_PHILO_ONE)/philo_one .
						@mv $(PATH_PHILO_TWO)/philo_two .
						@mv $(PATH_PHILO_THREE)/philo_three .
						@printf "🤖 : All philos are build and moved here !\n"

clean				:
						@make clean -sC $(PATH_PHILO_ONE)
						@make clean -sC $(PATH_PHILO_TWO)
						@make clean -sC $(PATH_PHILO_THREE)
						@rm -f philo_one
						@rm -f philo_two
						@rm -f philo_three
						@printf "🤖 : Clean done !\n"

fclean				:	clean
						@make fclean -sC $(PATH_PHILO_ONE)
						@make fclean -sC $(PATH_PHILO_TWO)
						@make fclean -sC $(PATH_PHILO_THREE)
						@printf "🤖 : Full clean done !\n"

re					:	fclean all
