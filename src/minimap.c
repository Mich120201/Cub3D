/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 14:45:17 by mich              #+#    #+#             */
/*   Updated: 2023/05/16 15:11:04 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minimap.h"

void	init(t_game *game, t_mnmap *mini)
{
	mini->side_len = WIDTH / 6;
	mini->tile_len = mini->side_len / 10;
	mini->tile_set_x = (int)(((game->plyr.pos_y
					- floor(game->plyr.pos_y)) * 10) * mini->tile_len / 10);
	mini->tile_set_y = (int)(((game->plyr.pos_x
					- floor(game->plyr.pos_x)) * 10) * mini->tile_len / 10);
	mini->tiles_n_per_side = mini->side_len / mini->tile_len / 2 + 1;
	mini->first_tile_x = floor(game->plyr.pos_y) - mini->tiles_n_per_side;
	mini->first_tile_y = floor(game->plyr.pos_x) - mini->tiles_n_per_side;
}

int	color(t_game *game, t_mnmap *mini, int x, int y)
{
	int	map_x;
	int	map_y;

	map_x = floor(game->plyr.pos_y) - mini->tiles_n_per_side
		+ x / mini->tile_len;
	map_y = floor(game->plyr.pos_x) - mini->tiles_n_per_side
		+ y / mini->tile_len;
	if (map_y < game->map.height && map_x < game->map.width
		&& map_y >= 0 && map_x >= 0)
	{
		if (game->map.m_int[map_y][map_x] == 1)
			return (0x00BFFF);
		if (game->map.m_int[map_y][map_x] == 2)
			return (0x8B4513);
		if (game->map.m_int[map_y][map_x] == 0)
			return (0xC9B797);
	}
	return (0x000000);
}

void	draw_map(t_game *game, t_mnmap *mini)
{
	int	x;
	int	y;
	int	set_x;
	int	set_y;

	set_x = MINI_SET - mini->tile_len - mini->tile_set_x;
	set_y = MINI_SET - mini->tile_len - mini->tile_set_y;
	y = -1;
	while (++y < mini->side_len + 42)
	{
		x = -1;
		while (++x < mini->side_len + 42)
		{
			if (y + set_y >= MINI_SET && x + set_x >= MINI_SET
				&& y + set_y < mini->side_len - MINI_SET
				&& x + set_x < mini->side_len - MINI_SET)
				game->mlx.buff[y + set_y][x + set_x]
					= color(game, mini, x, y);
		}
	}
}

void	draw_player(t_game *game, t_mnmap *mini)
{
	int	i;
	int	j;

	i = mini->side_len / 2 + MINI_SET - 4;
	while (++i < mini->side_len / 2 + MINI_SET + 4)
	{
		j = mini->side_len / 2 + MINI_SET - 4;
		while (++j < mini->side_len / 2 + MINI_SET + 4)
			game->mlx.buff[i][j] = 0xFF0000;
	}
}

void	minimap_cast(t_game *game)
{
	t_mnmap	minimap;

	init(game, &minimap);
	draw_map(game, &minimap);
	draw_player(game, &minimap);
}
