/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:23:19 by mich              #+#    #+#             */
/*   Updated: 2023/05/16 16:24:43 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

void	up(t_game *game)
{
	if (!game->map.m_int[(int)(game->plyr.pos_x + game->plyr.dir_x
			* game->plyr.movement_s)][(int)game->plyr.pos_y])
		game->plyr.pos_x += game->plyr.dir_x * game->plyr.movement_s;
	if (!game->map.m_int[(int)game->plyr.pos_x]
		[(int)(game->plyr.pos_y + game->plyr.dir_y
			* game->plyr.movement_s)])
		game->plyr.pos_y += game->plyr.dir_y * game->plyr.movement_s;
}

void	down(t_game *game)
{
	if (!game->map.m_int[(int)(game->plyr.pos_x - game->plyr.dir_x
			* game->plyr.movement_s)][(int)game->plyr.pos_y])
		game->plyr.pos_x -= game->plyr.dir_x * game->plyr.movement_s;
	if (!game->map.m_int[(int)game->plyr.pos_x]
		[(int)(game->plyr.pos_y - game->plyr.dir_y
			* game->plyr.movement_s)])
		game->plyr.pos_y -= game->plyr.dir_y * game->plyr.movement_s;
}

void	right(t_game *game)
{
	double	dirx;
	double	diry;

	dirx = -game->plyr.dir_y;
	diry = game->plyr.dir_x;
	if (!game->map.m_int[(int)(game->plyr.pos_x - dirx
			* game->plyr.movement_s)][(int)game->plyr.pos_y])
		game->plyr.pos_x -= dirx * game->plyr.movement_s;
	if (!game->map.m_int[(int)game->plyr.pos_x]
		[(int)(game->plyr.pos_y - diry * game->plyr.movement_s)])
		game->plyr.pos_y -= diry * game->plyr.movement_s;
}

void	left(t_game *game)
{
	double	dirx;
	double	diry;

	dirx = game->plyr.dir_y;
	diry = -game->plyr.dir_x;
	if (!game->map.m_int[(int)(game->plyr.pos_x - dirx
			* game->plyr.movement_s)][(int)game->plyr.pos_y])
		game->plyr.pos_x -= dirx * game->plyr.movement_s;
	if (!game->map.m_int[(int)game->plyr.pos_x]
		[(int)(game->plyr.pos_y - diry * game->plyr.movement_s)])
		game->plyr.pos_y -= diry * game->plyr.movement_s;
}
