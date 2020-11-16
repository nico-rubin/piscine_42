/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 12:05:39 by nrubin            #+#    #+#             */
/*   Updated: 2020/09/27 14:29:00 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int		ft_strcmp(char *str1, char *str2)
{
	while (*str1 == *str2 && *str1 != 0 && *str2 != 0)
	{
		str1++;
		str2++;
	}
	return ((unsigned char)*str1 - (unsigned char)*str2);
}

int		ft_strlen(char *str)
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

char	*ft_strdup(char *str)
{
	char	*dst;
	int		i;

	i = 0;
	if (!(dst = malloc(sizeof(char) * (ft_strlen(str) + 1))))
		return (NULL);
	while (str[i])
	{
		dst[i] = str[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int		ft_check_double(t_dico *dico)
{
	int	i;
	int j;

	i = 0;
	while (dico[i].number)
	{
		j = 0;
		while (dico[j].number)
		{
			if (dico[j].number && dico[i].number && i != j
					&& ft_strcmp(dico[i].number, dico[j].number) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
