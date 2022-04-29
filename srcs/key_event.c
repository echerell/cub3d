/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:38:26 by echerell          #+#    #+#             */
/*   Updated: 2022/04/29 18:53:37 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static void	rotate(t_world *world, double angle)
{
	double	old_dir_x;
	double	old_move_x;

	old_dir_x = world->dir.x;
	world->dir.x = world->dir.x * cos(angle) - world->dir.y * sin(angle);
	world->dir.y = old_dir_x * sin(angle) + world->dir.y * cos(angle);
	old_move_x = world->camera.plane_x;
	world->camera.plane_x = world->camera.plane_x * cos(angle) - \
	world->camera.plane_y * sin(angle);
	world->camera.plane_y = old_move_x * sin(angle) + \
	world->camera.plane_y * cos(angle);
}

static void	move(t_world *world, int keycode, double speed)
{
	int		val;

	if (keycode == KEY_W || keycode == KEY_S)
	{
		val = (int)(world->pos.x + world->dir.x * speed);
		if (world->map[val][(int)world->pos.y] == 0)
			world->pos.x += world->dir.x * speed;
		val = (int)(world->pos.y + world->dir.y * speed);
		if (world->map[(int)world->pos.x][val] == 0)
			world->pos.y += world->dir.y * speed;
	}
	else if (keycode == KEY_A || keycode == KEY_D)
	{
		val = (int)(world->pos.x + world->camera.plane_x * speed);
		if (world->map[val][(int)world->pos.y] == 0)
			world->pos.x += world->camera.plane_x * speed;
		val = (int)(world->pos.y + world->camera.plane_y * speed);
		if (world->map[(int)world->pos.x][val] == 0)
			world->pos.y += world->camera.plane_y * speed;
	}
}

int	key_event(int keycode, void *param)
{
	if (keycode == KEY_ESC)
	{
		free_world(param);
		exit(EXIT_SUCCESS);
	}
	else if (keycode == KEY_W || keycode == KEY_D)
		move(param, keycode, 0.3);
	else if (keycode == KEY_S || keycode == KEY_A)
		move(param, keycode, -0.3);
	else if (keycode == KEY_ARR_RIGHT)
		rotate(param, -0.1);
	else if (keycode == KEY_ARR_LEFT)
		rotate(param, 0.1);
	if (keycode == KEY_W || keycode == KEY_D || keycode == KEY_S || \
	keycode == KEY_A || keycode == KEY_ARR_LEFT || keycode == KEY_ARR_RIGHT)
		draw(param);
	return (1);
}
