/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:30:24 by echerell          #+#    #+#             */
/*   Updated: 2022/04/29 22:28:34 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	check_fc_err(int id, int *fc, int *fc_id)
{
	if (fc[id] == 1)
	{
		raise_error(DOUB_FC);
		return (0);
	}
	fc[id] = 1;
	*fc_id = id;
	return (1);
}

static int	check_fc(char *str, int *fc, int *fc_id)
{
	if (!ft_strncmp("F", str, ft_strlen(str)))
		return (check_fc_err(F, fc, fc_id));
	else if (!ft_strncmp("C", str, ft_strlen(str)))
		return (check_fc_err(C, fc, fc_id));
	return (0);
}

static void	info_check2(char **strs, t_world *world, t_parse *parse)
{
	if (mat_size(strs) == 2)
	{
		add_fc_color(strs[1], world, parse);
		if (world->f_col == -1 || world->c_col == -1)
			parse->err = 1;
	}
	else
	{
		raise_error(FC_ARG);
		parse->err = 1;
	}
}

static void	info_check(char **strs, t_world *world, t_parse *parse)
{
	if (check_tex_type(strs[0], parse->tex, &(parse->tex_id)))
	{
		if (mat_size(strs) == 2)
			add_tex(strs[1], world, parse->tex_id, parse);
		else
		{
			raise_error(TEX_ARG);
			parse->err = 1;
		}
	}
	else if (check_fc(strs[0], parse->fc, &(parse->fc_id)))
		info_check2(strs, world, parse);
	else
		parse->err = 1;
}

void	handle_info(char *line, t_parse *parse, t_world *world)
{
	char	*trim;
	char	**strs;

	trim = ft_strtrim(line, " ");
	if (trim && *trim)
	{
		strs = ft_split(trim, ' ');
		info_check(strs, world, parse);
		free_mat(strs);
	}
	if (trim)
		free(trim);
}
