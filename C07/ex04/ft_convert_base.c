/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 18:32:31 by nrubin            #+#    #+#             */
/*   Updated: 2020/09/29 18:47:33 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

int		ft_atoi_base(char *str, char *base);

char	*ft_rev_int_tab(char *tab, int size)
{
	int		i;
	char	tmp;

	i = 0;
	if (size == 0)
		size++;
	while (i < size / 2)
	{
		tmp = tab[i];
		tab[i] = tab[size - 1 - i];
		tab[size - 1 - i] = tmp;
		i++;
	}
	tab[size] = '\0';
	return (tab);
}

int		check_base(char *str)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (str[i])
	{
		while (str[j])
		{
			if ((str[j] == '+' || str[j] == '-') ||
					(str[i] == str[j] && i != j) ||
					(str[j] >= 9 && str[j] <= 13) ||
					(str[j] == ' '))
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_putnbr_base(int nb, char *base, char *tab)
{
	int		size_base;
	int		i;
	int		neg;
	long	nbr;

	neg = 1;
	i = 0;
	size_base = ft_strlen(base);
	nbr = nb;
	if (nb < 0)
	{
		neg = -1;
		nbr = -nb;
	}
	if (nbr == 0)
		tab[i] = base[nbr % size_base];
	while (nbr)
	{
		tab[i++] = base[nbr % size_base];
		nbr /= size_base;
	}
	if (neg < 0)
		tab[i++] = '-';
	return (ft_rev_int_tab(tab, i));
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		len1;
	int		len2;
	char	*tab;
	int		nombre;

	len1 = ft_strlen(base_to);
	len2 = ft_strlen(base_from);
	tab = malloc(20 * sizeof(char));
	if ((check_base(base_to) == 1) || (check_base(base_from) == 1) ||
			len1 < 2 || len2 < 2)
		return (NULL);
	nombre = ft_atoi_base(nbr, base_from);
	ft_putnbr_base(nombre, base_to, tab);
	return (tab);
}
