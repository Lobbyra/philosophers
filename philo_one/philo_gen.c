/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_gen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:09:33 by jecaudal          #+#    #+#             */
/*   Updated: 2020/11/25 18:17:48 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

static t_mutex	*create_forks(t_uint n_philos)
{
	t_uint	i;
	t_mutex	*forks;

	i = 0;
	if (!(forks = (t_mutex*)malloc(sizeof(t_mutex) * (n_philos))))
		return (NULL);
	while (i < n_philos)
	{
		if (pthread_mutex_init(forks + i, NULL))
		{
			write(1, ERR_MUTEX_INIT, sizeof(ERR_MUTEX_INIT));
			free(forks);
			return (NULL);
		}
		i++;
	}
	return (forks);
}

t_list			*philo_gen(t_stock *s)
{
	t_list	*begin;
	t_list	*curr;
	t_list	*next;
	t_mutex	*forks;

	if (!(forks = create_forks(s->n_philo)))
		return (NULL);
	begin = lstnew(s, forks, 1);
	curr = begin;
	while (curr->philo_pos < s->n_philo)
	{
		next = lstnew(s, forks, curr->philo_pos + 1);
		curr->next = next;
		curr = curr->next;
	}
	curr->next = begin;
	return (begin);
}
