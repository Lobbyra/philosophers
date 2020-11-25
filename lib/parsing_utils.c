/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 16:36:25 by jecaudal          #+#    #+#             */
/*   Updated: 2020/11/24 11:14:24 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_bool	is_num(char *str)
{
	if (str)
	{
		while (*str)
		{
			if (!(*str >= '0' && *str <= '9'))
				return (FALSE);
			str++;
		}
	}
	return (TRUE);
}

void	*parsing_panic(void *args, char *msg)
{
	write(1, msg, l_strlen(msg));
	if (l_strcmp(ERR_MISS_ARG, msg) == 0 || l_strcmp(ERR_MUCH_ARG, msg) == 0)
		print_usage();
	if (args)
		free(args);
	return (NULL);
}

void	print_warnings(int *args)
{
	if (args[N_PHILO] > 200)
		write(1, WARN_N_PHILO, l_strlen(WARN_N_PHILO));
	if (args[TT_DIE] < 60 || args[TT_EAT] < 60 || args[TT_SLEEP] < 60)
		write(1, WARN_DELA, l_strlen(WARN_DELA));
}
