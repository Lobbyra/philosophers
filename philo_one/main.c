/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 11:13:02 by jecaudal          #+#    #+#             */
/*   Updated: 2020/11/25 18:56:57 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_one.h"

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
		pthread_mutex_destroy(prev->fork1);
		free(prev);
	}
	pthread_mutex_destroy(curr->fork1);
	free(curr);
	free(philos->fork2);
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
		philos->tt_starvation = get_curr_time() + philos->time_to_die * 1000;
		// printf("%u\n", philos->tt_starvation);
		if (pthread_create(&philos->th, NULL, &philo_life, curr))
			break ;
		curr = curr->next;
		i++;
	}
	return (0);
}

static void		philo_monitor(t_stock *s, t_list *p, t_list *begin)
{
	t_bool	die;
	t_uchar n_ate;
	t_uchar n_philos;

	n_ate = 0;
	n_philos = s->n_philo;
	if (p->to_eat > 0)
		while (n_ate < n_philos && (die = (get_curr_time() < p->tt_starvation)))
		{
			if (p->to_eat == 0)
				n_ate++;
			else
				n_ate = 0;
			p = p->next;
		}
	else
		while ((die = (get_curr_time() < p->tt_starvation)))
		{
			p = p->next;
		}
	// printf("%p\n", p);
	// printf("%u, %u\n", get_curr_time(), p->tt_starvation);
	if (die == FALSE)
		print(get_time(p->tt_start) / 1000, p->philo_pos, EVENT_DIED);
	while (begin->philo_pos != n_philos)
	{
		begin->alive = FALSE;
		begin = begin->next;
	}
	begin->alive = FALSE;
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
