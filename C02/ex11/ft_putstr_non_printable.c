/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/13 19:06:23 by nrubin            #+#    #+#             */
/*   Updated: 2020/09/13 19:23:18 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_is_printable(char c)
{
	return (c >= 32 && c < 127);
}

void	ft_print_int_to_hex(int nb)
{
	char *tab;

	tab = "0123456789abcdef";
	if (nb < 16)
		ft_putchar(tab[nb]);
	else
	{
		ft_print_int_to_hex(nb / 16);
		ft_putchar(tab[nb % 16]);
	}
}

void	ft_putstr_non_printable(char *str)
{
	while (*str)
	{
		if (!ft_is_printable(*str))
		{
			ft_putchar('\\');
			if ((unsigned char)*str < 16)
				ft_putchar('0');
			ft_print_int_to_hex((unsigned char)*str);
		}
		else
			ft_putchar(*str);
		str++;
	}
}
