/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 21:00:11 by nrubin            #+#    #+#             */
/*   Updated: 2020/09/17 15:03:20 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

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
	while (base[i++])
	{
		if (base[i] == '+' || base[i] == '-' || base[i] == 32 ||
				(base[i] >= 9 && base[i] <= 13))
			return (1);
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

int		ft_is_in_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i++])
	{
		if (c == base[i])
			return (1);
	}
	return (0);
}

int		ft_base_index(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i++])
	{
		if (c == base[i])
			return (i);
	}
	return (0);
}

int		ft_atoi_base(char *str, char *base)
{
	int	res;
	int	neg;

	neg = 1;
	res = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '-')
			neg *= -1;
		str++;
	}
	while (ft_is_in_base(*str, base))
	{
		res = res * ft_strlen(base) + ft_base_index(*str, base);
		str++;
	}
	return (res * neg);
}
