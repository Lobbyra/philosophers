/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/26 15:23:32 by jecaudal          #+#    #+#             */
/*   Updated: 2020/12/01 16:05:45 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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
	sem_close(curr->print);
	free(curr);
	free(stock);
}

static int		philo_launch(t_list *philos, t_uint n_philo)
{
	t_uint		i;
	t_list		*curr;
	t_timeval	tt_start;

	i = 0;
	curr = philos;
	gettimeofday(&tt_start, NULL);
	while (curr->next && i < n_philo)
	{
		curr->tt_start = tt_start;
		if ((curr->pid = fork()) == 0)
		{
			curr->tt_starvation = get_curr_time() + curr->time_to_die * 1000;
			if (pthread_create(&curr->ripper, NULL, &ripper, curr))
				break ;
			philo_life(curr);
		}
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
	philo_monitor(stock, philos);
	destroy(stock, philos);
	return (0);
}
