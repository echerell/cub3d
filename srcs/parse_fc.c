/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_fc.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 12:32:41 by echerell          #+#    #+#             */
/*   Updated: 2022/04/29 22:28:21 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	count_comma(char *str)
{
	int	i;
	int	n;

	i = 0;
	n = 0;
	while (str[i])
	{
		if (str[i] == ',')
			n++;
		i++;
	}
	return (n);
}

static int	check_rgb(char **col_args, int i, int rgb[3])
{
	if (check_num(col_args[i]))
	{
		raise_error(FC_ARG);
		free_mat(col_args);
		return (-1);
	}
	rgb[i] = ft_atoi(col_args[i]);
	if (rgb[i] < 0 || rgb[i] > 255)
	{
		raise_error(FC_RGB);
		free_mat(col_args);
		return (-1);
	}
	return (0);
}

static int	make_color(char *str)
{
	int		rgb[3];
	char	**col_args;
	int		i;

	rgb[0] = -1;
	rgb[1] = -1;
	rgb[2] = -1;
	i = 0;
	col_args = ft_split(str, ',');
	if (mat_size(col_args) != 3 || count_comma(str) != 2)
	{
		raise_error(FC_ARG);
		free_mat(col_args);
		return (-1);
	}
	while (col_args[i])
	{
		if (check_rgb(col_args, i, rgb) == -1)
			return (-1);
		i++;
	}
	free_mat(col_args);
	i = 0;
	return (i << 24 | rgb[0] << 16 | rgb[1] << 8 | rgb[2]);
}

void	add_fc_color(char *str, t_world *world, t_parse *parse)
{
	if (parse->fc_id == F)
		world->f_col = make_color(str);
	else if (parse->fc_id == C)
		world->c_col = make_color(str);
}
