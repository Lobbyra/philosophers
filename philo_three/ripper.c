/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ripper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:38:49 by jecaudal          #+#    #+#             */
/*   Updated: 2020/12/02 11:50:53 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	destroy_others(t_list *philo)
{
	t_uint	og_pos;
	t_list	*prev;

	og_pos = philo->philo_pos;
	philo = philo->next;
	prev = philo;
	philo = philo->next;
	while (prev->philo_pos != og_pos)
	{
		free(prev);
		prev = philo;
		philo = philo->next;
	}
	free(prev);
}

void	*ripper(void *philo_ptr)
{
	t_bool	alive;
	t_list	*philo;

	philo = (t_list*)philo_ptr;
	if (philo->to_eat > 0)
		while ((alive = get_curr_time() < philo->tt_starvation)
		&& philo->to_eat != 0)
			usleep(1);
	else
		while ((alive = (get_curr_time() < philo->tt_starvation)))
			usleep(1);
	philo->alive = FALSE;
	sem_post(philo->forks);
	sem_post(philo->forks);
	if (alive == FALSE)
	{
		sem_wait(philo->print);
		print(get_time(philo->tt_start) / 1000, philo->philo_pos, EVENT_DIED);
	}
	destroy_others(philo);
	exit(alive);
	return (NULL);
}
