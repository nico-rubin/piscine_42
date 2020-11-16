/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 13:04:40 by nrubin            #+#    #+#             */
/*   Updated: 2020/10/01 13:20:24 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_asc_sorted(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (++i < length)
		if (f(tab[i - 1], tab[i]) > 0)
			return (0);
	return (1);
}

int		ft_desc_sorted(int *tab, int length, int (*f)(int, int))
{
	int	i;

	i = 0;
	while (++i < length)
		if (f(tab[i - 1], tab[i]) < 0)
			return (0);
	return (1);
}

int		ft_is_sort(int *tab, int length, int (*f)(int, int))
{
	return (ft_asc_sorted(tab, length, f) || ft_desc_sorted(tab, length, f));
}
