/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:06:13 by nrubin            #+#    #+#             */
/*   Updated: 2020/10/01 13:29:21 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft.h"

int	ft_checks(int argc, char **argv)
{
	if (argc != 4)
		return (0);
	if (argv[2][1] != 0 || !(argv[2][0] == '+' || argv[2][0] == '-' ||
				argv[2][0] == '/' || argv[2][0] == '%' || argv[2][0] == '*'))
	{
		write(1, "0\n", 2);
		return (0);
	}
	if (argv[2][0] == '/' && ft_atoi(argv[3]) == 0)
	{
		write(1, "Stop : Division by zero\n", 24);
		return (0);
	}
	if (argv[2][0] == '%' && ft_atoi(argv[3]) == 0)
	{
		write(1, "Stop : Modulo by zero\n", 22);
		return (0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	if (ft_checks(argc, argv) == 0)
		return (0);
	if (argv[2][0] == '+')
		add(argv[1], argv[3]);
	else if (argv[2][0] == '-')
		sub(argv[1], argv[3]);
	else if (argv[2][0] == '*')
		mult(argv[1], argv[3]);
	else if (argv[2][0] == '/')
		div(argv[1], argv[3]);
	else if (argv[2][0] == '%')
		mod(argv[1], argv[3]);
	return (0);
}
