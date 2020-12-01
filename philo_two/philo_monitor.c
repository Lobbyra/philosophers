/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:23:11 by jecaudal          #+#    #+#             */
/*   Updated: 2020/12/01 12:48:35 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static t_bool	monitor_meals(t_list *p, int n_p)
{
	t_bool	died;
	t_uchar n_ate;

	n_ate = 0;
	while (n_ate < n_p && (died = (get_curr_time() < p->tt_starvation)))
	{
		if (p->to_eat == 0)
			n_ate++;
		else
			n_ate = 0;
		p = p->next;
		usleep(1);
	}
	return (died);
}

static t_bool	monitor_inf(t_list *p)
{
	t_bool	died;

	while ((died = (get_curr_time() < p->tt_starvation)))
	{
		p = p->next;
		usleep(1);
	}
	// printf("%u, %u\n", get_curr_time(), p->tt_starvation);
	return (died);
}

void		philo_monitor(t_stock *s, t_list *p, t_list *begin)
{
	t_bool	died;
	t_uchar	n_philos;

	n_philos = s->n_philo;
	if (s->is_n_meals == TRUE)
		died = monitor_meals(p, n_philos);
	else
		died = monitor_inf(p);
	if (died == FALSE)
		print(get_time(p->tt_start) / 1000, p->philo_pos, EVENT_DIED);
	while (begin->philo_pos != n_philos)
	{
		begin->alive = FALSE;
		begin = begin->next;
	}
	begin->alive = FALSE;
}
