/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 21:06:01 by echerell          #+#    #+#             */
/*   Updated: 2021/06/23 16:45:57 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_count_str(char const *s, char c)
{
	size_t	start;
	size_t	end;
	size_t	n;

	start = 0;
	n = 0;
	while (s[start] && s[start] == c)
		start++;
	end = ft_strlen(s);
	while (end > start && s[end - 1] == c)
		end--;
	while (start < end)
	{
		while (s[start] != c && start < end)
			start++;
		if (s[start] == c && start < end)
		{
			while (s[start] == c && start < end)
				start++;
			n++;
		}
	}
	return (n);
}

static	size_t	ft_make_str(char *str, char const *s, size_t k, char c)
{
	size_t	j;

	j = 0;
	while (s[k] != c && s[k])
	{
		str[j] = s[k];
		j++;
		k++;
	}
	while (s[k] == c && s[k])
		k++;
	str[j] = '\0';
	return (k);
}

static	void	ft_free_all(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
	{
		if (!strs[i])
			free(strs[i]);
		i++;
	}
	free(strs);
}

static	char	**ft_check_zero(char const *s)
{
	char	**strs;

	if (!s)
		return (NULL);
	else
	{
		strs = (char **)malloc(sizeof(char *));
		strs[0] = NULL;
	}
	return (strs);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	k;
	char	**strs;

	if (!s || s[0] == '\0')
		return (ft_check_zero(s));
	strs = (char **)malloc((ft_count_str(s, c) + 2) * sizeof(char *));
	if (!strs)
		return (NULL);
	strs[ft_count_str(s, c) + 1] = NULL;
	i = 0;
	k = 0;
	while (s[k] == c && s[k])
		k++;
	while (i < ft_count_str(s, c) + 1)
	{
		strs[i] = (char *)malloc((ft_strlenc(s + k, c) + 1) * sizeof(char));
		if (!strs[i])
		{
			ft_free_all(strs);
			return (NULL);
		}
		k = ft_make_str(strs[i++], s, k, c);
	}
	return (strs);
}
