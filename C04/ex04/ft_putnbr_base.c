/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 18:34:45 by nrubin            #+#    #+#             */
/*   Updated: 2020/09/17 14:43:48 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int		ft_is_base_valid(char *base)
{
	int	i;
	int	j;

	i = 0;
	if (ft_strlen(base) < 2)
		return (1);
	while (base[i])
	{
		if (base[i] == '+' || base[i] == '-')
			return (1);
		i++;
	}
	i = 0;
	while (base[i])
	{
		j = i + 1;
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_putnbr_base(int nbr, char *base)
{
	unsigned int	size;
	unsigned int	u_nbr;

	if (ft_is_base_valid(base) == 1)
		return ;
	size = (unsigned int)ft_strlen(base);
	if (nbr < 0)
	{
		u_nbr = (-1 * nbr);
		ft_putchar('-');
	}
	else
		u_nbr = (unsigned int)nbr;
	if (u_nbr >= 10)
	{
		ft_putnbr_base((u_nbr / size), base);
		ft_putchar(base[u_nbr % size]);
	}
	else
		ft_putchar(base[u_nbr]);
}
