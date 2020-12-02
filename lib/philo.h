/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:15:12 by jecaudal          #+#    #+#             */
/*   Updated: 2020/12/02 10:47:53 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>

typedef char			t_bool;
typedef unsigned int	t_uint;
typedef struct timeval	t_timeval;
typedef unsigned char	t_uchar;

# define FALSE 0
# define TRUE 1
# define FAILURE 0
# define SUCCESS 1

typedef struct			s_stock
{
	t_uint				tt_die;
	t_uint				tt_eat;
	t_uint				tt_sleep;
	t_uint				n_philo;
	t_uint				n_meals;
	t_bool				is_n_meals;
}						t_stock;

/*
**	MAIN FUNCTION used one time and have key role
*/
t_stock					*parsing(int argc, char **argv);

# define EVENT_FORK "has taken a fork"
# define EVENT_EAT "is eating"
# define EVENT_SLEEP "is sleeping"
# define EVENT_THINK "is thinking"
# define EVENT_DIED "died"

# define ONE_MILLISECOND 1000

# define USAGE_P1 "\nUsage : ./philo_x (-v) [1] [2] [3] [4] ([5])\n"
# define USAGE_P2 "\t-v : Print philo with additionnal graphics.\n"
# define USAGE_P3 "\t[1] : number_of_philosopher value.\n"
# define USAGE_P4 "\t[2] : time_to_die value.\n"
# define USAGE_P5 "\t[3] : time_to_eat.\n"
# define USAGE_P6 "\t[4] : time_to_sleep.\n"
# define USAGE_P7 "\t[5] : nbr_of_time_each_philo_must_eat optionnal value.\n"

# define WARN_N_PHILO "WARNING : More than 200 could generate wrong results.\n"
# define WARN_DELA "WARNING : -60ms delay could be not enough for good result\n"

# define ERR_N_DISH "ERROR : Philos must have at least one dish to eat.\n"
# define ERR_TT_EAT "ERROR : Time to eat value must be upper than 0.\n"
# define ERR_TT_SLEEP "ERROR : Time to sleep value must be upper than 0.\n"
# define ERR_TT_DIE "ERROR : Time to die value must be upper than 0.\n"
# define ERR_N_PHILO "ERROR : Numbers of philos must be between 2 and 255.\n"

# define ERR_MUCH_ARG "ERROR : There is too much arguments.\n"
# define ERR_MISS_ARG "ERROR : One or more arguments is missing.\n"
# define ERR_NON_NUM_ARG "ERROR : All your arguments must be numbers.\n"

# define ERR_THREAD "ERROR : All threads could not be created (philo %d).\n"
# define ERR_MALLOC "ERROR : Memory allocation failed.\n"

# define N_PHILO 0
# define TT_DIE 1
# define TT_EAT 2
# define TT_SLEEP 3
# define N_MEALS 4

t_bool					l_isnum(char c);
t_bool					is_num(char *str);
int						l_atoi(char *str);
t_bool					l_isspace(char c);
void					l_strrev(char *str);
unsigned int			l_strlen(char *str);
int						l_strcmp(char *s1, char *s2);
void					*l_memcpy_n(void *s1, void *s2, unsigned int n);

void					print_usage(void);
void					print_warnings(int *args);
void					print(t_uint time, t_uint n_philo, char *event);
void					*parsing_panic(void *ptr, char *msg);

t_uint					get_curr_time(void);
t_uint					get_time(t_timeval tt_start);

#endif
