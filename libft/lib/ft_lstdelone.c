/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 14:08:37 by mvolpi            #+#    #+#             */
/*   Updated: 2023/04/28 12:14:21 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/libft.h"

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst == NULL || del == NULL)
		return ;
	del(lst->content);
	free(lst);
}

void	ft_sarfree(char **sar, int y)
{
	int	x;

	x = -1;
	if (!sar)
		return ;
	while (++x < y)
	{
		if (sar[x])
		{
			free(sar[x]);
			sar[x] = NULL;
		}
	}
	if (sar)
	{
		free(sar);
		sar = NULL;
	}
}
