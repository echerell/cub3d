/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 19:25:53 by echerell          #+#    #+#             */
/*   Updated: 2022/04/30 00:11:06 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	main(int argc, char **argv)
{
	t_world	world;

	if (argc == 2 && check_file(argv[1]))
	{
		init(&world, argv[1]);
		draw(&world);
		free_world(&world);
		return (0);
	}
	printf("Error: Wrong number of arguments\nFormat: ./cub3d file.cub\n");
	return (1);
}
