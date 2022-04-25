/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 22:31:28 by echerell          #+#    #+#             */
/*   Updated: 2021/05/05 15:20:43 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>

int	ft_atoi(const char *nptr)
{
	int		i;
	long	n;
	long	sign;

	sign = 1;
	n = 0;
	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		n = (n * 10) + (nptr[i++] - '0');
		if (n < 0 && sign == 1)
			return (-1);
		if (n < 0 && sign == -1)
			return (0);
	}
	return ((int)(n * sign));
}
