/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 12:36:55 by mich              #+#    #+#             */
/*   Updated: 2023/05/16 16:30:53 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mouse.h"

int	ms_move(int x, int y, t_game *game)
{
	int		diff;
	double	dir_x;
	double	plane_x;
	double	rot_speed;

	(void)y;
	if (game->mouse.ms_active)
	{
		diff = x - game->mouse.ms_x;
		dir_x = game->plyr.dir_x;
		plane_x = game->plyr.plane_x;
		rot_speed = (diff * game->plyr.rotation_s) / 900;
		game->mouse.ms_x = x;
		game->plyr.dir_x = game->plyr.dir_x * cos(rot_speed)
			- game->plyr.dir_y * sin(rot_speed);
		game->plyr.dir_y = dir_x * sin(rot_speed)
			+ game->plyr.dir_y * cos(rot_speed);
		game->plyr.plane_x = game->plyr.plane_x * cos(rot_speed)
			- game->plyr.plane_y * sin(rot_speed);
		game->plyr.plane_y = plane_x * sin(rot_speed)
			+ game->plyr.plane_y * cos(rot_speed);
	}
	return (0);
}

void	unlock(t_game *game)
{
	mlx_mouse_show(game->mlx.mlx, game->mlx.win);
}

void	lock(t_game *game)
{
	game->mouse.ms_x = WIDTH / 2;
	game->mouse.ms_y = HEIGHT / 2;
}

void	mouse(t_game *game)
{
	if (game->mouse.ms_active)
		lock(game);
	else
		unlock(game);
}
