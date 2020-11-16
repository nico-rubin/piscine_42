/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 14:59:53 by nrubin            #+#    #+#             */
/*   Updated: 2020/10/01 13:30:04 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

void	add(char *x, char *y)
{
	ft_putnbr(ft_atoi(x) + ft_atoi(y));
	write(1, "\n", 1);
}

void	sub(char *x, char *y)
{
	ft_putnbr(ft_atoi(x) - ft_atoi(y));
	write(1, "\n", 1);
}

void	mult(char *x, char *y)
{
	ft_putnbr(ft_atoi(x) * ft_atoi(y));
	write(1, "\n", 1);
}

void	div(char *x, char *y)
{
	ft_putnbr(ft_atoi(x) / ft_atoi(y));
	write(1, "\n", 1);
}

void	mod(char *x, char *y)
{
	ft_putnbr(ft_atoi(x) % ft_atoi(y));
	write(1, "\n", 1);
}
