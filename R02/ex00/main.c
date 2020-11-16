/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 12:34:20 by ali               #+#    #+#             */
/*   Updated: 2020/09/27 14:41:02 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

char	*ft_set_up(int ac, char **av)
{
	char	*nb;

	if (ft_error(ac, av) == 1)
		return (NULL);
	if (ac == 2)
		nb = set_number(av[1]);
	else
		nb = set_number(av[2]);
	return (nb);
}

void	ft_display_zero(t_dico *dico)
{
	char	str[2];
	int		index;

	str[0] = '0';
	str[1] = '\0';
	index = 0;
	while (dico[index].number != 0 && ft_strcmp(str, dico[index].number) != 0)
		index++;
	if (dico[index].number == 0)
		write(1, "Error\n", 6);
	else
	{
		ft_putstr(dico[index].string);
		write(1, "\n", 1);
	}
}

int		main(int ac, char **av)
{
	t_dico	*dico;
	int		size;
	char	**tab;
	char	*nb;

	if (!(nb = ft_set_up(ac, av)))
		return (1);
	if (!(dico = ft_format_dico(ac, av)))
	{
		write(1, "Dict Error\n", 11);
		return (1);
	}
	if (nb[0] == '0')
	{
		ft_display_zero(dico);
		return (0);
	}
	size = ft_get_sizeof_malloc(nb, ft_strlen(nb) - 1);
	tab = malloc(sizeof(char *) * (size + 1));
	ft_fill_tab(nb, ft_strlen(nb) - 1, tab, dico);
	if (ft_check_empty_strings_tab(size, tab) == 1)
		write(1, "Error\n", 6);
	else
		ft_display(tab);
	ft_freeall(tab, dico, nb);
}
