/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/16 13:58:00 by mich              #+#    #+#             */
/*   Updated: 2023/05/16 15:03:00 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SORT_H
# define SORT_H

# include "src.h"

/*sort.c*/
void	sort_close(t_game *game, int *order, double *dist);
void	sort_sprites(int *order, double *dist, int amount);

#endif
