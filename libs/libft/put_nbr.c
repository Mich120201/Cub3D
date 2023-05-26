/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_nbr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvolpi <mvolpi@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/14 11:14:45 by mvolpi            #+#    #+#             */
/*   Updated: 2022/03/14 11:14:51 by mvolpi           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	writenbr(long long nbr, int fd)
{
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		writenbr(nbr * -1, fd);
	}
	else if (nbr > 0)
	{
		writenbr(nbr / 10, fd);
		ft_putchar_fd('0' + (nbr % 10), fd);
	}
}

void	ft_putnbr_fd(int nbr, int fd)
{
	if (nbr == 0)
		ft_putchar_fd('0', fd);
	else
		writenbr(nbr, fd);
}

void	ft_putlong_fd(long nbr, int fd)
{
	if (nbr == 0)
		ft_putchar_fd('0', fd);
	else
		writenbr(nbr, fd);
}
