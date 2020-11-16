/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 12:29:20 by nrubin            #+#    #+#             */
/*   Updated: 2020/09/22 12:31:06 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_sqrt(int nb)
{
	long	i;
	long	n;

	i = 0;
	n = nb;
	while ((i * i) <= n)
	{
		if ((i * i) == n)
			return (i);
		i++;
	}
	return (i);
}

int	ft_is_prim(int nb)
{
	int	i;

	i = ft_sqrt(nb);
	if (nb < 2)
		return (0);
	if (nb == 2)
		return (1);
	while (i > 1)
	{
		if (nb % i == 0)
			return (0);
		i--;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (ft_is_prim(nb))
		return (nb);
	return (ft_find_next_prime(nb + 1));
}
