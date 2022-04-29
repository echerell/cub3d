/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pos.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:29:04 by echerell          #+#    #+#             */
/*   Updated: 2022/04/29 21:33:30 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	dir_cam(t_world *world, double dir_y, double cam_x, double cam_y)
{
	world->dir.y = dir_y;
	world->camera.plane_x = cam_x;
	world->camera.plane_y = cam_y;
}

void	set_pos(char c, int x, int y, t_world *world)
{
	world->pos.x = x + 0.5;
	world->pos.y = y + 0.5;
	if (c == 'N')
	{
		world->dir.x = -1.0;
		dir_cam(world, 0.0, 0.0, 0.66);
	}
	else if (c == 'S')
	{
		world->dir.x = 1.0;
		dir_cam(world, 0.0, 0.0, -0.66);
	}
	else if (c == 'E')
	{
		world->dir.x = 0.0;
		dir_cam(world, 1.0, 0.66, 0.0);
	}
	else if (c == 'W')
	{
		world->dir.x = 0.0;
		dir_cam(world, -1.0, -0.66, 0.0);
	}
}
