/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:57:01 by jecaudal          #+#    #+#             */
/*   Updated: 2020/12/02 10:41:44 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

t_list	*lstnew(t_stock *s, sem_t *forks, t_uint philo_pos)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->alive = 1;
	new->next = NULL;
	new->philo_pos = 1;
	new->n_philo = s->n_philo;
	new->time_to_eat = s->tt_eat;
	new->time_to_die = s->tt_die;
	new->time_to_sleep = s->tt_sleep;
	new->philo_pos = philo_pos;
	new->forks = forks;
	if (s->is_n_meals == TRUE)
		new->to_eat = s->n_meals;
	else
		new->to_eat = -1;
	return (new);
}
