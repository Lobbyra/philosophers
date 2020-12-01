/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_sem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 15:43:38 by jecaudal          #+#    #+#             */
/*   Updated: 2020/12/01 16:00:55 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_three.h"

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


void		print_sem(t_uint time, t_list *philo, char *event)
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
	utoa_buff(philo->philo_pos, temp);
	move_cursor(&temp);
	*temp = ' ';
	temp++;
	l_memcpy_n(temp, event, l_strlen(event));
	move_cursor(&temp);
	*temp = ' ';
	temp++;
	*temp = '\n';
	temp++;
	sem_wait(philo->print);
	write(1, str, temp - str);
	sem_post(philo->print);
}
