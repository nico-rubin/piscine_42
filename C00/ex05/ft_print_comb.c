/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_com.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/08 14:03:23 by nrubin            #+#    #+#             */
/*   Updated: 2020/09/09 10:41:32 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putint(int i)
{
	write(1, &i, 1);
}

void	ft_print_comb(void)
{
	int i;
	int j;
	int k;

	i = -1;
	while (++i < 10)
	{
		j = i;
		while (++j < 10)
		{
			k = j;
			while (++k <= 9)
			{
				ft_putint(i + '0');
				ft_putint(j + '0');
				ft_putint(k + '0');
				if (i < 7)
					write(1, ", ", 2);
			}
		}
	}
}
