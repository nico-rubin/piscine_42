/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/09 12:38:10 by nrubin            #+#    #+#             */
/*   Updated: 2020/09/09 14:20:17 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_rev_int_tab(int *tab, int size)
{
	int i;
	int k;
	int tmp;

	i = 0;
	k = size / 2;
	while (size > k)
	{
		tmp = tab[size - 1];
		tab[size - 1] = tab[i];
		tab[i] = tmp;
		size--;
		i++;
	}
}
