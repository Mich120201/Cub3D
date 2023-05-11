/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 14:37:28 by mich              #+#    #+#             */
/*   Updated: 2023/05/03 12:03:53 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include "src.h"

int		get_next_line(int fd, char **line);

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

int		ft_linelen(char *line);
int		ft_newread(int fd, char **oldread);
char	*ft_getline(int len, char *read);
char	*ft_clearline(int len, char *read);

#endif
