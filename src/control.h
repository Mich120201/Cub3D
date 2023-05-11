/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 12:50:31 by mich              #+#    #+#             */
/*   Updated: 2023/05/03 12:03:56 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTROL_H
# define CONTROL_H

# include "src.h"

/*control_data.c*/
void	control_data(t_game *game);
void	control_color(t_game *game);
/*control_line.c*/
void	control_fst_lst_line(char *line, int i, t_game *game);
void	control_line(char *line, int i, t_game *game, int j);
/*control_map.c*/
int		control_map(t_game *game, int i);
/*file.c*/
void	valid_file(t_game *game);

#endif
