/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 20:22:59 by echerell          #+#    #+#             */
/*   Updated: 2022/04/30 00:11:24 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	cross_close(void *param)
{
	free_world(param);
	exit(EXIT_SUCCESS);
	return (1);
}
