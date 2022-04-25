/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 17:02:05 by echerell          #+#    #+#             */
/*   Updated: 2021/05/06 20:55:43 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	unsigned int	rec;

	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		rec = (unsigned int)(-1 * n);
	}
	else
		rec = (unsigned int)n;
	if (rec >= 10)
	{
		ft_putnbr_fd(rec / 10, fd);
		ft_putchar_fd(rec % 10 + '0', fd);
	}
	else
		ft_putchar_fd(rec % 10 + '0', fd);
}
