/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/09 10:40:33 by mich              #+#    #+#             */
/*   Updated: 2023/05/09 11:35:02 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sprites.h"

int	pos_sprites(t_game *game)
{
	game->count.i = -1;
	while (game->map.map[++game->count.i])
	{
		game->count.j = -1;
		while (game->map.map[game->count.i][++game->count.i])
		{
			// if (game->map.map == 2)
			// 	game->b_sprite.sprites_n++;
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

void	sprites(t_game *game)
{
	if (!pos_sprites(game))
		return ;
	malloc_sprt(game);
}
