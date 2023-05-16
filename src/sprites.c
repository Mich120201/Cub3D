/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:40:33 by mich              #+#    #+#             */
/*   Updated: 2023/05/16 15:13:02 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites.h"

int	n_sprites(t_game *game)
{
	game->count.i = -1;
	while (game->map.map[++game->count.i])
	{
		game->count.j = -1;
		while (game->map.map[game->count.i][++game->count.j])
		{
			if (game->map.map[game->count.i][game->count.j] == 'A')
				game->b_sprite.sprites_n++;
		}
	}
	return (game->b_sprite.sprites_n);
}

void	malloc_sprt(t_game *game)
{
	game->count.i = -1;
	game->sprt = (t_sprites **)malloc(sizeof(t_sprites *) 
		* game->b_sprite.sprites_n);
	while (++game->count.i < game->b_sprite.sprites_n)
		game->sprt[game->count.i] = (t_sprites *)malloc(sizeof(t_sprites));
}

int	check_pos_sprite(t_game *game, int y, int x, int pos)
{
	if (game->map.map[y][x] == 'A')
	{
		game->sprt[pos]->x = y + 0.5;
		game->sprt[pos]->y = x + 0.5;
		game->sprt[pos]->txt_n = 5;
		game->sprt[pos]->sprt_tipe = game->map.map[y][x];
		pos++;
	}
	return (pos);
}

void	pos_sprites(t_game *game)
{
	int	x;
	int	y;
	int	pos;
	
	pos = 0;
	y = -1;
	while (game->map.map[++y])
	{
		x = -1;
		while (game->map.map[y][++x])
			pos = check_pos_sprite(game, y, x, pos);
	}
}

void	sprites(t_game *game)
{
	if (!n_sprites(game))
		return ;
	malloc_sprt(game);
	pos_sprites(game);
}
