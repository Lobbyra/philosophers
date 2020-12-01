/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_two.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:23:13 by jecaudal          #+#    #+#             */
/*   Updated: 2020/12/01 12:37:22 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_TWO_H
# define PHILO_TWO_H

# include "philo.h"

#include <semaphore.h>
#include <pthread.h>

typedef pthread_t		t_thread;

void			*philo_life(void *philo);

/*
**	t_list		*next;		-> ptr to next philo
**	t_bool		alive;		-> alive value controlled by main to decide if die
**	int			to_eat;		-> n dish have to eat, ==-1 if its not specified.
**	t_uchar		philo_pos;	-> pos of the philosophers
**	t_mutex		*forks;		-> ptr to forks on the table
**	t_timeval	tt_ate;		-> last timestamp he ate
**	t_timeval	tt_start;	-> timestamp of the start of the philo
*/

typedef struct		s_list
{
	int				to_eat;
	sem_t			*forks;
	struct s_list	*next;
	t_bool			alive;
	t_uint			n_philo;
	t_uint			time_to_eat;
	t_uint			time_to_die;
	t_uint			time_to_sleep;
	t_uint			tt_starvation;
	t_uchar			philo_pos;
	t_thread		th;
	t_timeval		tt_start;
}					t_list;

# define NAME_SEM_FORKS "huiosdfuigosfhdugiofhdugis"

t_list	*lstnew(t_stock *s, sem_t *forks, t_uint philo_pos);
t_list	*philo_gen(t_stock *s);

void		philo_monitor(t_stock *s, t_list *p, t_list *begin);
void		philo_debug(t_list *begin, int n_philos);

# define ERR_MUTEX_INIT "ERROR: A mutex init failed. fatal error.\n"

#endif
