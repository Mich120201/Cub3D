/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:53:39 by mich              #+#    #+#             */
/*   Updated: 2023/05/16 11:35:49 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "init.h"

void	save_data(t_game *game)
{
	game->count.i = -1;
	while (game->map.map[++game->count.i])
	{
		if (ft_strncmp(game->map.map[game->count.i], "NO", 2) == 0)
			game->save.nord = ft_strdup(game->map.map[game->count.i] + 3);
		if (ft_strncmp(game->map.map[game->count.i], "SO", 2) == 0)
			game->save.sud = ft_strdup(game->map.map[game->count.i] + 3);
		if (ft_strncmp(game->map.map[game->count.i], "WE", 2) == 0)
			game->save.ovest = ft_strdup(game->map.map[game->count.i] + 3);
		if (ft_strncmp(game->map.map[game->count.i], "EA", 2) == 0)
			game->save.est = ft_strdup(game->map.map[game->count.i] + 3);
		if (ft_strncmp(game->map.map[game->count.i], "F", 1) == 0)
		{
			game->map.floor = ft_strdup(game->map.map[game->count.i]);
			game->save.f = ft_split(game->map.map[game->count.i] + 2, ',');
		}
		if (ft_strncmp(game->map.map[game->count.i], "C", 1) == 0)
		{
			game->map.sky = ft_strdup(game->map.map[game->count.i]);
			game->save.c = ft_split(game->map.map[game->count.i] + 2, ',');
		}
	}
	control_color(game);
}

void	start(t_game *game)
{
	map_init(game);
	save_data(game);
	sprites(game);
}
