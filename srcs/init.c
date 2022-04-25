/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:49:58 by echerell          #+#    #+#             */
/*   Updated: 2022/04/24 23:28:02 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	init(t_world *world)
{
	world->mlx.mlx_ptr = mlx_init();
	world->mlx.win_ptr = mlx_new_window(world->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "Cub3d");
	world->mlx.img_ptr = mlx_new_image(world->mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	world->mlx.img_addr = mlx_get_data_addr(world->mlx.img_ptr, &world->mlx.bpp, &world->mlx.line_len, &world->mlx.endian);
	mlx_do_key_autorepeaton(world->mlx.mlx_ptr);
	world->pos.x = 22;
	world->pos.y = 12;
	world->dir.x = -1;
	world->dir.y = 0;
	world->camera.plane_x = 0;
	world->camera.plane_y = 0.66;
	world->hit = 0;
	world->side = 0;
}
