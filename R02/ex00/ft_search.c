/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_search.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:16:55 by ali               #+#    #+#             */
/*   Updated: 2020/09/27 14:16:06 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int		ft_search_unity(char c, t_dico *dico)
{
	int		index;
	char	str[2];

	str[0] = c;
	str[1] = '\0';
	index = 0;
	while (dico[index].number && ft_strcmp(dico[index].number, str) != 0)
		index++;
	if (dico[index].number == 0)
		return (-1);
	else
		return (index);
}

int		ft_search_illion(int size, t_dico *dico)
{
	int		index;
	char	str[size + 2];
	int		i;

	str[0] = '1';
	i = 1;
	while (i < size + 1)
	{
		str[i] = '0';
		i++;
	}
	str[i] = '\0';
	index = 0;
	while (dico[index].number && ft_strcmp(dico[index].number, str) != 0)
		index++;
	if (dico[index].number == 0)
		return (-1);
	else
		return (index);
}

int		ft_search_ten(char c0, char c1, t_dico *dico)
{
	char	str[3];
	int		index;

	str[0] = c0;
	str[2] = '\0';
	if (c0 == '1')
		str[1] = c1;
	else
		str[1] = '0';
	index = 0;
	while (dico[index].number && ft_strcmp(dico[index].number, str) != 0)
		index++;
	if (dico[index].number == 0)
		return (-1);
	else
		return (index);
}

int		ft_search_hundred(t_dico *dico)
{
	char	str[4];
	int		index;

	str[0] = '1';
	str[1] = '0';
	str[2] = '0';
	str[3] = '\0';
	index = 0;
	while (dico[index].number && ft_strcmp(dico[index].number, str) != 0)
		index++;
	if (dico[index].number == 0)
		return (-1);
	else
		return (index);
}

void	ft_fill_tab(char *nb, int size, char **tab, t_dico *dico)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	while (nb[j])
	{
		if ((size - j) % 3 == 0)
		{
			if ((j == 0 || nb[j - 1] != '1') && nb[j] != '0')
				tab[i++] = ft_fill_unity(nb[j], dico);
			if (j != size && (nb[j] != '0' || (j > 0 && nb[j - 1] != '0')
						|| (j > 1 && nb[j - 2] != '0')))
				tab[i++] = ft_fill_illion(size - j, dico);
		}
		else if ((size - j) % 3 == 1 && nb[j] != '0')
			tab[i++] = ft_fill_ten(nb[j], nb[j + 1], dico);
		else if ((size - j) % 3 == 2 && nb[j] != '0')
		{
			tab[i++] = ft_fill_unity(nb[j], dico);
			tab[i++] = ft_fill_hundred(dico);
		}
		j++;
	}
}
