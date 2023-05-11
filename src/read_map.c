/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:25:26 by mich              #+#    #+#             */
/*   Updated: 2023/05/05 15:16:23 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "read.h"

static int	file_linecount(char *file)
{
	int		linecount;
	int		fd;
	int		readcount;
	char	c;

	fd = open(file, O_RDONLY);
	if (!fd)
		return (-1);
	linecount = 1;
	while (TRUE)
	{
		readcount = read(fd, &c, 1);
		if (readcount == 0)
			break ;
		if (readcount < 0)
			return (-1);
		if (c == '\n')
			linecount++;
	}
	close(fd);
	return (linecount);
}

void	create_columns(char *file, t_game *game)
{
	game->map.line_count = file_linecount(file);
	if (game->map.line_count <= 0)
		exit(printf("Error!! Open or reading error, \
			the file may not exist\n"));
	game->map.map = malloc(sizeof(char *) * game->map.line_count + 1);
	game->count.line = malloc(sizeof(int) * game->map.line_count + 1);
	if (game->map.map == NULL)
		exit_game(game, 1, "Eroor!! Malloc error on alloc_map()\n");
}

void	read_map(char *file, t_game *game)
{
	create_columns(file, game);
	if (game->map.map == NULL)
		return ;
	game->map.fd = open(file, O_RDONLY);
	game->count.i = 0;
	while (get_next_line(game->map.fd, \
		&game->map.map[game->count.i++]))
		;
	game->map.map[game->count.i] = NULL;
	close(game->map.fd);
}
