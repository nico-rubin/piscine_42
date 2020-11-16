/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 10:23:01 by ali               #+#    #+#             */
/*   Updated: 2020/09/27 12:36:25 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int		ft_filelen(int fd)
{
	char	buffer[28000];
	int		i;
	ssize_t	ok;

	i = 0;
	while ((ok = read(fd, buffer, 28000)))
	{
		if (ok == -1)
			return (-1);
		i += ok;
	}
	close(fd);
	return (i);
}

char	*ft_strncat(char *dest, char *src, unsigned int nb)
{
	int				count;
	unsigned int	count2;

	count = 0;
	count2 = 0;
	while (dest[count] != '\0')
		count++;
	while (count2 < nb && src[count2] != '\0')
	{
		dest[count] = src[count2];
		count++;
		count2++;
	}
	dest[count] = '\0';
	return (dest);
}

int		ft_count_lines(char *raw)
{
	int i;
	int lines;

	lines = 0;
	i = 0;
	while (raw[i])
	{
		if (i != 0 && raw[i] == '\n' && raw[i - 1] != '\n')
			lines++;
		i++;
	}
	return (lines);
}

int		ft_stringlen(char *raw)
{
	int i;

	i = 0;
	while (raw[i] != '\n')
		i++;
	while (raw[i - 1] == ' ')
		i--;
	return (i);
}

int		ft_numlen(char *raw)
{
	int i;

	i = 0;
	while (raw[i] <= '9' && raw[i] >= '0')
		i++;
	return (i);
}
