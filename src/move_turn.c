/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_turn.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:26:00 by mich              #+#    #+#             */
/*   Updated: 2023/05/16 16:26:40 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "move.h"

void	turn_right(t_game *game)
{
	double	old_dirx;
	double	oldplane_x;

	old_dirx = game->plyr.dir_x;
	oldplane_x = game->plyr.plane_x;
	game->plyr.dir_x = game->plyr.dir_x * cos(-game->plyr.rotation_s)
		- game->plyr.dir_y * sin(-game->plyr.rotation_s);
	game->plyr.dir_y = old_dirx * sin(-game->plyr.rotation_s)
		+ game->plyr.dir_y * cos(-game->plyr.rotation_s);
	game->plyr.plane_x = game->plyr.plane_x * cos(-game->plyr.rotation_s)
		- game->plyr.plane_y * sin(-game->plyr.rotation_s);
	game->plyr.plane_y = oldplane_x * sin(-game->plyr.rotation_s)
		+ game->plyr.plane_y * cos(-game->plyr.rotation_s);
}

void	turn_left(t_game *game)
{
	double	old_dirx;
	double	oldplane_x;

	old_dirx = game->plyr.dir_x;
	oldplane_x = game->plyr.plane_x;
	game->plyr.dir_x = game->plyr.dir_x * cos(game->plyr.rotation_s)
		- game->plyr.dir_y * sin(game->plyr.rotation_s);
	game->plyr.dir_y = old_dirx * sin(game->plyr.rotation_s)
		+ game->plyr.dir_y * cos(game->plyr.rotation_s);
	game->plyr.plane_x = game->plyr.plane_x * cos(game->plyr.rotation_s)
		- game->plyr.plane_y * sin(game->plyr.rotation_s);
	game->plyr.plane_y = oldplane_x * sin(game->plyr.rotation_s)
		+ game->plyr.plane_y * cos(game->plyr.rotation_s);
}
