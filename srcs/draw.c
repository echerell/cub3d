/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/24 11:29:57 by echerell          #+#    #+#             */
/*   Updated: 2022/04/26 23:00:55 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


static void	make_delta(t_world *world, int x)
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
}

static void	move_ray(t_world *world)
{
	if (world->ray.x < 0)
	{
		world->map_step.step_x = -1;
		world->dist.side_x = (world->pos.x - world->map_step.x) \
		* world->dist.delta_x;
	}
	else
	{
		world->map_step.step_x = 1;
		world->dist.side_x = (world->map_step.x + 1.0 - world->pos.x) \
		* world->dist.delta_x;
	}
	if (world->ray.y < 0)
	{
		world->map_step.step_y = -1;
		world->dist.side_y = (world->pos.y - world->map_step.y) \
		* world->dist.delta_y;
	}
	else
	{
		world->map_step.step_y = 1;
		world->dist.side_y = (world->map_step.y + 1.0 - world->pos.y) \
		* world->dist.delta_y;
	}
}

static void	run_dda(t_world *world)
{
	while (!world->hit)
	{
		if (world->dist.side_x < world->dist.side_y)
		{
			world->dist.side_x += world->dist.delta_x;
			world->map_step.x += world->map_step.step_x;
			world->side = 0;
			if (world->ray.x > 0)
				world->t_side = EA;
			else
				world->t_side = WE;
		}
		else
		{
			world->dist.side_y += world->dist.delta_y;
			world->map_step.y += world->map_step.step_y;
			world->side = 1;
			if (world->ray.y > 0)
				world->t_side = NO;
			else
				world->t_side = SO;
		}
		if (worldMap[world->map_step.x][world->map_step.y] > 0)
			world->hit = 1;
	}
}

static void	set_height(t_world *world)
{
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
}

void	draw(t_world *world)
{
	int	x;

	if (world->mlx.img_ptr)
		ft_bzero(world->mlx.img_addr, WIN_WIDTH * WIN_HEIGHT * 4);
	x = 0;
	while (x < WIN_WIDTH)
	{
		make_delta(world, x);
		move_ray(world);
		run_dda(world);
		set_height(world);
		put_line(world, x);
		world->hit = 0;
		x++;
	}
	mlx_put_image_to_window(world->mlx.mlx_ptr, world->mlx.win_ptr, \
				world->mlx.img_ptr, 0, 0);
	mlx_hook(world->mlx.win_ptr, 2, 1L << 0, &key_event, world);
	mlx_hook(world->mlx.win_ptr, 17, 0L, &cross_close, world);
	mlx_hook(world->mlx.win_ptr, 25, 1L<<18, NULL, NULL);
	mlx_loop(world->mlx.mlx_ptr);
}
