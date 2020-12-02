/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_gen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 12:09:33 by jecaudal          #+#    #+#             */
/*   Updated: 2020/12/02 10:36:14 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

t_list			*philo_gen(t_stock *s)
{
	t_list	*begin;
	t_list	*curr;
	t_list	*next;
	sem_t	*forks;

	sem_unlink(NAME_SEM_FORKS);
	if ((forks = sem_open(NAME_SEM_FORKS, 100, 0660, s->n_philo)) == SEM_FAILED)
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
