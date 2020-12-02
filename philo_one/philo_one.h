/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_one.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:23:13 by jecaudal          #+#    #+#             */
/*   Updated: 2020/12/02 10:31:58 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_ONE_H
# define PHILO_ONE_H

# include "philo.h"

# include <pthread.h>

typedef pthread_mutex_t	t_mutex;
typedef pthread_t		t_thread;

void				*philo_life(void *philo);

/*
**	t_list		*next;		-> ptr to next philo
**	t_bool		alive;		-> alive value controlled by main to decide if die
**	int			to_eat;		-> n dish have to eat, ==-1 if its not specified.
**	t_uchar		philo_pos;	-> pos of the philosophers
**	t_mutex		*fork1;		-> ptr to first fork
**	t_mutex		*fork2;		-> ptr to second fork
**	t_timeval	tt_ate;		-> last timestamp he ate
**	t_timeval	tt_start;	-> timestamp of the start of the philo
*/

typedef struct		s_list
{
	int				to_eat;
	struct s_list	*next;
	t_bool			alive;
	t_uint			n_philo;
	t_uint			time_to_eat;
	t_uint			time_to_die;
	t_uint			time_to_sleep;
	t_uint			tt_starvation;
	t_mutex			*fork1;
	t_mutex			*fork2;
	t_uchar			philo_pos;
	t_thread		th;
	t_timeval		tt_start;
}					t_list;

typedef t_bool	(*t_actions_arr)(t_list*);

t_list				*lstnew(t_stock *s, t_mutex *forks, t_uint philo_pos);
t_list				*philo_gen(t_stock *s);
void				philo_monitor(t_stock *s, t_list *p, t_list *begin);

# define ERR_MUTEX_INIT "ERROR: A mutex init failed. fatal error.\n"

#endif
