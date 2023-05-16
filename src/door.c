/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:27:40 by mich              #+#    #+#             */
/*   Updated: 2023/05/16 16:28:50 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

static void	up_down(t_game *game)
{
	if (game->map.map[(int)game->plyr.pos_x + 1]
		[(int)game->plyr.pos_y] == '2')
	{
		if (game->map.m_int[(int)game->plyr.pos_x + 1]
			[(int)game->plyr.pos_y] == 2)
			game->map.m_int[(int)game->plyr.pos_x + 1]
			[(int)game->plyr.pos_y] = 0;
		else
			game->map.m_int[(int)game->plyr.pos_x + 1]
			[(int)game->plyr.pos_y] = 2;
		game->key.door_open = 1;
	}
	if (game->map.map[(int)game->plyr.pos_x - 1]
		[(int)game->plyr.pos_y] == '2')
	{
		if (game->map.m_int[(int)game->plyr.pos_x - 1]
			[(int)game->plyr.pos_y] == 2)
			game->map.m_int[(int)game->plyr.pos_x - 1]
			[(int)game->plyr.pos_y] = 0;
		else
			game->map.m_int[(int)game->plyr.pos_x - 1]
			[(int)game->plyr.pos_y] = 2;
		game->key.door_open = 1;
	}
}

static void	right_left(t_game *game)
{
	if (game->map.map[(int)game->plyr.pos_x]
		[(int)game->plyr.pos_y + 1] == '2')
	{
		if (game->map.m_int[(int)game->plyr.pos_x]
			[(int)game->plyr.pos_y + 1] == 2)
			game->map.m_int[(int)game->plyr.pos_x]
			[(int)game->plyr.pos_y + 1] = 0;
		else
			game->map.m_int[(int)game->plyr.pos_x]
			[(int)game->plyr.pos_y + 1] = 2;
		game->key.door_open = 1;
	}
	if (game->map.map[(int)game->plyr.pos_x]
		[(int)game->plyr.pos_y - 1] == '2')
	{
		if (game->map.m_int[(int)game->plyr.pos_x]
			[(int)game->plyr.pos_y - 1] == 2)
			game->map.m_int[(int)game->plyr.pos_x]
			[(int)game->plyr.pos_y - 1] = 0;
		else
			game->map.m_int[(int)game->plyr.pos_x]
			[(int)game->plyr.pos_y - 1] = 2;
		game->key.door_open = 1;
	}
}

void	door(t_game *game)
{
	if (!game->key.door_open)
	{
		up_down(game);
		right_left(game);
	}
}
