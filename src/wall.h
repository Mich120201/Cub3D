/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 12:09:03 by mich              #+#    #+#             */
/*   Updated: 2023/05/16 15:24:22 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WALL_H
# define WALL_H

# include "src.h"

/*wall.c*/
void	step_side(t_game *game, t_math *math);
void	dist_ray(t_game *game, t_math *math);
void	count_pixel(t_game *game, t_math *math);

#endif

