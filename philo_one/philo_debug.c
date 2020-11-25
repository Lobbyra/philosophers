/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_debug.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:17:03 by jecaudal          #+#    #+#             */
/*   Updated: 2020/11/25 16:18:40 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

void		philo_debug(t_list *begin, int n_philos)
{
	while (begin && begin->philo_pos != n_philos)
	{
		printf("Address of curr node : %p\n", begin);
		printf("Address of next node : %p\n", begin->next);
		printf("Address of fork1     : %p\n", begin->fork1);
		printf("Address of fork2     : %p\n", begin->fork2);
		printf("time to eat          : %u\n", begin->time_to_eat);
		printf("time to sleep        : %u\n", begin->time_to_sleep);
		printf("time to die          : %u\n", begin->time_to_die);
		printf("philo_pos            : %d\n", begin->philo_pos);
		fflush(stdout);
		begin = begin->next;
	}
	printf("Address of curr node : %p\n", begin);
	printf("Address of next node : %p\n", begin->next);
	printf("Address of fork1     : %p\n", begin->fork1);
	printf("Address of fork2     : %p\n", begin->fork2);
	printf("time to eat          : %u\n", begin->time_to_eat);
	printf("time to sleep        : %u\n", begin->time_to_sleep);
	printf("time to die          : %u\n", begin->time_to_die);
	printf("philo_pos            : %d\n", begin->philo_pos);
}
