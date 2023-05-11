/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:50:08 by mich              #+#    #+#             */
/*   Updated: 2023/05/09 11:34:15 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "control.h"

int	ft_strend_cmp(char *name, char *end)
{
	size_t	name_len;
	size_t	ext_len;

	name_len = ft_strlen(name);
	ext_len = ft_strlen(end);
	if (name_len <= ext_len)
		return (0);
	name += name_len - ext_len;
	while (*name)
	{
		if (*name != *end)
			return (0);
		name++;
		end++;
	}
	return (1);
}

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
