/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_fts.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:12:46 by mvolpi            #+#    #+#             */
/*   Updated: 2022/03/14 11:12:53 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*funct)(void *))
{
	while (lst)
	{
		funct(lst->content);
		lst = lst->next;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	del (lst->content);
	free (lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*aux;
	t_list	*new_next;

	aux = *lst;
	if (!*lst)
		return ;
	while (aux)
	{
		new_next = aux->next;
		ft_lstdelone (aux, del);
		aux = new_next;
	}
	*lst = NULL;
}

t_list	*ft_lstmap(t_list *lst, void *(*funct)(void *), void(*del)(void *))
{
	t_list	*output;
	t_list	*og_output;

	if (!lst || !funct)
		return (NULL);
	output = ft_lstnew(funct(lst->content));
	if (output == NULL)
		return (NULL);
	og_output = output;
	lst = lst->next;
	while (lst)
	{
		output->next = ft_lstnew(funct(lst->content));
		if (output == NULL)
		{
			ft_lstclear(&og_output, del);
			return (NULL);
		}
		lst = lst->next;
		output = output->next;
	}
	return (og_output);
}
