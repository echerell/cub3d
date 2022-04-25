/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:05:41 by echerell          #+#    #+#             */
/*   Updated: 2021/05/01 17:00:30 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*sub;
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	sub = (char *)malloc(len * sizeof(char) + 1);
	if (!s || !sub)
		return (NULL);
	while (s[i])
	{
		if (i >= start && k < len)
		{
			sub[k] = s[i];
			k++;
		}
		i++;
	}
	sub[k] = '\0';
	return (sub);
}
