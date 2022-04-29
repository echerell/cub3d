/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 11:38:47 by echerell          #+#    #+#             */
/*   Updated: 2022/04/29 22:21:54 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_file(char *str)
{
	char	*dot;

	dot = ft_strchr(str, '.');
	if (dot && *dot && !ft_strncmp(".cub", dot, 4) && ft_strlen(dot) == 4 && \
		ft_strlen(str) > 4)
		return (1);
	printf("Error: Wrong file, need <name.cub>\n");
	exit(EXIT_FAILURE);
}

static void	check_info(t_parse *parse)
{
	if (parse->fc[F] == 1 && parse->fc[C] == 1 && parse->tex[NO] == 1 \
		&& parse->tex[SO] == 1 && parse->tex[WE] == 1 && parse->tex[EA] == 1)
		parse->info = 1;
}

static void	read_file(t_parse *parse, t_world *world)
{
	char	*line;

	line = NULL;
	while (!parse->err && !parse->info && get_next_line(parse->fd, &line) > 0)
	{
		if (!parse->err && !parse->info)
			handle_info(line, parse, world);
		check_info(parse);
		free(line);
		line = NULL;
	}
	if (parse->err || !parse->info)
		raise_error(NO_INFO);
	if (!parse->err && parse->info)
		world->map = make_map(line, parse, world);
	while (line && get_next_line(parse->fd, &line) > 0)
	{
		free(line);
		line = NULL;
	}
	free(line);
}

void	parse_file(char *file, t_world *world)
{
	t_parse	parse;

	parse.fd = open(file, O_RDONLY);
	if (parse.fd == -1)
	{
		perror("Error");
		free_world(world);
		exit(EXIT_FAILURE);
	}
	parse.info = 0;
	parse.err = 0;
	parse.tex[0] = 0;
	parse.tex[1] = 0;
	parse.tex[2] = 0;
	parse.tex[3] = 0;
	parse.fc[0] = 0;
	parse.fc[1] = 0;
	read_file(&parse, world);
	close(parse.fd);
	if (parse.err || !world->map)
	{
		free_world(world);
		exit(EXIT_FAILURE);
	}
}
