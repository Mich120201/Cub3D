/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:50:58 by mich              #+#    #+#             */
/*   Updated: 2023/05/19 10:12:55 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.h"

int	save_info(char *line, t_game *game)
{
	game->count.i = -1;
	while (line[++game->count.i])
	{
		if (!ft_strchr(MAP_CHARS, line[game->count.i]))
			exit_game(game, 1, "invalid char\n");
	}
	game->count.j = ft_strlen(line);
	if (game->count.j > game->map.width)
		game->map.width += game->count.j;
	if (ft_strlen(line) > 0)
		game->map.height++;
	return (0);
}

int	take_line(char *line, t_game *game)
{
	if (line == NULL)
		return (1);
	else if (ft_strncmp(line, "NO ", 3) == 0
		|| ft_strncmp(line, "SO ", 3) == 0
		|| ft_strncmp(line, "WE ", 3) == 0
		|| ft_strncmp(line, "EA ", 3) == 0
		|| ft_strncmp(line, "F ", 2) == 0
		|| ft_strncmp(line, "C ", 2) == 0)
	{
		free(line);
		return (0);
	}
	else
	{
		if (save_info(line, game))
			return (2);
	}
	free(line);
	return (0);
}

void	take_data(t_game *game)
{
	char	*line;

	open_file(game);
	while (get_next_line(game->map.fd, &line) > 0)
	{
		game->map.i = take_line(line, game);
		if (game->map.i == 1)
			break ;
		else if (game->map.i == 2)
			exit_game(game, 1, "error readind line\n");
	}
	free(line);
	close_file(game);
}

void	convert_map(t_game *game)
{
	game->map.m_int = (int **)malloc(sizeof(int *) * game->map.height);
	game->count.i = -1;
	while (++game->count.i < game->map.height)
	{
		game->count.j = -1;
		game->map.m_int[game->count.i] = (int *)malloc(sizeof(int) \
			* game->map.width);
		while (++game->count.j < game->map.width)
		{
			if (game->map.save_map[game->count.i][game->count.j] == '1')
				game->map.m_int[game->count.i][game->count.j] = 1;
			else if (game->map.save_map[game->count.i][game->count.j] == '2')
				game->map.m_int[game->count.i][game->count.j] = 2;
			else
				game->map.m_int[game->count.i][game->count.j] = 0;
		}
		game->map.m_int[game->count.i][game->count.j] = 8;
	}
}

void	map_init(t_game *game)
{
	valid_file(game);
	take_data(game);
	read_map(game->data.argv, game);
	if (!game->map.map)
		exit_game(game, 1, "Error malloc map!!\n");
	game->map.save_map = (char **)malloc(sizeof(char) * game->map.height);
	control_data(game);
	sprites(game);
	convert_map(game);
}
