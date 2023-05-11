/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:25:34 by mich              #+#    #+#             */
/*   Updated: 2023/05/09 12:18:16 by mvolpi           ###   ########.fr       */
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
	int		player;
	int		i;
	int		fd;
	int		line_count;
	
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
	int	bubble_frame;
	int	siren_frame;
	int	coll_frame;
}	t_b_sprite;

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
}	t_game;

#endif
