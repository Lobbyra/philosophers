/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_gen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 16:00:31 by jecaudal          #+#    #+#             */
/*   Updated: 2020/11/27 16:53:25 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

t_list			*philo_gen(t_stock *s)
{
	t_list	*begin;
	t_list	*curr;
	t_list	*next;
	sem_t	*f;
	sem_t	*p;

	sem_unlink(NAME_SEM_FORKS);
	sem_unlink(NAME_SEM_PRINT);
	if ((f = sem_open(NAME_SEM_FORKS, O_CREAT, 0660, s->n_philo)) == SEM_FAILED)
		return (NULL);
	if ((p = sem_open(NAME_SEM_PRINT, O_CREAT, 0660, 1)) == SEM_FAILED)
		return (NULL);
	begin = lstnew(s, f, p, 1);
	curr = begin;
	while (curr->philo_pos < s->n_philo)
	{
		next = lstnew(s, f, p, curr->philo_pos + 1);
		curr->next = next;
		curr = curr->next;
	}
	curr->next = begin;
	return (begin);
}
