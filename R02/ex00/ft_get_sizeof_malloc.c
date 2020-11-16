/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_sizeof_malloc.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:24:15 by mchibane          #+#    #+#             */
/*   Updated: 2020/09/27 12:16:28 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void	ft_units(char *nb, int *count, int index)
{
	if (index > 0 && nb[index - 1] == '1' && nb[index + 1] != '\0')
		(*count)++;
	else if (nb[index] != '0')
	{
		if (nb[index + 1] == '\0')
		{
			if (index > 0 && nb[index - 1] != '1')
				(*count)++;
			if (index == 0)
				(*count)++;
		}
		else
			(*count) += 2;
	}
	else if (nb[index + 1] != '\0' && (nb[index] != '0' ||
			(index > 0 && nb[index - 1] != '0') ||
			(index > 1 && nb[index - 2] != '0')))
		(*count)++;
}

void	ft_dozens(char *nb, int *count, int index)
{
	if (nb[index] != '0')
		(*count)++;
}

void	ft_hundreds(char *nb, int *count, int index)
{
	if (nb[index] != '0')
		(*count) += 2;
}

int		ft_get_sizeof_malloc(char *nb, int size)
{
	int i;
	int count[1];

	*count = 0;
	i = 0;
	while (nb[i])
	{
		if ((size - i) % 3 == 0)
			ft_units(nb, count, i);
		else if ((size - i) % 3 == 1)
			ft_dozens(nb, count, i);
		else
			ft_hundreds(nb, count, i);
		i++;
	}
	return (*count);
}
