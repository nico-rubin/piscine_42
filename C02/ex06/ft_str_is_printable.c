/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_printable.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 17:13:05 by nrubin            #+#    #+#             */
/*   Updated: 2020/09/12 17:47:56 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_str_is_empty(char *str)
{
	while (*str)
		return (1);
	return (0);
}

int	ft_str_is_printable(char *str)
{
	int	i;

	i = 0;
	if (ft_str_is_empty(str) == 0)
		return (1);
	while (*str)
	{
		if (*str >= 0 && *str <= 31)
			return (0);
		str++;
	}
	return (1);
}
