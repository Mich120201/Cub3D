/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:59:22 by mich              #+#    #+#             */
/*   Updated: 2023/05/18 11:30:36 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void	control_fst_lst_line(char *line, int i, t_game *game)
{
	game->count.j = 0;
	while (line[++i] == ' ')
		;
	while (line[i])
	{
		if (line[i] == '1')
			i++;
		if (line[i] != '1')
		{
			while (line[i] == ' ')
			{
				if (line[i + 1] != ' ')
					exit_game(game, 1, "Error!! The map isn't closed\n");
				i++;
			}
			if (line[i] == '0' || line[i] == 'N' || line[i] == 'S' \
				|| line[i] == 'W' || line[i] == 'E' || line[i] == '2')
				exit_game(game, 1, "Error!! The map isn't closed\n");
		}
	}
}

void	ft_continue(char *line, int i, t_game *game, int j)
{
	if (game->map.map[j - 1][i] == '\0'
		|| game->map.map[j + 1][i] == '\0'
		|| line[i + 1] == '\0')
		exit_game(game, 1, "Error!! The map isn't closed\n");
	if (line[i] != 'N' && line[i] != 'S'
		&& line[i] != 'E' && line[i] != 'W'
		&& line[i] != '1' && line[i] != '0'
		&& line[i] != '2')
		exit_game(game, 1, "Error!! The map isn't closed\n");
}

void	control_line(char *line, int i, t_game *game, int j)
{
	while (line[++i] == ' ')
		;
	if (line[i] != '1')
		exit_game(game, 1, "Error!! The map isn't closed\n");
	while (line[i])
	{
		if (line[i] != '1' && line[i] != ' ')
		{
			if (line[i] == 'N' || line[i] == 'S'
				|| line[i] == 'E' || line[i] == 'W')
			{
				game->map.player++;
				if (game->map.player > 1)
					exit_game(game, 1, "Double player\n");
				game->plyr.dir = line[i];
			}
			if (game->map.map[j - 1][i] == ' ' || game->map.map[j + 1][i] == ' '
				|| line[i + 1] == ' ')
				exit_game(game, 1, "Error!! The map isn't closed\n");
			ft_continue(line, i, game, j);
		}
		i++;
	}
}
