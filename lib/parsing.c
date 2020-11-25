/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/11 17:43:09 by jecaudal          #+#    #+#             */
/*   Updated: 2020/11/25 12:14:42 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int		*parsing_data(int *args, t_stock *stock)
{
	if (args[N_PHILO] < 1 || args[N_PHILO] > 255)
		return (parsing_panic(args, ERR_N_PHILO));
	if (args[TT_DIE] < 1)
		return (parsing_panic(args, ERR_TT_DIE));
	if (args[TT_EAT] < 1)
		return (parsing_panic(args, ERR_TT_EAT));
	if (args[TT_SLEEP] < 1)
		return (parsing_panic(args, ERR_TT_SLEEP));
	if (stock->is_n_meals == TRUE && args[N_MEALS] < 1)
		return (parsing_panic(args, ERR_N_DISH));
	print_warnings(args);
	return (args);
}

static int		*data_miner(char **argv, int is_n_meals)
{
	int		*new;
	char	**max;
	char	**temp;

	temp = argv;
	max = argv + 4 + is_n_meals;
	if (!(new = (int*)malloc(sizeof(int) * 5)))
		return (NULL);
	while (*temp && temp < max)
	{
		new[temp - argv] = l_atoi(*temp);
		temp++;
	}
	if (!(*temp) && temp < max)
		return (parsing_panic(new, ERR_MISS_ARG));
	else if (*temp && temp == max)
		return (parsing_panic(new, ERR_MUCH_ARG));
	return (new);
}

static t_stock	*data_inserter(char **argv, t_stock *stock)
{
	int	*datas;

	if (!(datas = data_miner(argv, stock->is_n_meals)))
		return (parsing_panic(stock, ""));
	if (!(datas = parsing_data(datas, stock)))
		return (parsing_panic(stock, ""));
	stock->n_philo = datas[N_PHILO];
	stock->tt_die = datas[TT_DIE];
	stock->tt_eat = datas[TT_EAT];
	stock->tt_sleep = datas[TT_SLEEP];
	if (stock->is_n_meals == TRUE)
		stock->n_meals = datas[N_MEALS];
	else
		stock->n_meals = 2000000;
	free(datas);
	return (stock);
}

static int		check_strnum(char **argv)
{
	while (*argv)
	{
		if (is_num(*argv) == FALSE)
			return (1);
		argv++;
	}
	return (0);
}

t_stock			*parsing(int argc, char **argv)
{
	t_stock	*stock;

	if (!argv || !(*argv))
		return (parsing_panic(NULL, ERR_MISS_ARG));
	if (!(stock = (t_stock*)malloc(sizeof(t_stock))))
		return (NULL);
	if (argc == 5)
		stock->is_n_meals = TRUE;
	else
		stock->is_n_meals = FALSE;
	if (check_strnum(argv) != 0)
		return (parsing_panic(stock, ERR_NON_NUM_ARG));
	if (data_inserter(argv, stock) == NULL)
		return (NULL);
	return (stock);
}
