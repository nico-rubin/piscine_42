/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/10 18:27:29 by nrubin            #+#    #+#             */
/*   Updated: 2020/09/14 16:04:56 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int			ft_is_lowercase(char c)
{
	return (c >= 'a' && c <= 'z');
}

int			ft_is_alphanumeric(char c)
{
	return ((c >= 'a' && c <= 'z')
			|| (c >= 'A' && c <= 'Z')
			|| (c >= '0' && c <= '9'));
}

int			ft_is_uppercase(char c)
{
	return (c >= 'A' && c <= 'Z');
}

char		*ft_strcapitalize(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (i == 0 && ft_is_lowercase(str[i]))
			str[i] -= 32;
		else if (i != 0 && !ft_is_alphanumeric(str[i - 1])
				&& ft_is_lowercase(str[i]))
			str[i] -= 32;
		else if (i != 0 && ft_is_alphanumeric(str[i - 1])
				&& ft_is_uppercase(str[i]))
			str[i] += 32;
	}
	return (str);
}
