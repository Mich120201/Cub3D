/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   src.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 11:27:30 by mich              #+#    #+#             */
/*   Updated: 2023/05/09 10:41:02 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SRC_H
# define SRC_H

# include "../h_file/cub3d.h"
# include "control.h"
# include "exit.h"
# include "game.h"
# include "gnl.h"
# include "init.h"
# include "key.h"
# include "map.h"
# include "mouse.h"
# include "player.h"
# include "read.h"
# include "sprites.h"
# include "texture.h"
# include "../mlx_linux/mlx.h"

void	free_all(t_game *game);

#endif
