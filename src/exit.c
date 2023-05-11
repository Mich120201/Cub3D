/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:27:56 by mich              #+#    #+#             */
/*   Updated: 2023/05/09 12:06:30 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "exit.h"

void	free_all(t_game *game)
{
	if (game->count.line)
		free(game->count.line);
	game->count.line = NULL;
	ft_sarfree(game->map.map, ft_sarsize(game->map.map));
	if (game->save.nord)
		free(game->save.nord);
	if (game->save.sud)
		free(game->save.sud);
	if (game->save.est)
		free(game->save.est);
	if (game->save.ovest)
		free(game->save.ovest);
	if (game->save.f)
		ft_sarfree(game->save.f, ft_sarsize(game->save.f));
	if (game->save.c)
		ft_sarfree(game->save.c, ft_sarsize(game->save.c));
}

int	exit_game(t_game *game, int n, char *msg)
{
	printf("%s", msg);
	free_all(game);
	exit(n);
}
