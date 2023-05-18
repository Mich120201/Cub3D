/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cast.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 11:24:23 by mich              #+#    #+#             */
/*   Updated: 2023/05/18 11:35:04 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray_cast.h"

void	background_cast(t_game *game)
{
	int	x;
	int	y;

	y = -1;
	while (++y < HEIGHT)
	{
		x = -1;
		while (++x < WIDTH)
		{
			if (y < (HEIGHT / 2))
				game->mlx.buff[y][x] = game->map.sky_color;
			else
				game->mlx.buff[y][x] = game->map.floor_color;
		}
	}
}

void	math_init(t_game *game, t_math *math, int x)
{
	math->camera_x = 2 * x
		/ (double)WIDTH - 1;
	math->ray_dir_x = game->plyr.dir_x
		+ game->plyr.plane_x * math->camera_x;
	math->ray_dir_y = game->plyr.dir_y
		+ game->plyr.plane_y * math->camera_x;
	math->map_x = (int)game->plyr.pos_x;
	math->map_y = (int)game->plyr.pos_y;
	math->delta_dist_x = fabs(1 / math->ray_dir_x);
	math->delta_dist_y = fabs(1 / math->ray_dir_y);
	math->hit = 0;
}

void	digit_diff_analysis(t_game *game, t_math *math)
{
	while (math->hit == 0)
	{
		if (math->side_dist_x
			< math->side_dist_y)
		{
			math->side_dist_x += math->delta_dist_x;
			math->map_x += math->step_x;
			math->side = 0;
		}
		else
		{
			math->side_dist_y += math->delta_dist_y;
			math->map_y += math->step_y;
			math->side = 1;
		}
		if (game->map.m_int[math->map_x]
			[math->map_y] > 0)
			math->hit = 1;
	}
}

void	wall_cast(t_game *game)
{
	t_math	math;
	int		x;
	int		y;

	x = -1;
	while (++x < WIDTH)
	{
		math_init(game, &math, x);
		step_side(game, &math);
		digit_diff_analysis(game, &math);
		dist_ray(game, &math);
		count_pixel(game, &math);
		y = math.draw_start;
		while (y < math.draw_end)
		{
			math.tex_y = (int)math.tex_pos & (TEXT_SIZE);
			math.tex_pos += math.step;
			math.color = game->mlx.text[math.tex_n]
			[TEXT_SIZE * math.tex_y + math.tex_x];
			game->mlx.buff[y][x] = math.color;
			y++;
		}
		game->mlx.z_buff[x] = math.perp_wall_dist;
	}
}

void	ray_cast(t_game *game)
{
	background_cast(game);
	wall_cast(game);
	sprites_cast(game);
	minimap_cast(game);
}
