/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:38:38 by echerell          #+#    #+#             */
/*   Updated: 2022/04/29 22:22:46 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	dest_img(void *mlx_ptr, void *img_ptr)
{
	if (mlx_ptr && img_ptr)
	{
		mlx_destroy_image(mlx_ptr, img_ptr);
		img_ptr = NULL;
	}
}

static void	free_map(t_world *world)
{
	int	i;

	i = 0;
	if (world->map)
	{
		while (i < world->map_height)
		{
			free(world->map[i]);
			i++;
		}
		free(world->map);
	}
}

void	free_world(t_world *world)
{
	free_map(world);
	dest_img(world->mlx.mlx_ptr, world->tex[NO].img_ptr);
	dest_img(world->mlx.mlx_ptr, world->tex[SO].img_ptr);
	dest_img(world->mlx.mlx_ptr, world->tex[WE].img_ptr);
	dest_img(world->mlx.mlx_ptr, world->tex[EA].img_ptr);
	if (world->mlx.mlx_ptr && world->mlx.img_ptr)
	{
		mlx_destroy_image(world->mlx.mlx_ptr, world->mlx.img_ptr);
		world->mlx.img_ptr = NULL;
		world->mlx.img_addr = NULL;
	}
	if (world->mlx.mlx_ptr && world->mlx.win_ptr)
	{
		mlx_destroy_window(world->mlx.mlx_ptr, world->mlx.win_ptr);
		world->mlx.win_ptr = NULL;
	}
	if (world->mlx.mlx_ptr)
	{
		mlx_destroy_display(world->mlx.mlx_ptr);
		free(world->mlx.mlx_ptr);
		world->mlx.mlx_ptr = NULL;
	}
}
