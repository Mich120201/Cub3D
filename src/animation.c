/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:11:00 by mich              #+#    #+#             */
/*   Updated: 2023/05/22 15:26:03 by mvolpi           ###   ########.fr       */
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
			&& game->sprt[i]->txt_n == 6)
			game->sprt[i]->txt_n = 5;
		else if (game->sprt[i]->sprt_tipe == 'A'
			&& game->sprt[i]->txt_n == 6)
			game->sprt[i]->txt_n = 5;
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
