/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_monitor.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:00:57 by jecaudal          #+#    #+#             */
/*   Updated: 2020/11/27 15:17:45 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

static void	wait_philos(t_uint n_done, t_uint n_philo)
{
	int status;

	status = 0;
	while (n_done < n_philo)
	{
		if (wait4(0, &status, WNOHANG, NULL))
		{
			if (WEXITSTATUS(status) == RET_DIED)
				break;
			else
				n_done++;
		}
	}
}

static void kill_philos(t_list *p, t_uint n_philo)
{
	while (p->philo_pos != n_philo)
	{
		kill(p->pid, SIGKILL);
		p = p->next;
	}
	kill(p->pid, SIGKILL);
}

void		philo_monitor(t_stock *s, t_list *p)
{
	wait_philos(0, s->n_philo);
	kill_philos(p, s->n_philo);
}
