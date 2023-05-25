/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tde-nico <tde-nico@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/06 11:27:39 by tde-nico          #+#    #+#             */
/*   Updated: 2022/09/07 10:50:59 by tde-nico         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*null_error(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
	return (NULL);
}

t_map	*map_error(t_map *map, char **file, char *str)
{
	free_map(map);
	free_matrix(file);
	return ((t_map *)null_error(str));
}
