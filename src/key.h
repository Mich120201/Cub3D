/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/04 11:35:56 by mich              #+#    #+#             */
/*   Updated: 2023/05/05 12:33:08 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEY_H
# define KEY_H

# include "src.h"

/*key.c*/
int	key_press(int key, t_game *game);
int	key_release(int key, t_game *game);

#endif
