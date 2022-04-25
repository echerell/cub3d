/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:29:57 by echerell          #+#    #+#             */
/*   Updated: 2022/04/24 21:37:49 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

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

void	put_line(t_world *world, int x)
{
	int	y;

	y = 0;
	while (y < world->line.start)
	{
		put_pix(world, x, y, RGB_CEIL);
		y++;
	}
	while (y >= world->line.start && y <= world->line.end)
	{
		put_pix(world, x, y, world->color);
		y++;
	}
	while (y < WIN_HEIGHT)
	{
		put_pix(world, x, y, RGB_FLOOR);
		y++;
	}
}

void	draw_world(t_world *world)
{
	int	x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		world->camera.move_x = 2 * x / (double)WIN_WIDTH - 1;
		world->ray.x = world->dir.x + world->camera.plane_x * world->camera.move_x;
		world->ray.y = world->dir.y + world->camera.plane_y * world->camera.move_x;

		world->map_step.x = (int)world->pos.x;
		world->map_step.y = (int)world->pos.y;
		if (!world->ray.x)
			world->dist.delta_x = 1e30;
		else
			world->dist.delta_x = fabs(1.0 / world->ray.x);
		if (!world->ray.y)
			world->dist.delta_y = 1e30;
		else
			world->dist.delta_y = fabs(1.0 / world->ray.y);
		if (world->ray.x < 0)
		{
			world->map_step.step_x = -1;
			world->dist.side_x = (world->pos.x - world->map_step.x) * world->dist.delta_x;
		}
		else
		{
			world->map_step.step_x = 1;
			world->dist.side_x = (world->map_step.x + 1.0 - world->pos.x) * world->dist.delta_x;
		}
		if (world->ray.y < 0)
		{
			world->map_step.step_y = -1;
			world->dist.side_y = (world->pos.y - world->map_step.y) * world->dist.delta_y;
		}
		else
		{
			world->map_step.step_y = 1;
			world->dist.side_y = (world->map_step.y + 1.0 - world->pos.y) * world->dist.delta_y;
		}

		while (!world->hit)
		{
			if (world->dist.side_x < world->dist.side_y)
			{
				world->dist.side_x += world->dist.delta_x;
				world->map_step.x += world->map_step.step_x;
				world->side = 0;
			}
			else
			{
				world->dist.side_y += world->dist.delta_y;
				world->map_step.y += world->map_step.step_y;
				world->side = 1;
			}
			if (worldMap[world->map_step.x][world->map_step.y] > 0)
				world->hit = 1;
		}
		if (!world->side)
			world->dist.perp_dist = (world->dist.side_x - world->dist.delta_x);
		else
			world->dist.perp_dist = (world->dist.side_y - world->dist.delta_y);

		world->line.height = (int)(WIN_HEIGHT / world->dist.perp_dist);
		world->line.start = -world->line.height / 2 + WIN_HEIGHT / 2;
		if (world->line.start < 0)
			world->line.start = 0;
		world->line.end = world->line.height / 2 + WIN_HEIGHT / 2;
		if (world->line.end >= WIN_HEIGHT)
			world->line.end = WIN_HEIGHT - 1;

		if (worldMap[world->map_step.x][world->map_step.y] == 1)
			world->color = RGB_1;
		else if (worldMap[world->map_step.x][world->map_step.y] == 2)
			world->color = RGB_2;
		else if (worldMap[world->map_step.x][world->map_step.y] == 3)
			world->color = RGB_3;
		else if (worldMap[world->map_step.x][world->map_step.y] == 4)
			world->color = RGB_4;
		else
			world->color = RGB_5;

		if (world->side == 1)
			world->color /= 2;
		put_line(world, x);
		world->hit = 0;
		x++;
	}
}

void	draw(t_world *world)
{
	if (world->mlx.img_ptr)
		ft_bzero(world->mlx.img_addr, WIN_WIDTH * WIN_HEIGHT * 4);
	draw_world(world);
	mlx_put_image_to_window(world->mlx.mlx_ptr, world->mlx.win_ptr, world->mlx.img_ptr, 0, 0);
	mlx_hook(world->mlx.win_ptr, 2, 1L << 0, &key_event, world);
	mlx_loop(world->mlx.mlx_ptr);
}
