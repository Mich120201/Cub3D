/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:50:08 by mich              #+#    #+#             */
/*   Updated: 2023/05/16 15:07:54 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

void	valid_file(t_game *game)
{
	char	**str;

	str = ft_split(game->data.argv, '.');
	if (game->data.argc == 1)
	{
		ft_sarfree(str, ft_sarsize(str));
		exit_game(game, 1, "Error!! Too few arguments!!\n");
	}
	if (!(ft_strncmp(str[1], "cub", 4) == 0))
	{
		ft_sarfree(str, ft_sarsize(str));
		exit_game(game, 1, "Error!! Map should be a .cub file\n");
	}
	ft_sarfree(str, ft_sarsize(str));
}

void	open_file(t_game *game)
{
	game->map.fd = open(game->data.argv, O_RDONLY);
	if (game->map.fd == -1)
		exit_game(game, 1, "Error opening file!!\n");
}

void	close_file(t_game *game)
{
	if (close(game->map.fd) == -1)
		exit_game(game, 1, "Error closing file!!\n");
}
