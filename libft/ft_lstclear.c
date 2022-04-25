/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 23:52:21 by echerell          #+#    #+#             */
/*   Updated: 2021/05/06 20:48:37 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*begin;
	t_list	*current;

	if (del && lst && *lst)
	{
		begin = *lst;
		current = NULL;
		while (begin->next)
		{
			current = begin;
			begin = begin->next;
			ft_lstdelone(current, del);
		}
		ft_lstdelone(begin, del);
		*lst = NULL;
	}
}
