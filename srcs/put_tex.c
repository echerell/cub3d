/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_tex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:33:32 by echerell          #+#    #+#             */
/*   Updated: 2022/04/26 19:45:50 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	get_tex(t_tex *tex)
{
	int	a;
	int	r;
	int	g;
	int	b;

	a = 0;
	r = tex->img_addr[tex->t_x * 4 + tex->line_len * tex->t_y + 2];
	g = tex->img_addr[tex->t_x * 4 + tex->line_len * tex->t_y + 1];
	b = tex->img_addr[tex->t_x * 4 + tex->line_len * tex->t_y];
	return (a << 24 | r << 16 | g << 8 | b);
}

void	put_tex(t_world *world, int x, int y, int id)
{
	int	color;

	world->tex[id].t_y = (int)world->tex[id].tex_pos & \
	(world->tex[id].height - 1);
	world->tex[id].tex_pos += world->tex[id].step;
	color = get_tex(&(world->tex[id]));
	if (world->side == 1)
		color = (color >> 1) & 0x7F7F7F;
	put_pix(world, x, y, color);
}
