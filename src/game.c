/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/03 15:44:27 by mich              #+#    #+#             */
/*   Updated: 2023/05/16 15:06:31 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "game.h"

int	play_game(t_game *game)
{
	ray_cast(game);
	return (0);
}

void	create_game(t_game *game)
{
	game->mlx.z_buff = (double *)malloc(sizeof(double) * WIDTH);
	game->mlx.mlx = mlx_init();
	put_txt(game);
	game->mlx.win = mlx_new_window(game->mlx.mlx, WIDTH, HEIGHT, "Cub3D");
	game->img.image = mlx_new_image(game->mlx.mlx, WIDTH, HEIGHT);
	game->img.data = (int *)mlx_get_data_addr(game->img.image, &game->img.pos,
		&game->img.line_size, &game->img.end);
	mlx_loop_hook(game->mlx.mlx, play_game, game);
	mlx_hook(game->mlx.win, K_EXIT, 0, exit_game, game);
	mlx_hook(game->mlx.win, K_PRESS, 0, key_press, game);
	mlx_hook(game->mlx.win, K_REL, 0, key_release, game);
	mlx_hook(game->mlx.win, MS_MOVE, 0, ms_move, game);
	mlx_loop(game->mlx.mlx);
}
