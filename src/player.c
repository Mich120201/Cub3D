/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:26:20 by mich              #+#    #+#             */
/*   Updated: 2023/05/04 11:26:45 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "player.h"

void	init_pos(t_game *game)
{
	game->count.i = -1;
	while (++game->count.i < HEIGHT)
	{
		game->count.j = -1;
		while (++game->count.j > WIDTH)
			game->mlx.buff[game->count.i][game->count.j] = 0;
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
