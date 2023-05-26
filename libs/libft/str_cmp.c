/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_cmp.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:15:56 by mvolpi            #+#    #+#             */
/*   Updated: 2022/03/14 11:16:04 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	if (n == 0)
		return (0);
	while (*str1 != '\0' && *str2 != '\0' && n--)
	{
		if (*str1 != *str2)
			return ((unsigned char)*str1 - (unsigned char)*str2);
		str1++;
		str2++;
	}
	if (n != 0 && (*str1 == '\0' || *str2 == '\0'))
		return ((unsigned char)*str1 - (unsigned char)*str2);
	return (0);
}

int	ft_strend_cmp(char *name, char *end)
{
	int	name_len;
	int	ext_len;

	name_len = ft_strlen(name);
	ext_len = ft_strlen(end);
	if (name_len <= ext_len)
		return (0);
	name += name_len - ext_len;
	while (*name)
	{
		if (*name != *end)
			return (0);
		name++;
		end++;
	}
	return (1);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	int	i;

	if (*little == '\0')
		return ((char *)big);
	while (*big != '\0' && len > 0)
	{
		if (*big == *little)
		{
			i = 0;
			while (little[i] != '\0' && len - i > 0)
			{
				if (little[i] != big[i])
					break ;
				i++;
			}
			if (little[i] == '\0')
				return ((char *)big);
		}
		len--;
		big++;
	}
	return (NULL);
}
