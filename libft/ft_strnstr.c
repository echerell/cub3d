/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 15:41:22 by echerell          #+#    #+#             */
/*   Updated: 2021/05/01 16:28:08 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strnstr(const char *big, const char *lit, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (!lit[0])
		return ((char *)(big));
	while (big[i] && i < len)
	{
		j = 0;
		while (big[i + j] == lit[j] && i + j < len && lit[j] && big[i + j])
			j++;
		if (!lit[j])
			return ((char *)(big + i));
		i++;
	}
	return (NULL);
}
