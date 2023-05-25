/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:27:39 by tde-nico          #+#    #+#             */
/*   Updated: 2023/05/25 11:41:20 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	clean_exit(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	free_game(game);
	printf("YOU WIN!!!!!\n");
	exit(0);
	return (0);
}

int	exit_game(void)
{
	exit(0);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	game;

	if (check_args(argc, argv))
		return (1);
	game.map = read_map(argv[1]);
	if (!game.map)
		return (!INVALID_TESTING);
	if (start_game(&game))
	{
		free_map(game.map);
		return (!INVALID_TESTING);
	}
	init_game(&game);
	mlx_hook(game.win, ON_KEYDOWN, 1L << 0, input_handler_down, (void *)&game);
	mlx_hook(game.win, ON_KEYUP, 1L << 1, input_handler_up, (void *)&game);
	mlx_hook(game.win, ON_MOUSEMOVE, 1L << 6, mouse_handler, (void *)&game);
	mlx_hook(game.win, ON_DESTROY, 0, clean_exit, (void *)&game);
	mlx_loop_hook(game.mlx, update, (void *)&game);
	mlx_loop(game.mlx);
	return (0);
}
