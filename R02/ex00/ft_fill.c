/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fill.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 12:15:17 by nrubin            #+#    #+#             */
/*   Updated: 2020/09/27 12:15:41 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char	*ft_fill_unity(char c, t_dico *dico)
{
	int		index;
	char	*str;

	index = ft_search_unity(c, dico);
	if (index == -1)
		return (NULL);
	else
		str = ft_strdup(dico[index].string);
	return (str);
}

char	*ft_fill_illion(int size, t_dico *dico)
{
	int		index;
	char	*str;

	index = ft_search_illion(size, dico);
	if (index == -1)
		return (NULL);
	else
		str = ft_strdup(dico[index].string);
	return (str);
}

char	*ft_fill_ten(char c0, char c1, t_dico *dico)
{
	int		index;
	char	*str;

	index = ft_search_ten(c0, c1, dico);
	if (index == -1)
		return (NULL);
	else
		str = ft_strdup(dico[index].string);
	return (str);
}

char	*ft_fill_hundred(t_dico *dico)
{
	int		index;
	char	*str;

	index = ft_search_hundred(dico);
	if (index == -1)
		return (NULL);
	else
		str = ft_strdup(dico[index].string);
	return (str);
}
