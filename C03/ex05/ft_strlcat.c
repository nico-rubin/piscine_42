/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 10:57:06 by nrubin            #+#    #+#             */
/*   Updated: 2020/09/15 19:18:01 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <string.h>

int				ft_strle(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	s_len;
	long			nb;
	unsigned int	i;

	i = 0;
	d_len = (unsigned int)ft_strle(dest);
	s_len = (unsigned int)ft_strle(src);
	nb = size;
	if (size < d_len)
		return (s_len + nb);
	while (src[i] && (d_len + i) < (nb - 1))
	{
		dest[d_len + i] = src[i];
		i++;
	}
	dest[d_len + i] = 0;
	return (s_len + d_len);
}
