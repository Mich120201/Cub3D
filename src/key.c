/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:37:06 by mich              #+#    #+#             */
/*   Updated: 2023/05/05 12:33:12 by mich             ###   ########.fr       */
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
