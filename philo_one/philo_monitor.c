/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:30:03 by jecaudal          #+#    #+#             */
/*   Updated: 2020/12/02 16:46:14 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static t_uint	monitor_meals(t_list *p, int n_p)
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
	}
	if (n_ate == n_p)
		return (0);
	else
		return (p->philo_pos);
}

static t_uint	monitor_inf(t_list *p)
{
	t_bool	died;

	while ((died = (get_curr_time() < p->tt_starvation)))
		p = p->next;
	return (p->philo_pos);
}

void			philo_monitor(t_stock *s, t_list *p, t_list *begin)
{
	t_uint	p_pos_finished;
	t_uchar	n_philos;

	n_philos = s->n_philo;
	if (s->is_n_meals == TRUE)
		p_pos_finished = monitor_meals(p, n_philos);
	else
		p_pos_finished = monitor_inf(p);
	while (begin->philo_pos != n_philos)
	{
		begin->alive = FALSE;
		begin = begin->next;
	}
	begin->alive = FALSE;
	if (p_pos_finished > 0)
		print(get_time(p->tt_start) / 1000, p_pos_finished, EVENT_DIED);
}
