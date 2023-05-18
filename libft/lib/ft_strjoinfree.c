/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mich <mich@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/18 11:24:45 by mich              #+#    #+#             */
/*   Updated: 2023/05/18 11:24:45 by mich             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_file/libft.h"

char	*ft_strjoinfree(char *s1, char *s2)
{
	char	*joined_str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (s1 == NULL || s2 == NULL)
	{
		free(s1);
		free(s2);
		return (NULL);
	}
	joined_str = (char *) malloc (((sizeof(char))
				* (ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (joined_str == NULL)
		return (NULL);
	while (s1[j] != '\0')
		joined_str[i++] = s1[j++];
	j = 0;
	while (s2[j] != '\0')
		joined_str[i++] = s2[j++];
	joined_str[i] = '\0';
	free(s1);
	free(s2);
	return (joined_str);
}
