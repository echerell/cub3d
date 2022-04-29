/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 21:25:11 by echerell          #+#    #+#             */
/*   Updated: 2022/04/29 22:18:18 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static int	map_pos(char *map, t_parse *parse, t_world *world)
{
	if (check_map(map, &(parse->p_set), world))
	{
		raise_error(MAP_SYM);
		free(map);
		return (1);
	}
	if (parse->p_set != 1)
	{
		raise_error(PLAYER_POS);
		free(map);
		return (1);
	}
	return (0);
}

static void	fill_map(int i[3], char *map, int **imap, t_world *world)
{
	if (map[i[2]] && map[i[2]] != '\n')
	{
		if (map[i[2]] == ' ')
			imap[i[0]][i[1]] = -1;
		else if (map[i[2]] == '0')
			imap[i[0]][i[1]] = 0;
		else if (map[i[2]] == '1')
			imap[i[0]][i[1]] = 1;
		else if (ft_isalpha(map[i[2]]))
		{
			set_pos(map[i[2]], i[0], i[1], world);
			imap[i[0]][i[1]] = 0;
		}
		i[2]++;
	}
	else if (map[i[2]] == '\n' || !map[i[2]])
		imap[i[0]][i[1]] = -1;
	i[1]++;
}

static int	**make_mat(char *map, t_parse *parse, t_world *world)
{
	int	i[3];
	int	**imap;

	parse->p_set = 0;
	if (map_pos(map, parse, world))
		return (NULL);
	imap = (int **)malloc((world->map_height) * sizeof(int *));
	i[0] = 0;
	i[2] = 0;
	while (i[0] < world->map_height && !parse->err)
	{
		i[1] = 0;
		imap[i[0]] = (int *)malloc(world->map_width * sizeof(int));
		while (i[1] < world->map_width && !parse->err)
			fill_map(i, map, imap, world);
		i[0]++;
		i[2]++;
	}
	free(map);
	check_pos(imap, world, parse);
	check_wall(imap, world, parse);
	return (imap);
}

static int	check_save(char *line, char *save)
{
	if (!ft_strlen(save))
	{
		raise_error(NO_MAP);
		free(save);
		free(line);
		return (1);
	}
	return (0);
}

int	**make_map(char *line, t_parse *parse, t_world *world)
{
	char	*save;
	char	*map;

	map = "";
	while (get_next_line(parse->fd, &line) > 0)
	{
		save = ft_strjoin(map, line);
		if (*map)
			free(map);
		map = ft_strjoin(save, "\n");
		free(save);
		free(line);
	}
	save = ft_strtrim(map, "\n");
	if (*map)
		free(map);
	if (check_save(line, save))
		return (NULL);
	free(line);
	line = NULL;
	return (make_mat(save, parse, world));
}
