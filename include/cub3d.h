/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:59:44 by echerell          #+#    #+#             */
/*   Updated: 2022/04/24 21:20:40 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include "libft.h"
# include "mlx.h"

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720
# define MAP_WIDTH 24
# define MAP_HEIGHT 24

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_ARR_LEFT 65361
# define KEY_ARR_RIGHT 65363

# define RGB_1 0x223240
# define RGB_2 0x3B8C66
# define RGB_3 0x347355
# define RGB_4 0x60BF81
# define RGB_5 0x93D94E
# define RGB_FLOOR 0x07403A
# define RGB_CEIL 0x58007F

typedef struct s_mlx
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*img_ptr;
	char	*img_addr;
	int		bpp;
	int		line_len;
	int		endian;
}t_mlx;

typedef struct s_vector
{
	double	x;
	double	y;
}t_vector;

typedef struct s_camera
{
	double	plane_x;
	double	plane_y;
	double	move_x;
}t_camera;

typedef struct s_map
{
	int	x;
	int	y;
	int	step_x;
	int	step_y;
}t_map;

typedef struct s_dist
{
	double	side_x;
	double	side_y;
	double	delta_x;
	double	delta_y;
	double	perp_dist;
}t_dist;

typedef struct s_line
{
	int	height;
	int	start;
	int	end;
}t_line;

typedef struct s_world
{
	t_mlx		mlx;
	t_vector	pos;
	t_vector	dir;
	t_vector	ray;
	t_camera	camera;
	t_map		map_step;
	t_dist		dist;
	t_line		line;
	int			hit;
	int			side;
	int			color;
}t_world;

extern int worldMap[MAP_WIDTH][MAP_HEIGHT];

void	free_world(t_world *world);
int		key_event(int keycode, void *param);
void	init(t_world *world);
void	draw(t_world *world);

#endif
