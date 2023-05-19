/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:44:40 by mich              #+#    #+#             */
/*   Updated: 2023/05/19 12:50:20 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src.h"

t_bool	init_data(t_game *game, int argc, char **argv)
{
	if (argc > 2)
		exit(write(2, "Invald number of arguments\n", 28));
	ft_bzero(game, sizeof(t_game));
	game->data.argv = argv[1];
	game->data.argc = argc;
	game->mlx.buff = (int **)malloc(sizeof(int *) * HEIGHT);
	if (!game->mlx.buff)
		exit_game(game, 1, "error during malloc buff\n");
	game->count.i = -1;
	while (++game->count.i < HEIGHT)
	{
		game->mlx.buff[game->count.i] = (int *)malloc(sizeof(int) * WIDTH);
		game->count.j = -1;
		while (++game->count.j < WIDTH)
			game->mlx.buff[game->count.i][game->count.j] = 0;
	}
	return (TRUE);
}

int	main(int argc, char **argv)
{
	t_game	game;

	init_data(&game, argc, argv);
	start(&game);
	ft_sarprint(game.map.save_map);
	pos_player(&game);
	create_game(&game);
	exit_game(&game, 0, "\n");
}
