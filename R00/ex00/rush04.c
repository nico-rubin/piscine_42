/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mchibane <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/12 11:31:40 by mchibane          #+#    #+#             */
/*   Updated: 2020/09/12 16:23:52 by mchibane         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c);

void	print_line(int x, char a, char b, char c)
{
	int col;

	col = 1;
	while (col <= x)
	{
		if (col == 1)
			ft_putchar(a);
		else if (col == x)
			ft_putchar(c);
		else
			ft_putchar(b);
		col++;
	}
}

void	rush(int x, int y)
{
	int line;

	if (x <= 0 || y <= 0)
		return ;
	line = 1;
	while (line <= y)
	{
		if (line == 1)
		{
			print_line(x, 'A', 'B', 'C');
			ft_putchar('\n');
		}
		else if (line == y)
		{
			print_line(x, 'C', 'B', 'A');
			ft_putchar('\n');
		}
		else
		{
			print_line(x, 'B', ' ', 'B');
			ft_putchar('\n');
		}
		line++;
	}
}
