/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_hex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:14:40 by mvolpi            #+#    #+#             */
/*   Updated: 2022/03/14 11:14:41 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_puthex_fd(unsigned int nbr, int fd)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_puthex_fd(nbr / 16, fd);
		ft_putchar_fd(*(base + (nbr % 16)), 1);
	}
	else
		ft_putchar_fd(*(base + nbr), 1);
}

void	ft_putlonghex_fd(unsigned long nbr, int fd)
{
	char	*base;

	base = "0123456789abcdef";
	if (nbr >= 16)
	{
		ft_putlonghex_fd(nbr / 16, fd);
		ft_putchar_fd(*(base + (nbr % 16)), fd);
	}
	else
		ft_putchar_fd(*(base + nbr), fd);
}

void	ft_putupperhex_fd(unsigned int nbr, int fd)
{
	char	*base;

	base = "0123456789ABCDEF";
	if (nbr >= 16)
	{
		ft_putupperhex_fd(nbr / 16, fd);
		ft_putchar_fd(*(base + (nbr % 16)), 1);
	}
	else
		ft_putchar_fd(*(base + nbr), 1);
}
