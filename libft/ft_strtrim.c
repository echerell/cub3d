/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/23 13:37:52 by echerell          #+#    #+#             */
/*   Updated: 2021/05/04 21:03:19 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_check_c(char c, char const *set)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (c == set[i])
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*trim;
	size_t	start;
	size_t	k;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && set && ft_check_c(s1[start], set))
		start++;
	end = ft_strlen(s1);
	while (end > start && set && ft_check_c(s1[end - 1], set))
		end--;
	trim = (char *)malloc((end - start + 1) * sizeof(char));
	if (!trim)
		return (NULL);
	k = 0;
	while (start < end)
	{
		trim[k] = s1[start];
		k++;
		start++;
	}
	trim[k] = '\0';
	return (trim);
}
