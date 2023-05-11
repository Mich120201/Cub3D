/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 14:01:19 by mvolpi            #+#    #+#             */
/*   Updated: 2023/04/28 11:52:39 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/libft.h"

size_t	ft_strlen(const char *s)
{
	int	l;

	l = 0;
	while (s[l] != '\0')
		l++;
	return (l);
}

int	ft_sarsize(char **tocount)
{
	int	j;

	j = -1;
	if (!tocount)
		return (0);
	while (tocount[++j])
		;
	return (j);
}
