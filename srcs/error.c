/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 09:40:28 by echerell          #+#    #+#             */
/*   Updated: 2022/04/29 22:21:18 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	raise_error2(int err_type)
{
	if (err_type == FC_RGB)
		printf("Error: Wrong range of RGB\n");
	else if (err_type == NO_INFO)
		printf("Error: Wrong information or map not at the right place\n");
	else if (err_type == MAP_SYM)
		printf("Error: Incorrect map\n");
	else if (err_type == PLAYER_POS)
		printf("Error: Multiple player position or no position\n");
	else if (err_type == NO_MAP)
		printf("Error: No map in the file\n");
	else if (err_type == MAP_WALL)
		printf("Error: Map is not closed\n");
	else if (err_type == WRG_POS)
		printf("Error: Player wrong position\n");
}

void	raise_error(int err_type)
{
	if (err_type == DOUB_TEX)
		printf("Error: Double definition of the same texture side\n");
	else if (err_type == MLX_FAIL)
		printf("Error: MLX failed to initialize\n");
	else if (err_type == TEX_ARG)
		printf("Error: Wrong number of arguments near texture definition\n");
	else if (err_type == TEX_FAIL)
	{
		printf("Error: Cannot load texture file, check, that it is .xpm");
		printf(" and it exists\n");
	}
	else if (err_type == UNDEF_INFO)
		printf("Error: Undefined information in the file\n");
	else if (err_type == DOUB_FC)
		printf("Error: Double definition of floor or ceil color\n");
	else if (err_type == FC_ARG)
		printf("Error: Wrong arguments of floor or ceil color\n");
	raise_error2(err_type);
}
