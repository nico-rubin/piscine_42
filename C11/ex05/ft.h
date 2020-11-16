/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrubin <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 15:02:49 by nrubin            #+#    #+#             */
/*   Updated: 2020/10/01 13:27:41 by nrubin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_H

# define FT_H

# include <unistd.h>

void	add(char *x, char *y);
void	sub(char *x, char *y);
void	mult(char *x, char *y);
void	div(char *x, char *y);
void	mod(char *x, char *y);
void	ft_putchar(char c);
void	ft_putnbr(long nbr);
long	ft_atoi(char *str);

#endif
