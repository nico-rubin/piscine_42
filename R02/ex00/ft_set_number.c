/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_number.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 11:38:12 by ali               #+#    #+#             */
/*   Updated: 2020/09/27 12:27:59 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char	*skip_to_number(char *str)
{
	while (*str == '0' && *(str + 1) != '\0')
	{
		str++;
	}
	return (str);
}

char	*set_number(char *src)
{
	int		i;
	int		j;
	char	*dst;
	char	*str;

	i = 0;
	j = 0;
	if (ft_strlen(src) > 1)
		str = skip_to_number(src);
	else
		str = src;
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (!(dst = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	while (*str && i > 0)
	{
		dst[j] = *str;
		j++;
		str++;
		i--;
	}
	dst[j] = 0;
	return (dst);
}
