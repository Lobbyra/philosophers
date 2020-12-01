/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:20:33 by jecaudal          #+#    #+#             */
/*   Updated: 2020/12/01 12:43:23 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

t_list	*lstnew(t_stock *s, sem_t *forks, sem_t *print, t_uint philo_pos)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	new->alive = TRUE;
	new->next = NULL;
	new->philo_pos = 1;
	new->n_philo = s->n_philo;
	new->time_to_eat = s->tt_eat;
	new->time_to_die = s->tt_die;
	new->time_to_sleep = s->tt_sleep;
	new->philo_pos = philo_pos;
	new->forks = forks;
	new->print = print;
	if (s->is_n_meals == TRUE)
		new->to_eat = s->n_meals;
	else
		new->to_eat = -1;
	return (new);
}

