/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:11:00 by mich              #+#    #+#             */
/*   Updated: 2023/05/16 16:32:18 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "animation.h"

void	change_slime(t_game *game)
{
	int	i;

	i = -1;
	while (++i < game->b_sprite.sprites_n)
	{
		if (game->sprt[i]->sprt_tipe == 'A'
			&& game->sprt[i]->txt_n == 7)
			game->sprt[i]->txt_n = 6;
		else if (game->sprt[i]->sprt_tipe == 'A'
			&& game->sprt[i]->txt_n == 6)
			game->sprt[i]->txt_n = 7;
	}
}

void	animation(t_game *game)
{
	game->b_sprite.slime_frame++;
	if (game->b_sprite.slime_frame == 40)
	{
		change_slime(game);
		game->b_sprite.slime_frame = 0;
	}
}
