/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echerell <echerell@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 20:59:44 by echerell          #+#    #+#             */
/*   Updated: 2022/04/30 00:11:19 by echerell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdio.h>
# include <fcntl.h>
# include "libft.h"
# include "mlx.h"
# include "get_next_line.h"

# define WIN_WIDTH 1280
# define WIN_HEIGHT 720

# define KEY_ESC 65307
# define KEY_W 119
# define KEY_S 115
# define KEY_A 97
# define KEY_D 100
# define KEY_ARR_LEFT 65361
# define KEY_ARR_RIGHT 65363

# define NO 0
# define SO 1
# define WE 2
# define EA 3
# define F 0
# define C 1

enum	e_err
{
	DOUB_TEX = -20,
	MLX_FAIL,
	TEX_ARG,
	TEX_FAIL,
	UNDEF_INFO,
	DOUB_FC,
	FC_ARG,
	FC_RGB,
	NO_INFO,
	MAP_SYM,
	PLAYER_POS,
	NO_MAP,
	MAP_WALL,
	WRG_POS
};

typedef struct s_parse
{
	int	fd;
	int	info;
	int	tex[4];
	int	err;
	int	tex_id;
	int	fc[2];
	int	fc_id;
	int	p_set;
}t_parse;

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

typedef struct s_tex
{
	void	*img_ptr;
	char	*img_addr;
	int		bpp;
	int		line_len;
	int		width;
	int		height;
	int		endi;
	int		t_x;
	int		t_y;
	double	step;
	double	tex_pos;
}t_tex;

typedef struct s_world
{
	t_mlx		mlx;
	t_vector	pos;
	t_vector	dir;
	t_vector	ray;
	t_camera	camera;
	t_map		map_step;
	int			**map;
	int			map_width;
	int			map_height;
	t_dist		dist;
	t_line		line;
	t_tex		tex[4];
	int			hit;
	int			side;
	int			color;
	int			f_col;
	int			c_col;
	double		wall_x;
	int			t_side;
}t_world;

// free all staff
void	free_world(t_world *world);
// events for key pressed
int		key_event(int keycode, void *param);
// initialization
void	init(t_world *world, char *filename);
// main function for drawing world
void	draw(t_world *world);
// put vertical line on img
void	put_line(t_world *world, int x);
// determine, which texture pixel put on img
void	put_tex(t_world *world, int x, int y, int id);
// put pixel function
void	put_pix(t_world *world, int x, int y, int color);
// close window on red cross
int		cross_close(void *param);
// check file name and extension
int		check_file(char *str);
// main function for parcing
void	parse_file(char *file, t_world *world);
// print error, if occurs
void	raise_error(int err_type);
// free map matrix
void	free_mat(char **strs);
// determine length of char** matrix
int		mat_size(char **strs);
// open texture file and load to img
void	add_tex(char *file, t_world *world, int id, t_parse *parse);
// determine texture world side
int		check_tex_type(const char *str, int *tex, int *tex_id);
// check, if rgb is a number in file
int		check_num(char *str);
// add floor and ceil color
void	add_fc_color(char *str, t_world *world, t_parse *parse);
// check for holes on the map
int		look_around(int **map, int i, int j, int width);
// set player position and direction with camera
void	set_pos(char c, int x, int y, t_world *world);
// function to check info before map in the file
void	handle_info(char *line, t_parse *parse, t_world *world);
// check, if the map is closed
void	check_wall(int	**map, t_world *world, t_parse *parse);
// main function for map checking
int		check_map(char *str, int *p_set, t_world *world);
// check, if player stand on the right place
void	check_pos(int **map, t_world *world, t_parse *parse);
// create int matrix, which represents a map
int		**make_map(char *line, t_parse *parse, t_world *world);

#endif
