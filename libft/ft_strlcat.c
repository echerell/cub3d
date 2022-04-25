/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 00:09:46 by echerell          #+#    #+#             */
/*   Updated: 2021/05/01 15:39:58 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	len_d;
	size_t	d_i;
	size_t	s_i;

	len_d = ft_strlen(dst);
	if (size > 0 && len_d < size - 1)
	{
		d_i = len_d;
		s_i = 0;
		while (s_i < size - len_d - 1 && src[s_i])
		{
			dst[d_i] = src[s_i];
			d_i++;
			s_i++;
		}
		dst[d_i] = '\0';
	}
	if (len_d >= size)
		len_d = size;
	return (len_d + ft_strlen(src));
}
