/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:26:20 by mich              #+#    #+#             */
/*   Updated: 2023/05/19 10:13:55 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	init_buff_plyr(t_game *game)
{
	game->count.i = -1;
	while (++game->count.i < game->map.size_h)
	{
		game->map.size_w = -1;
		while(game->map.m_int[game->count.i][++game->map.size_w] != 8)
			;
		game->count.j = -1;
		while (++game->count.j < game->map.size_w)
		{
			if (game->map.map[game->count.i][game->count.j] == 'N'
				|| game->map.map[game->count.i][game->count.j] == 'S'
				|| game->map.map[game->count.i][game->count.j] == 'W'
				|| game->map.map[game->count.i][game->count.j] == 'E')
			{
				game->plyr.pos_x = game->count.j + 0.5;
				game->plyr.pos_y = game->count.i + 0.5;
			}
			game->mlx.buff[game->count.i][game->count.j] = 0;
		}
	}
}

void	player_dir(t_game *game)
{
	if (game->plyr.dir == 'N')
	{
		game->plyr.dir_x = -1.0;
		game->plyr.dir_y = 0.0;
		game->plyr.plane_x = 0.0;
		game->plyr.plane_y = 0.66;
	}
	else if (game->plyr.dir == 'S')
	{
		game->plyr.dir_x = 1.0;
		game->plyr.dir_y = 0.0;
		game->plyr.plane_x = 0.0;
		game->plyr.plane_y = -0.66; 
	}
}

void	plyr_dir(t_game *game)
{
	if (game->plyr.dir == 'W')
	{
		game->plyr.dir_x = 0.0;
		game->plyr.dir_y = -1.0;
		game->plyr.plane_x = -0.66;
		game->plyr.plane_y = 0.0;
	}
	else if (game->plyr.dir == 'E')
	{
		game->plyr.dir_x = 0.0;
		game->plyr.dir_y = 1.0;
		game->plyr.plane_x = 0.66;
		game->plyr.plane_y = 0.0;
	}
}

void	map_size(t_game *game)
{
	game->map.size_h = -1;
	while (game->map.m_int[++game->map.size_h])
		;
	game->map.size_w = game->map.max_size_w;
}

void	pos_player(t_game *game)
{
	map_size(game);
	init_buff_plyr(game);
	player_dir(game);
	plyr_dir(game);
	game->plyr.movement_s = 0.05;
	game->plyr.rotation_s = 0.04;
}
