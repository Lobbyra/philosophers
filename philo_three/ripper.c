/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ripper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:38:49 by jecaudal          #+#    #+#             */
/*   Updated: 2020/12/01 16:08:37 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

void	*ripper(void *philo_ptr)
{
	t_bool	died;
	t_list	*philo;

	philo = (t_list*)philo_ptr;
	if (philo->to_eat > 0)
		while ((died = get_curr_time() < philo->tt_starvation)
		&& philo->to_eat != 0)
			usleep(10);
	else
		while ((died = (get_curr_time() < philo->tt_starvation)))
			usleep(10);
	philo->alive = FALSE;
	sem_wait(philo->print);
	if (died == FALSE)
		print(get_time(philo->tt_start) / 1000, philo->philo_pos, EVENT_DIED);
	free(philo_ptr);
	exit(died);
	return (NULL);
}
