/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 23:09:59 by echerell          #+#    #+#             */
/*   Updated: 2021/05/06 20:48:56 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*begin;

	if (new)
	{
		begin = NULL;
		if (*lst && lst)
		{
			begin = *lst;
			while (begin->next)
				begin = begin->next;
			begin->next = new;
			new->next = NULL;
		}
		else
		{
			*lst = new;
			new->next = NULL;
		}
	}
}
