/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:43:38 by jecaudal          #+#    #+#             */
/*   Updated: 2020/11/25 14:06:09 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_usage(void)
{
	write(1, USAGE_P1, sizeof(USAGE_P1));
	write(1, USAGE_P2, sizeof(USAGE_P2));
	write(1, USAGE_P3, sizeof(USAGE_P3));
	write(1, USAGE_P4, sizeof(USAGE_P4));
	write(1, USAGE_P5, sizeof(USAGE_P5));
	write(1, USAGE_P6, sizeof(USAGE_P6));
	write(1, USAGE_P7, sizeof(USAGE_P7));
}

static char	*utoa_buff(unsigned int n, char *buff)
{
	char *temp;

	if (n == 0)
	{
		*buff = '0';
		return (buff);
	}
	temp = buff;
	while (n != 0)
	{
		*temp = (n % 10) + '0';
		n /= 10;
		temp++;
	}
	l_strrev(buff);
	return (buff);
}

static void	move_cursor(char **ptr)
{
	while (**ptr)
		(*ptr)++;
}

static int	l_numlen(int n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n /= 10;
		count++;
	}
	return (count);
}


void		print(t_uint time, t_uint n_philo, char *event)
{
	char	*temp;
	char	str[32];

	temp = str;
	memset(str, 0, 32);
	memset(temp, '.', 7 - l_numlen((int)time));
	move_cursor(&temp);
	utoa_buff(time, temp);
	move_cursor(&temp);
	*temp = ' ';
	temp++;
	utoa_buff(n_philo, temp);
	move_cursor(&temp);
	*temp = ' ';
	temp++;
	l_memcpy_n(temp, event, l_strlen(event));
	move_cursor(&temp);
	*temp = ' ';
	temp++;
	*temp = '\n';
	temp++;
	write(1, str, temp - str);
}
