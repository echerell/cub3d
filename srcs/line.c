/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/26 17:31:17 by echerell          #+#    #+#             */
/*   Updated: 2022/04/26 19:57:48 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	tex_prep(t_world *world, int id)
{
	if (!world->side)
		world->wall_x = world->pos.y + world->dist.perp_dist * world->ray.y;
	else
		world->wall_x = world->pos.x + world->dist.perp_dist * world->ray.x;
	world->wall_x -= floor(world->wall_x);
	world->tex[id].t_x = (int)(world->wall_x * (double)world->tex[id].width);
	if (!world->side && world->ray.x > 0)
		world->tex[id].t_x = world->tex[id].width - world->tex[id].t_x - 1;
	if (world->side == 1 && world->ray.y < 0)
		world->tex[id].t_x = world->tex[id].width - world->tex[id].t_x - 1;
	world->tex[id].step = 1.0 * world->tex[id].height / world->line.height;
	world->tex[id].tex_pos = (world->line.start - WIN_HEIGHT / 2 + \
	world->line.height / 2) * world->tex[id].step;
}

void	put_line(t_world *world, int x)
{
	int	y;

	y = 0;
	tex_prep(world, world->t_side);
	while (y < world->line.start)
	{
		put_pix(world, x, y, RGB_CEIL);
		y++;
	}
	while (y >= world->line.start && y <= world->line.end)
	{
		put_tex(world, x, y, world->t_side);
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		put_pix(world, x, y, RGB_FLOOR);
		y++;
	}
}
