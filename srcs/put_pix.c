/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_pix.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:35:02 by echerell          #+#    #+#             */
/*   Updated: 2022/04/26 17:35:21 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	put_pix(t_world *world, int x, int y, int color)
{
	int	r;
	int	g;
	int	b;

	r = (color >> 16) & 0xFF;
	g = (color >> 8) & 0xFF;
	b = color & 0xFF;
	(world->mlx.img_addr)[x * 4 + world->mlx.line_len * y] = b;
	(world->mlx.img_addr)[x * 4 + world->mlx.line_len * y + 1] = g;
	(world->mlx.img_addr)[x * 4 + world->mlx.line_len * y + 2] = r;
	(world->mlx.img_addr)[x * 4 + world->mlx.line_len * y + 3] = 0;
}
