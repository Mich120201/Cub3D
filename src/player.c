/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:26:20 by mich              #+#    #+#             */
/*   Updated: 2023/05/18 16:46:00 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	init_pos(t_game *game)
{
	game->count.i = -1;
	while (++game->count.i < 3)
	{
		game->count.j = -1;
		while (++game->count.j < 15)
		{
			if (game->map.map[game->count.i][game->count.j] == 'N'
				|| game->map.map[game->count.i][game->count.j] == 'S'
				|| game->map.map[game->count.i][game->count.j] == 'W'
				|| game->map.map[game->count.i][game->count.j] == 'E')
			{
				game->plyr.pos_x = game->count.j + 0.5;
				game->plyr.pos_y = game->count.i + 0.5;
				printf("%d %d\n", game->count.j, game->count.i);
			}
			game->mlx.buff[game->count.i][game->count.j] = 0;
		}
		printf("\n");
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

void	pos_player(t_game *game)
{
	init_pos(game);
	player_dir(game);
	plyr_dir(game);
	game->plyr.movement_s = 0.05;
	game->plyr.rotation_s = 0.04;
}
