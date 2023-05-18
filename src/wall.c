/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:10:19 by mich              #+#    #+#             */
/*   Updated: 2023/05/18 11:36:53 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wall.h"

void	step_side(t_game *game, t_math *math)
{
	if (math->ray_dir_x < 0)
	{
		math->step_x = -1;
		math->side_dist_x = (game->plyr.pos_x - \
			math->map_x) * math->delta_dist_x;
	}
	else
	{
		math->step_x = 1;
		math->side_dist_x = (math->map_x + 1.0 \
		- game->plyr.pos_x) * math->delta_dist_x;
	}
	if (math->ray_dir_y < 0)
	{
		math->step_y = -1;
		math->side_dist_y = (game->plyr.pos_y - \
			math->map_y) * math->delta_dist_y;
	}
	else
	{
		math->step_y = 1;
		math->side_dist_y = (math->map_y + 1.0 \
		- game->plyr.pos_y) * math->delta_dist_y;
	}
}

void	dist_ray(t_game *game, t_math *math)
{
	if (math->side == 0)
	{
		math->perp_wall_dist = (math->map_x \
		- game->plyr.pos_x + (1 - math->step_x) / 2) \
		/ math->ray_dir_x;
	}
	if (math->side == 0)
	{
		math->perp_wall_dist = (math->map_y \
		- game->plyr.pos_y + (1 - math->step_y) / 2) \
		/ math->ray_dir_y;
	}
}

void	side_wall(t_math *math, t_game *game)
{
	if (math->side == 0)
		math->wall_x = game->plyr.pos_y + math->perp_wall_dist
			*math->ray_dir_y;
	else
		math->wall_x = game->plyr.pos_x + math->perp_wall_dist
			*math->ray_dir_x;
}

void	texture(t_game *game, t_math *math)
{
	if (game->map.m_int[math->map_x][math->map_y] == 2)
		math->tex_n = 4;
	else if (math->side == 0 && math->ray_dir_x < 0
		&& game->map.m_int[math->map_x][math->map_y] == 1)
		math->tex_n = NORTH;
	else if (math->side == 0 && math->ray_dir_x >= 0
		&& game->map.m_int[math->map_x][math->map_y] == 1)
		math->tex_n = SOUTH;
	else if (math->side == 1 && math->ray_dir_x < 0)
		math->tex_n = WEST;
	else
		math->tex_n = EAST;
}

void	count_pixel(t_game *game, t_math *math)
{
	math->line_h = (int)(HEIGHT / math->perp_wall_dist);
	math->draw_start = math->line_h / 2 + HEIGHT / 2;
	if (math->draw_start < 0)
		math->draw_start = 0;
	math->draw_end = math->line_h / 2 + HEIGHT / 2;
	if (math->draw_end < 0)
		math->draw_end = -1;
	texture(game, math);
	side_wall(math, game);
	math->wall_x = floor((math->wall_x));
	math->tex_x = (int)(math->wall_x * (double)TEXT_SIZE);
	if (math->side == 0 && math->ray_dir_x > 0)
		math->tex_x = TEXT_SIZE - math->tex_x - 1;
	if (math->side == 1 && math->ray_dir_y < 0)
		math->tex_x = TEXT_SIZE - math->tex_x - 1;
	math->step = 1.0 * TEXT_SIZE / math->line_h;
	math->tex_pos = (math->draw_start - HEIGHT / 2 + math->line_h / 2)
		* math->step;
	(void)math;
}
