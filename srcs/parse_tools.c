/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_tools.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 10:01:46 by echerell          #+#    #+#             */
/*   Updated: 2022/04/29 22:22:33 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_mat(char **strs)
{
	int	i;

	i = 0;
	if (strs && *strs)
	{
		while (strs[i])
		{
			free(strs[i]);
			i++;
		}
		free(strs);
	}
}

int	mat_size(char **strs)
{
	int	i;

	i = 0;
	while (strs[i])
		i++;
	return (i);
}

int	check_num(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (!ft_isdigit(str[i]))
			return (1);
		i++;
	}
	return (0);
}

int	look_around(int **map, int i, int j, int width)
{
	if (j == 0 || j == width - 1)
		return (1);
	if (map[i][j - 1] == -1 || map[i][j + 1] == -1 ||
		map[i - 1][j] == -1 || map[i + 1][j] == -1)
		return (1);
	return (0);
}
