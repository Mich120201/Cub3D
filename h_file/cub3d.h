/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:25:34 by mich              #+#    #+#             */
/*   Updated: 2023/05/16 16:12:12 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# include <signal.h>
# include <sys/wait.h>
# include <dirent.h>
# include <termios.h>
# include <math.h>
# include "../libft/h_file/libft.h"
# include "../src/src.h"

# define MAP_CHARS "012NEWSABC \n"

# define TEXT_SIZE 64
# define HEIGHT 1024
# define WIDTH 1280

# define K_PRESS 2
# define K_REL 3
# define MS_MOVE 6
# define K_EXIT 17
# define K_ESC 53

# define A_LEFT 123
# define A_RIGHT 124
# define A_DOWN 125
# define A_UP 126

# define K_A 0
# define K_S 1
# define K_D 2
# define K_Z 6
# define K_W 13
# define K_E 14

# define MOVE 0.0
# define DIV_1 1
# define DIV_2 1
# define MINI_SET 15


enum	e_cardinal
{
	NORTH,
	SOUTH,
	WEST,
	EAST
};

typedef enum e_bool
{
	TRUE = 1,
	FALSE = 0
}	t_bool;

typedef struct s_data
{
	int		argc;
	char	*argv;
	int		**text;
}	t_data;

typedef struct s_count
{
	int	i;
	int	j;
	int	l;
	int	*line;
}	t_count;

typedef struct s_vector
{
	int	x;
	int	y;
}	t_vector;

typedef struct s_map
{
	char	**map;
	char	**save_map;
	int		**m_int;
	char	*floor;
	char	*sky;
	int		player;
	int		i;
	int		fd;
	int		line_count;
	int		width;
	int		height;
	int		sky_color;
	int		floor_color;
}	t_map;

typedef struct s_save
{
	char	*nord;
	char	*sud;
	char	*est;
	char	*ovest;
	char	**f;
	char	**c;
	int		f_i;
	int		c_i;
}	t_save;

typedef struct s_mlx
{
	void	*mlx;
	void	*win;
	double	*z_buff;
	int		**text;
	int		**buff;
}	t_mlx;

typedef struct s_key
{
	int	k_up;
	int	k_down;
	int	k_right;
	int	k_left;
	int	turn_right;
	int	turn_left;
	int	k_esc;
	int	k_door;
	int	door_open;
}	t_key;

typedef struct s_image
{
	void	*image;
	int		*data;
	int		img_w;
	int		img_h;
	int		pos;
	int		line_size;
	int		end;
}	t_image;

typedef struct s_player
{
	char		dir;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		movement_s;
	double		rotation_s;
}	t_player;

typedef struct s_mouse
{
	int	ms_active;
	int	ms_x;
	int	ms_y;
}	t_mouse;

typedef struct s_sprites
{
	double	x;
	double	y;
	int		txt_n;
	char	sprt_tipe;
}	t_sprites;

typedef enum e_tiletype
{
	EMPTY = '0',
	WALL = '1',
}	t_tiletype;

typedef struct s_tile
{
	t_tiletype		type;
	t_tiletype		og_type;
	t_vector		position;
	struct s_tile	*up;
	struct s_tile	*down;
	struct s_tile	*left;
	struct s_tile	*right;
}	t_tile;

typedef struct s_b_sprite
{
	int	sprites_n;
	int	slime_frame;
}	t_b_sprite;

typedef struct s_math
{
	double	camera_x;
	double	ray_dir_x;
	double	ray_dir_y;
	double	side_dist_x;
	double	side_dist_y;
	double	delta_dist_x;
	double	delta_dist_y;
	double	perp_wall_dist;
	double	wall_x;
	double	step;
	double	tex_pos;
	int		map_x;
	int		map_y;
	int		step_x;
	int		step_y;
	int		hit;
	int		side;
	int		line_h;
	int		draw_start;
	int		draw_end;
	int		tex_n;
	int		tex_x;
	int		tex_y;
	int		color;
}	t_math;

typedef struct s_maths
{
	double	sprite_x;
	double	sprite_y;
	double	inv_det;
	double	transform_x;
	double	transform_y;
	int		sprite_screen_x;
	int		v_move_screen;
	int		sprite_h;
	int		draw_start_y;
	int		draw_end_y;
	int		sprite_width;
	int		draw_start_x;
	int		draw_end_x;
	int		stripe;
	int		tex_x;
	int		d;
	int		tex_y;
	int		color;
	int		i;
	int		y;
}	t_maths;

typedef struct s_swap
{
	double	first;
	int		second;
}	t_swap;

typedef struct s_mnmap
{
	int		side_len;
	int		tile_len;
	int		tile_set_x;
	int		tile_set_y;
	int		tiles_n_per_side;
	int		first_tile_x;
	int		first_tile_y;
}	t_mnmap;

typedef struct s_game
{
	t_tile		**tilemap;
	t_data		data;
	t_count		count;
	t_vector	wndw_size;
	t_map		map;
	t_save		save;
	t_mlx		mlx;
	t_key		key;
	t_image		img;
	t_player	plyr;
	t_mouse		mouse;
	t_sprites	**sprt;
	t_b_sprite	b_sprite;
	t_math		math;
	t_maths		maths;
	t_swap		swap;
	t_mnmap		minimap;
}	t_game;

#endif
