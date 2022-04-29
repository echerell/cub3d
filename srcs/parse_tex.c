/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:08:21 by echerell          #+#    #+#             */
/*   Updated: 2022/04/29 23:22:43 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_tex_err(int id, int *tex, int *tex_id)
{
	if (tex[id] == 1)
	{
		raise_error(DOUB_TEX);
		return (0);
	}
	tex[id] = 1;
	*tex_id = id;
	return (1);
}

int	check_tex_type(const char *str, int *tex, int *tex_id)
{
	int	i;

	i = 0;
	if (str[i] == 'N' && str[i+1] == 'O' && ft_strlen(str) == 2)
		return (check_tex_err(NO, tex, tex_id));
	if (str[i] == 'S' && str[i+1] == 'O' && ft_strlen(str) == 2)
		return (check_tex_err(SO, tex, tex_id));
	if (str[i] == 'W' && str[i+1] == 'E' && ft_strlen(str) == 2)
		return (check_tex_err(WE, tex, tex_id));
	if (str[i] == 'E' && str[i+1] == 'A' && ft_strlen(str) == 2)
		return (check_tex_err(EA, tex, tex_id));
	return (0);
}

void	add_tex(char *file, t_world *world, int id, t_parse *parse)
{
	world->tex[id].img_ptr = mlx_xpm_file_to_image(world->mlx.mlx_ptr, file, \
	&(world->tex[id].width), &(world->tex[id].height));
	if (!world->tex[id].img_ptr)
	{
		raise_error(TEX_FAIL);
		parse->err = 1;
	}
	else
		world->tex[id].img_addr = mlx_get_data_addr(world->tex[id].img_ptr, \
		&(world->tex[id].bpp), &(world->tex[id].line_len), \
		&(world->tex[id].endi));
}
