/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_atoi.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/08 12:08:27 by jecaudal          #+#    #+#             */
/*   Updated: 2020/11/25 14:07:02 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		l_atoi(char *str)
{
	unsigned int i;
	unsigned int nb;
	unsigned int neg;

	i = 0;
	nb = 0;
	neg = 0;
	if (!str)
		return (0);
	while (l_isspace(str[i]) == TRUE)
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg++;
	while (l_isnum(str[i]) == TRUE)
	{
		nb = nb * 10 + (str[i] - '0');
		i++;
	}
	if (neg % 2 == 1)
		return (nb * (-1));
	else
		return (nb);
}
