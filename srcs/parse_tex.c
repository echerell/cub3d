/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 11:08:21 by echerell          #+#    #+#             */
/*   Updated: 2022/04/29 11:09:01 by echerell         ###   ########.fr       */
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
	if (!ft_strncmp("NO", str, ft_strlen(str)))
		return (check_tex_err(NO, tex, tex_id));
	if (!ft_strncmp("SO", str, ft_strlen(str)))
		return (check_tex_err(SO, tex, tex_id));
	if (!ft_strncmp("WE", str, ft_strlen(str)))
		return (check_tex_err(WE, tex, tex_id));
	if (!ft_strncmp("EA", str, ft_strlen(str)))
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
