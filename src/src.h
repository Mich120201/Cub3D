/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:27:30 by mich              #+#    #+#             */
/*   Updated: 2023/05/16 16:22:42 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

# include "../h_file/cub3d.h"
# include "animation.h"
# include "cast_sprite.h"
# include "control.h"
# include "exit.h"
# include "file.h"
# include "game.h"
# include "gnl.h"
# include "init.h"
# include "key.h"
# include "map.h"
# include "minimap.h"
# include "mouse.h"
# include "move.h"
# include "player.h"
# include "ray_cast.h"
# include "read.h"
# include "sort.h"
# include "sprites.h"
# include "texture.h"
# include "wall.h"
# include "../mlx_linux/mlx.h"

void	free_all(t_game *game);

#endif
