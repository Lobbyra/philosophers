/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 12:19:28 by jecaudal          #+#    #+#             */
/*   Updated: 2020/11/26 15:06:54 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_two.h"

static int		panic_main(t_stock *stock)
{
	free(stock);
	return (1);
}

static void		destroy(t_stock *stock, t_list *philos)
{
	t_list	*curr;
	t_list	*prev;

	curr = philos;
	while (curr->philo_pos != stock->n_philo)
	{
		prev = curr;
		curr = prev->next;
		free(prev);
	}
	sem_close(curr->forks);
	free(curr);
	free(stock);
}

static int		philo_launch(t_list *philos, t_uint n_philo)
{
	t_uint i;
	t_list *curr;

	i = 0;
	curr = philos;
	while (curr->next && i < n_philo)
	{
		gettimeofday(&(curr->tt_start), NULL);
		curr->tt_starvation = get_curr_time() + philos->time_to_die * 1000;
		if (pthread_create(&philos->th, NULL, &philo_life, curr))
			break ;
		curr = curr->next;
		i++;
	}
	return (0);
}

int				main(int argc, char **argv)
{
	t_stock	*stock;
	t_list	*philos;

	if (!(stock = parsing(argc - 1, argv + 1)))
		return (1);
	if (!(philos = philo_gen(stock)))
		return (panic_main(stock));
	if (philo_launch(philos, stock->n_philo))
		return (panic_main(stock));
	philo_monitor(stock, philos, philos);
	destroy(stock, philos);
	return (0);
}
