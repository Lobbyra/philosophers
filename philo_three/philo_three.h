/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_three.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:21:40 by jecaudal          #+#    #+#             */
/*   Updated: 2020/12/02 10:46:01 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_THREE_H
# define PHILO_THREE_H

# include "philo.h"

# include <semaphore.h>
# include <sys/wait.h>
# include <pthread.h>
# include <signal.h>

# define RET_DIED FALSE

typedef pthread_t		t_thread;

/*
**	t_list		*next;		->	ptr to next philo
**	int			to_eat;		->	n dish have to eat, ==-1 if its not specified.
**	t_uchar		philo_pos;	->	pos of the philosophers
**	t_mutex		*forks;		->	ptr to forks on the table
**	t_timeval	tt_ate;		->	last timestamp he ate
**	t_timeval	tt_start;	->	timestamp of the start of the philo
**	pid_t		pid;		->	Pid of the current philo
**	t_thread	ripper;		->	Thread of the ripper. Ripper is a thread that
**								will check the starvation of the philosopher
**								and will exit the process after print the die.
*/

typedef struct		s_list
{
	int				to_eat;
	pid_t			pid;
	sem_t			*forks;
	sem_t			*print;
	struct s_list	*next;
	t_bool			alive;
	t_uint			n_philo;
	t_uint			time_to_eat;
	t_uint			time_to_die;
	t_uint			time_to_sleep;
	t_uint			tt_starvation;
	t_uchar			philo_pos;
	t_thread		ripper;
	t_timeval		tt_start;
}					t_list;

typedef t_bool	(*t_actions_arr)(t_list*);

t_list				*lstnew(t_stock *s, sem_t *f, sem_t *print, t_uint p_pos);
t_list				*philo_gen(t_stock *s);

void				philo_monitor(t_stock *s, t_list *p);
void				philo_debug(t_list *begin, int n_philos);
void				print_sem(t_uint time, t_list *philo, char *event);

void				*ripper(void *philo_ptr);
void				*philo_life(void *philo);

# define ERR_MUTEX_INIT "ERROR: A mutex init failed. fatal error.\n"
# define NAME_SEM_FORKS "huiosdfuigosfhdugiofhdugis"
# define NAME_SEM_PRINT "fdg6s4df68hs48gh64t8y4j68p"

#endif
