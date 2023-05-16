/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 10:23:25 by mich              #+#    #+#             */
/*   Updated: 2023/05/16 15:08:03 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILE_H
# define FILE_H

# include "src.h"

/*file.h*/
void	valid_file(t_game *game);
void	open_file(t_game *game);
void	close_file(t_game *game);

#endif
