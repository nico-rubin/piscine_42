/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_dico.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 10:23:21 by ali               #+#    #+#             */
/*   Updated: 2020/09/27 12:37:13 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int		ft_stock_file(int fd, int size, char **raw)
{
	char	buffer[28000];
	int		bytes;
	int		lines;

	if (!(*raw = malloc((sizeof(char) + 1) * size)))
		return (-1);
	*raw[0] = '\0';
	lines = 0;
	while ((bytes = read(fd, buffer, 28000)))
	{
		ft_strncat(*raw, buffer, bytes);
	}
	lines = ft_count_lines(*raw);
	return (lines);
}

char	*ft_stock_number(char *raw)
{
	int		i;
	int		size;
	char	*number;

	i = 0;
	size = ft_numlen(raw);
	number = malloc((size + 1) * sizeof(char));
	while (i < size)
	{
		number[i] = raw[i];
		i++;
	}
	number[i] = '\0';
	return (number);
}

char	*ft_stock_string(char *raw)
{
	int		i;
	int		size;
	char	*string;

	i = 0;
	size = ft_stringlen(raw);
	string = malloc((size + 1) * sizeof(char));
	while (i < size)
	{
		string[i] = raw[i];
		i++;
	}
	string[i] = '\0';
	return (string);
}

t_dico	*ft_make_dico(char *raw, int lines)
{
	t_dico	*dico;
	int		i;

	i = -1;
	dico = malloc((1 + lines) * sizeof(t_dico));
	while (++i < lines)
	{
		while (*raw < '0' || *raw > '9')
			raw++;
		dico[i].number = ft_stock_number(raw);
		while (*raw <= '9' && *raw >= '0')
			raw++;
		raw = ft_pass_middle(raw);
		dico[i].string = ft_stock_string(raw);
		while (*raw != '\n')
			raw++;
	}
	dico[i].number = 0;
	return (dico);
}
