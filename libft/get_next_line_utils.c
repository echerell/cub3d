/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/02 20:33:38 by echerell          #+#    #+#             */
/*   Updated: 2022/01/20 01:40:05 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	del_thread(t_thread **threads, t_thread *del)
{
	t_thread	*save;

	save = *threads;
	if (*threads != del)
	{
		while (save && save->next != del)
			save = save->next;
		save->next = del->next;
		free(del->strs);
		free(del);
	}
	else
	{
		*threads = del->next;
		free(del->strs);
		free(del);
	}
}

t_thread	*lstnew_fd(int fd, char *buf)
{
	t_thread	*new;

	new = (t_thread *)malloc(sizeof(t_thread));
	if (!new)
		return (NULL);
	new->fd = fd;
	new->strs = buf;
	new->next = NULL;
	return (new);
}

char	*mod_strjoin(char *s1, char *s2)
{
	int		len;
	int		temp;
	int		i;
	char	*str;

	len = 0;
	temp = 0;
	i = -1;
	while (s1 && s1[len])
		len++;
	while (s2 && s2[temp])
		temp++;
	len += temp;
	str = malloc((len + 1) * sizeof(char));
	if ((!s1 && !s2) || !str)
		return (NULL);
	temp = -1;
	while ((++temp + i + 1) < len && s1 && s1[temp])
		str[temp] = s1[temp];
	while ((temp + ++i) < len && s2 && s2[i])
		str[temp + i] = s2[i];
	str[temp + i] = '\0';
	free(s1);
	free(s2);
	return (str);
}

char	*mod_substr(char *s, unsigned int start, size_t len)
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

void	mod_bzero(void *ptr, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		*(unsigned char *)(ptr + i) = '\0';
		i++;
	}
}
