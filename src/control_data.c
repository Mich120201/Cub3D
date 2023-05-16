/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 13:01:28 by mich              #+#    #+#             */
/*   Updated: 2023/05/16 15:03:50 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void	control_data(t_game *game)
{
	game->count.i = -1;
	game->count.j = 0;
	while (game->map.map[++game->count.i])
	{
		if (ft_strncmp(game->map.map[game->count.i], "NO", 2) == 0)
			game->count.j++;
		else if (ft_strncmp(game->map.map[game->count.i], "SO", 2) == 0)
			game->count.j++;
		else if (ft_strncmp(game->map.map[game->count.i], "WE", 2) == 0)
			game->count.j++;
		else if (ft_strncmp(game->map.map[game->count.i], "EA", 2) == 0)
			game->count.j++;
		else if (ft_strncmp(game->map.map[game->count.i], "F", 1) == 0)
			game->count.j++;
		else if (ft_strncmp(game->map.map[game->count.i], "C", 1) == 0)
			game->count.j++;
		else if (ft_strncmp(game->map.map[game->count.i], "1", 1) == 0)
		{
			if (game->count.j < 6)
				exit_game(game, 1, "Error!! One argument missing!!\n");
			if (game->count.j > 6)
				exit_game(game, 1, "Error!! Duoble argument!!\n");
			if (control_map(game, game->count.i))
				return ;
		}
		else if (ft_strncmp(game->map.map[game->count.i], "\0", 2) != 0)
			exit_game(game, 1, "Invalid argument\n");
	}
}

int	convert_color(char **n_color)
{
	int	red;
	int	green;
	int	blue;
	int	color_int;

	red = ft_atoi(n_color[0]);
	green = ft_atoi(n_color[1]);
	blue = ft_atoi(n_color[2]);
	color_int = (red << 16) | (green << 8) | blue;
	return (color_int);
}

void	control_color(t_game *game)
{
	game->count.i = -1;
	game->count.l = ft_sarsize(game->save.f);
	if (game->count.l != 3)
		exit_game(game, 1, "Error!! Invalid color\n");
	game->count.l = ft_sarsize(game->save.c);
	if (game->count.l != 3)
		exit_game(game, 1, "Error!! Invalid color\n");
	while (game->save.f[++game->count.i])
	{
		game->save.f_i = ft_atoi(game->save.f[game->count.i]);
		if (game->save.f_i < 0 || game->save.f_i > 255)
			exit_game(game, 1, "Error!! The color value F is invalid!\n");
	}
	game->count.i = -1;
	while (game->save.c[++game->count.i])
	{
		game->save.c_i = ft_atoi(game->save.c[game->count.i]);
		if (game->save.c_i < 0 || game->save.c_i > 255)
			exit_game(game, 1, "Error!! The color value C is invalid!\n");
	}
	game->map.sky_color = convert_color(game->save.c);
	game->map.floor_color = convert_color(game->save.f);
}
