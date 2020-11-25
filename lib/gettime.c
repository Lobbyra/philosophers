/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettime.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:46:14 by jecaudal          #+#    #+#             */
/*   Updated: 2020/11/25 17:24:18 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_uint	get_time(t_timeval tt_start)
{
	unsigned int	time;
	t_timeval		curr;

	gettimeofday(&curr, NULL);
	curr.tv_sec -= tt_start.tv_sec;
	time = curr.tv_sec * 1000000;
	time += curr.tv_usec - tt_start.tv_usec;
	return (time);
}

t_uint	get_curr_time(void)
{
	t_timeval		curr;

	gettimeofday(&curr, NULL);
	return (curr.tv_sec * 1000000 + curr.tv_usec);
}
