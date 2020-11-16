/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_show_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 15:30:45 by nrubin            #+#    #+#             */
/*   Updated: 2020/09/23 16:49:59 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_stock_str.h"

void				ft_putchar(char c)
{
	write(1, &c, 1);
}

void				ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		ft_putchar(str[i++]);
}

void				ft_putnbr(int nbr)
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

void				ft_show_tab(struct s_stock_str *par)
{
	int	i;

	i = 0;
	while (par[i].str)
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}
