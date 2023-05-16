/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:59:20 by mich              #+#    #+#             */
/*   Updated: 2023/05/16 14:26:39 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_close(t_game *game, int *order, double *dist)
{
	int	i;

	i = -1;
	while (++i < game->b_sprite.sprites_n)
	{
		order[i] = i;
		dist[i] = ((game->plyr.pos_x - game->sprt[i]->x)
				* (game->plyr.pos_x - game->sprt[i]->x)
				+ (game->plyr.pos_y - game->sprt[i]->y)
				* (game->plyr.pos_y - game->sprt[i]->y));
	}
}

void	sort(t_swap *orders, int amount)
{
	t_swap	tmp;
	int		i;
	int		j;

	i = -1;
	while (++i < amount)
	{
		j = -1;
		while (++j < amount - 1)
		{
			if (orders[j].first > orders[j + 1].first)
			{
				tmp.first = orders[j].first;
				tmp.second = orders[j].second;
				orders[j].first = orders[j + 1].first;
				orders[j].second = orders[j + 1].second;
				orders[j + 1].first = tmp.first;
				orders[j + 1].second = tmp.second;
			}
		}
	}
}

void	sort_sprites(int *order, double *dist, int amount)
{
	t_swap	*sprites;
	int		i;

	i = -1;
	sprites = (t_swap *)malloc(sizeof(t_swap) * amount);
	while (++i < amount)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
	}
	sort(sprites, amount);
	i = -1;
	while (++i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
	}
	free(sprites);
}
