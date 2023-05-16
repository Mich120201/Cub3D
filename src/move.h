/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 16:21:58 by mich              #+#    #+#             */
/*   Updated: 2023/05/16 16:33:46 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MOVE_H
# define MOVE_H

# include "src.h"

/*door.c*/
void	door(t_game *game);
/*move_turn.c*/
void	turn_right(t_game *game);
void	turn_left(t_game *game);
/*move.c*/
void	up(t_game *game);
void	down(t_game *game);
void	right(t_game *game);
void	left(t_game *game);

#endif
