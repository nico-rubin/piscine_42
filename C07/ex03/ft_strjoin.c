/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:39:45 by nrubin            #+#    #+#             */
/*   Updated: 2020/09/29 18:35:53 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_join(int size, char **strs, char *sep, int dest_len)
{
	char	*dest;
	int		i;
	int		j;
	int		k;

	if (!(dest = malloc(sizeof(dest) * (dest_len + 1))))
		return (0);
	i = -1;
	while (++i < size)
	{
		j = 0;
		while (strs[i] && strs[i][j])
		{
			*dest = strs[i][j++];
			dest++;
		}
		k = 0;
		while (sep[k] && i < size - 1)
		{
			*dest = sep[k++];
			dest++;
		}
	}
	*dest = '\0';
	return (dest - dest_len);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int	i;
	int	dest_len;

	i = 0;
	dest_len = 0;
	if (size > 0)
	{
		while (i < size && strs[i])
		{
			dest_len += ft_strlen(strs[i]);
			i++;
		}
		dest_len += ft_strlen(sep) * (size - 1);
	}
	return (ft_join(size, strs, sep, dest_len));
}
