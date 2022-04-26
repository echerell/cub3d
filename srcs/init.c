/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:49:58 by echerell          #+#    #+#             */
/*   Updated: 2022/04/26 19:50:25 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
#include <stdio.h>

static void	tex_to_img(t_world *world, int id, char *filename)
{
	world->tex[id].img_ptr = mlx_xpm_file_to_image(world->mlx.mlx_ptr, \
	filename, &(world->tex[id].width), &(world->tex[id].height));
	world->tex[id].img_addr = mlx_get_data_addr(world->tex[id].img_ptr, \
	&(world->tex[id].bpp), &(world->tex[id].line_len), &(world->tex[id].endi));
}

void	init(t_world *world)
{
	world->mlx.mlx_ptr = mlx_init();
	world->mlx.win_ptr = mlx_new_window(world->mlx.mlx_ptr, WIN_WIDTH, \
	WIN_HEIGHT, "Cub3d");
	world->mlx.img_ptr = mlx_new_image(world->mlx.mlx_ptr, WIN_WIDTH, \
	WIN_HEIGHT);
	world->mlx.img_addr = mlx_get_data_addr(world->mlx.img_ptr, \
	&world->mlx.bpp, &world->mlx.line_len, &world->mlx.endian);
	mlx_do_key_autorepeaton(world->mlx.mlx_ptr);
	tex_to_img(world, NO, "./textures/wood.xpm");
	tex_to_img(world, SO, "./textures/mossy.xpm");
	tex_to_img(world, WE, "./textures/redbrick.xpm");
	tex_to_img(world, EA, "./textures/stone.xpm");
	world->pos.x = 22;
	world->pos.y = 12;
	world->dir.x = 0;
	world->dir.y = 1;
	world->camera.plane_x = 0.66;
	world->camera.plane_y = 0;
	world->hit = 0;
	world->side = 0;
}
