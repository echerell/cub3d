/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:28:23 by echerell          #+#    #+#             */
/*   Updated: 2022/04/29 22:13:50 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	line_sym(char *str, int *p_set, int *i)
{
	while (str[*i] && str[*i] != '\n')
	{
		if (str[*i] != ' ' && str[*i] != '0' && str[*i] != '1' \
		&& str[*i] != 'N' && str[*i] != 'S' && str[*i] != 'W' && \
		str[*i] != 'E')
			return (1);
		if (str[*i] == 'N' || str[*i] == 'S' || \
			str[*i] == 'W' || str[*i] == 'E')
			(*p_set)++;
		(*i)++;
	}
	if (str[*i] == '\n' && str[*i - 1] == '\n')
		return (1);
	return (0);
}

int	check_map(char *str, int *p_set, t_world *world)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_strlenc(str, '\n');
	if (len == 0)
		return (1);
	while (str[i])
	{
		if (line_sym(str, p_set, &i))
			return (1);
		if (str[i] == '\n')
		{
			if (world->map_width < i / len)
				world->map_width = i;
			i++;
			j++;
		}
	}
	world->map_height = j + 1;
	return (0);
}

static int	cor_around(int i, int j, int **map, t_world *world)
{
	if (i == 0 || i == world->map_height - 1)
	{
		if (map[i][j] != -1 && map[i][j] != 1)
		{
			raise_error(MAP_WALL);
			return (1);
		}
	}
	else if (map[i][j] == 0)
	{
		if (look_around(map, i, j, world->map_width))
		{
			raise_error(MAP_WALL);
			return (1);
		}
	}
	return (0);
}

void	check_wall(int	**map, t_world *world, t_parse *parse)
{
	int	i;
	int	j;

	i = 0;
	while (i < world->map_height && !parse->err)
	{
		j = 0;
		while (j < world->map_width && !parse->err)
		{
			parse->err = cor_around(i, j, map, world);
			j++;
		}
		i++;
	}
}

void	check_pos(int **map, t_world *world, t_parse *parse)
{
	if (!parse->err)
	{
		if (world->pos.x == 0.5 || world->pos.x == world->map_height - 0.5)
		{
			raise_error(WRG_POS);
			parse->err = 1;
		}
		else if (look_around(map, (int)(world->pos.x - 0.5), \
		(int)(world->pos.y - 0.5), world->map_width))
		{
			raise_error(WRG_POS);
			parse->err = 1;
		}
	}
}
