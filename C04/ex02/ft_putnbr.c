/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 13:03:06 by nrubin            #+#    #+#             */
/*   Updated: 2020/09/14 13:03:11 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nbr)
{
	unsigned int u_nbr;

	if (nbr < 0)
	{
		u_nbr = (-1 * nbr);
		ft_putchar('-');
	}
	else
		u_nbr = (unsigned int)nbr;
	if (u_nbr >= 10)
	{
		ft_putnbr(u_nbr / 10);
		ft_putnbr(u_nbr % 10);
	}
	else
		ft_putchar(u_nbr + '0');
}
