/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 16:07:04 by echerell          #+#    #+#             */
/*   Updated: 2021/05/04 20:07:22 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*cat;
	size_t	i;
	size_t	n2;

	i = 0;
	n2 = 0;
	if (!s1 || !s2)
		return (NULL);
	cat = (char *)malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!cat)
		return (NULL);
	while (s1[i])
	{
		cat[i] = s1[i];
		i++;
	}
	while (s2[n2])
	{
		cat[i] = s2[n2];
		i++;
		n2++;
	}
	cat[i] = '\0';
	return (cat);
}
