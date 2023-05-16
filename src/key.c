/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:37:06 by mich              #+#    #+#             */
/*   Updated: 2023/05/16 16:21:38 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "key.h"

int	key_press(int key, t_game *game)
{
	if (key == K_ESC)
		game->key.k_esc = 1;
	else if (key == K_W)
		game->key.k_up = 1;
	else if (key == K_S)
		game->key.k_down = 1;
	else if (key == K_A)
		game->key.k_left = 1;
	else if (key == K_D)
		game->key.k_right = 1;
	else if (key == A_RIGHT)
		game->key.turn_right = 1;
	else if (key == A_LEFT)
		game->key.turn_left = 1;
	return (0);
}

int	key_release(int key, t_game *game)
{
	if (key == K_ESC)
		game->key.k_esc = 0;
	else if (key == K_W)
		game->key.k_up = 0;
	else if (key == K_S)
		game->key.k_down = 0;
	else if (key == K_A)
		game->key.k_left = 0;
	else if (key == K_D)
		game->key.k_right = 0;
	else if (key == A_RIGHT)
		game->key.turn_right = 0;
	else if (key == A_LEFT)
		game->key.turn_left = 0;
	return (0);
}

void	key(t_game *game)
{
	if (game->key.k_up)
		up(game);
	if (game->key.k_down)
		down(game);
	if (game->key.k_right)
		right(game);
	if (game->key.k_left)
		left(game);
	if (game->key.turn_right)
		turn_right(game);
	if (game->key.turn_left)
		turn_left(game);
	if (game->key.k_esc)
		exit_game(game, 0, "YOU WIN!!\n");
	if (game->key.k_door)
		door(game);
	mouse(game);
}
