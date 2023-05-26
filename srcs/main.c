/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:27:39 by tde-nico          #+#    #+#             */
/*   Updated: 2023/05/26 16:09:17 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	clean_exit(t_game *game)
{
	int	i;

	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	free_game(game);
	game->name_map = ft_split(game->split_name[0], '/');
	i = -1;
	while(game->name_map[1][++i])
		game->name_map[1][i] = ft_toupper(game->name_map[1][i]);
	printf("YOU WIN THE %s MAP!!!!!\n", game->name_map[1]);
	free_matrix(game->split_name);
	free_matrix(game->name_map);
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
	game.split_name = ft_split(argv[1], '.');
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
