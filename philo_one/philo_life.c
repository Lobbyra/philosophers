/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_life.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 14:44:49 by jecaudal          #+#    #+#             */
/*   Updated: 2020/12/01 12:46:08 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static t_bool	take_forks(t_list *philo)
{
	pthread_mutex_lock(philo->fork1);
	pthread_mutex_lock(philo->fork2);
	print(get_time(philo->tt_start) / 1000, philo->philo_pos, EVENT_FORK);
	print(get_time(philo->tt_start) / 1000, philo->philo_pos, EVENT_FORK);
	return (TRUE);
}

static t_bool	p_eat(t_list *philo)
{
	philo->alive = TRUE;
	philo->tt_starvation = get_curr_time() + philo->time_to_die * 1000;
	if (philo->to_eat > 0)
		philo->to_eat--;
	print(get_time(philo->tt_start) / 1000, philo->philo_pos, EVENT_EAT);
	usleep(philo->time_to_eat * ONE_MILLISECOND);
	pthread_mutex_unlock(philo->fork1);
	pthread_mutex_unlock(philo->fork2);
	if (philo->to_eat == 0)
		return (FALSE);
	return (philo->alive);
}

static t_bool	p_sleep(t_list *philo)
{
	print(get_time(philo->tt_start) / 1000, philo->philo_pos, EVENT_SLEEP);
	usleep(philo->time_to_sleep * ONE_MILLISECOND);
	return (philo->alive);
}

static t_bool	p_think(t_list *philo)
{
	print(get_time(philo->tt_start) / 1000, philo->philo_pos, EVENT_THINK);
	if (philo->n_philo % 2)
		usleep(philo->time_to_sleep * 999);
	return (philo->alive);
}

void			*philo_life(void *philo)
{
	int	i;
	t_bool	(*arr[4])(t_list *) = {take_forks, p_eat, p_sleep, p_think};

	i = 0;
	while (arr[i](philo))
	{
		if (i == 3)
			i = 0;
		else
			i++;
	}
	return (NULL);
}
