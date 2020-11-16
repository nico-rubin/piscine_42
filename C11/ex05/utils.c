/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:04:39 by nrubin            #+#    #+#             */
/*   Updated: 2020/10/01 11:39:29 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(long nbr)
{
	long u_nbr;

	if (nbr < 0)
	{
		u_nbr = (-1 * nbr);
		ft_putchar('-');
	}
	else
		u_nbr = (long)nbr;
	if (u_nbr >= 10)
	{
		ft_putnbr(u_nbr / 10);
		ft_putnbr(u_nbr % 10);
	}
	else
		ft_putchar(u_nbr + '0');
}

long	ft_atoi(char *str)
{
	long	res;
	long	neg;

	neg = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (*str >= '0' && *str <= '9')
	{
		res = res * 10 + (*str - '0');
		str++;
	}
	return (res * neg);
}
