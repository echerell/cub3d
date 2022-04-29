/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:49:58 by echerell          #+#    #+#             */
/*   Updated: 2022/04/29 22:15:22 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	img_init(t_world *world)
{
	world->mlx.win_ptr = NULL;
	world->mlx.img_ptr = NULL;
	world->tex[NO].img_ptr = NULL;
	world->tex[SO].img_ptr = NULL;
	world->tex[WE].img_ptr = NULL;
	world->tex[EA].img_ptr = NULL;
	world->f_col = 0;
	world->c_col = 0;
	world->map_width = 0;
	world->map_height = 0;
	world->map = NULL;
}

void	init(t_world *world, char *filename)
{
	world->mlx.mlx_ptr = mlx_init();
	if (!world->mlx.mlx_ptr)
	{
		raise_error(MLX_FAIL);
		exit(EXIT_FAILURE);
	}
	img_init(world);
	parse_file(filename, world);
	world->mlx.win_ptr = mlx_new_window(world->mlx.mlx_ptr, WIN_WIDTH, \
	WIN_HEIGHT, "Cub3d");
	world->mlx.img_ptr = mlx_new_image(world->mlx.mlx_ptr, WIN_WIDTH, \
	WIN_HEIGHT);
	world->mlx.img_addr = mlx_get_data_addr(world->mlx.img_ptr, \
	&world->mlx.bpp, &world->mlx.line_len, &world->mlx.endian);
	mlx_do_key_autorepeaton(world->mlx.mlx_ptr);
	world->hit = 0;
	world->side = 0;
}
