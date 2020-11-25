/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   l_memcpy_n.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jecaudal <jecaudal@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/20 16:22:24 by jecaudal          #+#    #+#             */
/*   Updated: 2020/01/08 14:26:23 by jecaudal         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** Copy n chars of s2 to s1 without nulling the string.
** Return ptr to the last case copied.
*/

void	*l_memcpy_n(void *s1, void *s2, unsigned int n)
{
	unsigned char *t_s1;
	unsigned char *t_s2;

	t_s1 = (unsigned char *)s1;
	t_s2 = (unsigned char *)s2;
	while (t_s1 - (unsigned char*)s1 < n)
	{
		*t_s1 = *t_s2;
		t_s1++;
		t_s2++;
	}
	return (t_s1);
}
