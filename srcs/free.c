/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 21:38:38 by echerell          #+#    #+#             */
/*   Updated: 2022/04/23 21:51:54 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_world(t_world *world)
{
	if (world->mlx.mlx_ptr && world->mlx.img_ptr)
		mlx_destroy_image(world->mlx.mlx_ptr, world->mlx.img_ptr);
	world->mlx.img_ptr = NULL;
	world->mlx.img_addr = NULL;
	if (world->mlx.mlx_ptr && world->mlx.win_ptr)
		mlx_destroy_window(world->mlx.mlx_ptr, world->mlx.win_ptr);
	world->mlx.mlx_ptr = NULL;
	world->mlx.win_ptr = NULL;
}
