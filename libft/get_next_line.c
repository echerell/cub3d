/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 00:13:38 by echerell          #+#    #+#             */
/*   Updated: 2022/01/20 01:40:43 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_line(t_thread *thread, char **line, int i)
{
	char	*offset;

	while (1)
	{
		i = 0;
		while (thread->strs[i] != '\n' && thread->strs[i])
			i++;
		*line = mod_strjoin(*line, mod_substr(thread->strs, 0, i));
		if (!(*line))
			return (-1);
		if (thread->strs[i] == '\n')
		{
			offset = mod_substr(thread->strs, i + 1, BUFFER_SIZE);
			if (!offset)
				return (-1);
			free(thread->strs);
			thread->strs = offset;
			return (1);
		}
		mod_bzero(thread->strs, BUFFER_SIZE + 1);
		if (!read(thread->fd, thread->strs, BUFFER_SIZE))
			return (0);
	}
}

static int	first_read(t_thread **thread, int fd, char *buf)
{
	int	read_ret;

	read_ret = read(fd, buf, BUFFER_SIZE);
	if (read_ret <= 0)
	{
		free(buf);
		return (read_ret);
	}
	buf[read_ret] = '\0';
	*thread = lstnew_fd(fd, buf);
	if (!thread)
	{
		free(buf);
		return (-1);
	}
	return (1);
}

static int	goto_fd(t_thread **threads, t_thread *save, int fd, char *buf)
{
	save = *threads;
	if (!(*threads))
		return (first_read(threads, fd, buf));
	while (save->next && save->fd != fd)
		save = save->next;
	if (save->fd == fd)
	{
		free(buf);
		return (1);
	}
	return (first_read(&save->next, fd, buf));
}

static int	lesszero_ret(char **line, int ret)
{
	if (ret < 0)
		return (-1);
	*line = malloc(sizeof(char));
	if (!*line)
		return (-1);
	line[0][0] = '\0';
	return (0);
}

int	get_next_line(int fd, char **line)
{
	static t_thread	*threads;
	t_thread		*save;
	int				ret;
	char			*buf;

	buf = malloc((BUFFER_SIZE + 1) * (sizeof(char)));
	if (BUFFER_SIZE < 1 || fd < 0 || !line || !buf)
	{
		if (buf)
			free(buf);
		return (-1);
	}
	save = NULL;
	ret = goto_fd(&threads, save, fd, buf);
	if (ret <= 0)
		return (lesszero_ret(line, ret));
	*line = NULL;
	save = threads;
	while (save && save->fd != fd)
		save = save->next;
	ret = get_line(save, line, 0);
	if (ret < 1)
		del_thread(&threads, save);
	return (ret);
}
