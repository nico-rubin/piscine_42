/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 17:26:44 by mchibane          #+#    #+#             */
/*   Updated: 2020/09/27 12:04:11 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

void	ft_freeall(char **tab, t_dico *dico, char *nb)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	i = 0;
	while (dico[i].number)
	{
		free(dico[i].number);
		free(dico[i].string);
		i++;
	}
	free(dico);
	free(nb);
}
