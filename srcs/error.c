/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/29 09:00:52 by mich              #+#    #+#             */
/*   Updated: 2023/05/29 09:00:53 by mich             ###   ########.fr       */
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
