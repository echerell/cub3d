/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/01 00:07:44 by echerell          #+#    #+#             */
/*   Updated: 2022/01/20 01:40:20 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 64

# include <stdlib.h>
# include <unistd.h>

typedef struct s_thread
{
	int				fd;
	char			*strs;
	struct s_thread	*next;
}	t_thread;

int			get_next_line(int fd, char **line);
void		del_thread(t_thread **threads, t_thread *del);

t_thread	*lstnew_fd(int fd, char *buf);
char		*mod_strjoin(char *s1, char *s2);
char		*mod_substr(char *s, unsigned int start, size_t len);
void		mod_bzero(void *ptr, size_t n);

#endif
