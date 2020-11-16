/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 15:37:21 by mchibane          #+#    #+#             */
/*   Updated: 2020/09/27 14:40:53 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int	ft_error(int ac, char **av)
{
	int		i;
	char	*input_str;

	if (ac > 3 || ac == 1)
	{
		ft_putstr("Error\n");
		return (1);
	}
	else if (ac == 2)
		input_str = av[1];
	else
		input_str = av[2];
	i = 0;
	while (input_str[i])
	{
		if (input_str[i] < '0' || input_str[i] > '9')
		{
			ft_putstr("Error\n");
			return (1);
		}
		i++;
	}
	return (0);
}
