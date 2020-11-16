/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stock_dico2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ali <marvin@42.fr>                         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 16:15:35 by ali               #+#    #+#             */
/*   Updated: 2020/09/27 14:32:10 by ali              ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush_02.h"

int		ft_open_dico(int ac, char **av)
{
	int fd;

	fd = 0;
	if (ac == 2)
	{
		fd = open("numbers.dict", O_RDONLY);
	}
	else if (ac == 3)
	{
		fd = open(av[1], O_RDONLY);
	}
	return (fd);
}

t_dico	*ft_format_dico(int ac, char **av)
{
	int		fd;
	char	*raw[1];
	t_dico	*dico;
	int		lines;
	int		size;

	fd = ft_open_dico(ac, av);
	if (fd == -1)
		return (NULL);
	size = ft_filelen(fd);
	if (size == -1)
		return (NULL);
	fd = (ac == 2 ? open("numbers.dict", O_RDONLY) : open(av[1], O_RDONLY));
	lines = ft_stock_file(fd, size, raw);
	dico = ft_make_dico(*raw, lines);
	if (ft_check_double(dico) == 0)
		return (NULL);
	return (dico);
}
