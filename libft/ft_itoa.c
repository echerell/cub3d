/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 00:42:31 by echerell          #+#    #+#             */
/*   Updated: 2022/01/20 23:38:19 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static	long	ft_make_tmp(int n)
{
	if (n < 0)
		return (-(long)n);
	return ((long)n);
}

static	int	ft_count_nbr(long tmp, size_t i)
{
	while (tmp >= 1)
	{
		i++;
		tmp /= 10;
	}
	return (i);
}

static	void	ft_make_str(char *str, long tmp, size_t i, int sign)
{
	while (i)
	{
		str[i--] = tmp % 10 + '0';
		tmp /= 10;
	}
	if (sign == -1)
		str[i] = '-';
	else
		str[i] = tmp % 10 + '0';
}

char	*ft_itoa(int n)
{
	char	*str;
	int		sign;
	long	tmp;
	size_t	i;

	i = 0;
	sign = 1;
	if (n < 0)
	{
		sign = -1;
		i++;
	}
	tmp = ft_make_tmp(n);
	i = ft_count_nbr(tmp, i);
	if (n == 0)
		i++;
	str = (char *)malloc((i + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[i--] = '\0';
	tmp = ft_make_tmp(n);
	ft_make_str(str, tmp, i, sign);
	return (str);
}
