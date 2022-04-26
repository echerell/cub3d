/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:38:38 by echerell          #+#    #+#             */
/*   Updated: 2022/04/26 18:13:29 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void dest_img(void *mlx_ptr, void *img_ptr)
{
	if (mlx_ptr && img_ptr)
		mlx_destroy_image(mlx_ptr, img_ptr);
}

void	free_world(t_world *world)
{
	dest_img(world->mlx.mlx_ptr, world->tex[NO].img_ptr);
	dest_img(world->mlx.mlx_ptr, world->tex[SO].img_ptr);
	dest_img(world->mlx.mlx_ptr, world->tex[WE].img_ptr);
	dest_img(world->mlx.mlx_ptr, world->tex[EA].img_ptr);
	if (world->mlx.mlx_ptr && world->mlx.img_ptr)
		mlx_destroy_image(world->mlx.mlx_ptr, world->mlx.img_ptr);
	world->mlx.img_ptr = NULL;
	world->mlx.img_addr = NULL;
	if (world->mlx.mlx_ptr && world->mlx.win_ptr)
		mlx_destroy_window(world->mlx.mlx_ptr, world->mlx.win_ptr);
	world->mlx.mlx_ptr = NULL;
	world->mlx.win_ptr = NULL;
}
