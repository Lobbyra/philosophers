/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_strlen.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/25 14:03:54 by jecaudal          #+#    #+#             */
/*   Updated: 2020/11/25 14:03:57 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int		l_strlen(char *str)
{
	char *temp;

	temp = str;
	if (!str)
		return (0);
	while (*temp)
		temp++;
	return (temp - str);
}
