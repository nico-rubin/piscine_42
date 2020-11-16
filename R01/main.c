/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alamonta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 13:59:06 by alamonta          #+#    #+#             */
/*   Updated: 2020/09/20 22:25:28 by alamonta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>

void print_tab(int tab[6][6], int x, int y)
{
	char c;

	y = 1;
	while (y < 5)
	{
		x = 1;
		while (x < 5)
		{
			c = tab[y][x] + '0';
			write(1, &c, 1);
			write(1, " ", 1);
			x++;
		}
		write(1, "\n", 1);
		y++;
	}
}

void	check_suite_x(int tab[6][6], int x)
{
	if (tab[0][x] == 4)
	{
		tab[1][x] = 1;
		tab[2][x] = 2;
		tab[3][x] = 3;
		tab[4][x] = 4;
	}
	if (tab[5][x] == 4)
	{
		tab[4][x] = 1;
		tab[3][x] = 2;
		tab[2][x] = 3;
		tab[1][x] = 4;
	}
	if (tab[0][x] == 1)
		tab[1][x] = 4;
	if (tab[5][x] == 1)
		tab[4][x] = 4;
}

void	check_suite_y(int tab[6][6], int y)
{
	if (tab[y][0] == 4)
	{
		tab[y][1] = 1;
		tab[y][2] = 2;
		tab[y][3] = 3;
		tab[y][4] = 4;
	}
	if (tab[y][5] == 4)
	{
		tab[y][4] = 1;
		tab[y][3] = 2;
		tab[y][2] = 3;
		tab[y][1] = 4;
	}
	if (tab[y][0] == 1)
	{
		tab[y][1] = 4;
	}
	if (tab[y][5] == 1)
	{
		tab[y][4] = 4;
	}
}

void	check_two(int tab[6][6], int x, int y)
{
	if (tab[0][x] == 2 && tab[4][x] == 4)
		tab[1][x] = 3;
	if (tab[5][x] == 2 && tab[1][x] == 4)
		tab[4][x] = 3;
	if (tab[y][0] == 2 && tab[y][4] == 4)
		tab[y][1] = 3;
	if (tab[y][5] == 2 && tab[y][1] == 4)
		tab[y][4] = 3;
}

void	check_three(int tab[6][6], int x, int y)
{
	if (tab[0][x] == 3 && tab[4][x] == 4)
		tab[1][x] = 1;
		tab[2][x] = 3;
	if (tab[5][x] == 2 && tab[1][x] == 4)
		tab[4][x] = 3;
	if (tab[y][0] == 2 && tab[y][4] == 4)
		tab[y][1] = 3;
	if (tab[y][5] == 2 && tab[y][1] == 4)
		tab[y][4] = 3;
}

void	see_param_x(int tab[6][6], int x, int y)
{
	while (x <= 5)
	{
		check_suite_x(tab, x);
		check_two(tab, x, y);
		x++;
	}
}

void	see_param_y(int tab[6][6], int x, int y)
{
	while (y <= 5)
	{
		check_suite_y(tab, y);
		check_two(tab, x, y);
		y++;
	}
}

void fonction_ligne(int tab[6][6], int x, int y, int pos)
{
	int myst = 10;
	x = 1;
	while (x <= 4)
	{
		myst = myst - tab[y][x];
		x++;
	}
	tab[y][pos] = myst;
}

void fonction_colonne(int tab[6][6], int x, int y, int pos)
{
	int myst = 10;
	y = 1;
	while (y <= 4)
	{
		myst = myst - tab[y][x];
		y++;
	}
	tab[pos][x] = myst;
}


void	detect_alone_vert(int tab[6][6], int x, int y)
{
	int i = 0;
	int pos = 0;

	i = 0;
	pos = 0;
	while (y <= 4)
	{
		x = 1;
		while(x <= 4)
		{
			if (tab[y][x] == 0)
			{
				i++;
				pos = x;
			}
			x++;
		}
		if (i == 1)
			fonction_ligne(tab, x, y, pos);
		i = 0;
		y++;
	}
}

void	detect_alone_hori(int tab[6][6], int x, int y)
{
	int i;
	int pos;
	
	i = 0;
	pos = 0;
	while (x <= 4)
	{
		y = 1;
		while(y <= 4)
		{
			if (tab[y][x] == 0)
			{
				i++;
				pos = y;
			}
			y++;
		}
		if (i == 1)
			fonction_colonne(tab, x, y, pos);
		i = 0;
		x++;
	}
}


int lecture_vert(int tab[6][6], int x, int y)
{
	int i;
	int yes;
	int nb;

	i = 1;
	nb = 0;
	while (i <= 4)
	{	
		yes = 1;
		y = 1;
		while (y < 5 && yes == 1)
		{
			if (tab[y][x] == i)
				yes = 0;
			y++;
		}
		if (yes == 1)
			nb = nb * 10 + i;
		i++;
	}
	return (decrypt(nb));
}


int lecture_hori(int tab[6][6], int x, int y)
{
	int i;
	int yes;
	int nb;

	i = 1;
	nb = 0;
	while (i <= 4)
	{	
		yes = 1;
		x = 1;
		while (x < 5 && yes == 1)
		{
			if (tab[y][x] == i)
				yes = 0;
			x++;
		}
		if (yes == 1)
			nb = nb * 10 + i;
		i++;
	}
	return (decrypt(nb));
}

void	detect_twice_vert(int tab[6][6], int x, int y)
{
	int i;
	int pos;
	
	i = 0;
	pos = 0;
	x = 1;

	while (x <= 4)
	{
		y = 1;

		while(y <= 4)
		{
			if (tab[y][x] == 0)
			{
				i++;
			}
			y++;
		}
		if (i == 2)

			lecture_hori(tab, x, y);

		i = 0;
		x++;
	}
}

void	detect_twice_hori(int tab[6][6], int x, int y)
{
	int i;
	int pos;
	
	i = 0;
	pos = 0;
	y = 1;
	while (y <= 4)
	{
		x = 1;
		while(x <= 4)
		{
			if (tab[y][x] == 0)
			{
				i++;
			}
			x++;
		}
		if (i == 2)
			lecture_hori(tab, x, y);
		i = 0;
		y++;
	}
}


int main()
{
	/*int tab[6][6] = {{0, 4, 3, 2, 1, 0},
					{4, 0, 0, 0, 0, 1},
					{3, 0, 0, 0, 0, 2},
					{2, 0, 0, 0, 0, 2},
					{1, 0, 0, 0, 0, 2},
					{0, 1, 2, 2, 2, 0}};*/

	/*int tab[6][6] = {{0, 2, 3, 2, 1, 0},
					{3, 0, 0, 0, 0, 1},
					{1, 0, 0, 0, 0, 4},
					{2, 0, 0, 0, 0, 2},
					{3, 0, 0, 0, 0, 2},
					{0, 3, 2, 1, 2, 0}};*/

	/*int tab[6][6] = {{0, 2, 3, 1, 2, 0},
					{2, 0, 0, 0, 0, 2},
					{1, 0, 0, 0, 0, 3},
					{4, 0, 0, 0, 0, 1},
					{2, 0, 0, 0, 0, 3},
					{0, 2, 1, 3, 2, 0}};*/

	/*int tab[6][6] = {{0, 1, 3, 2, 3, 0},
					{1, 0, 0, 0, 0, 3},
					{2, 0, 0, 0, 0, 2},
					{3, 0, 0, 0, 0, 1},
					{2, 0, 0, 0, 0, 2},
					{0, 2, 1, 3, 2, 0}};*/

	/*int tab[6][6] = {{0, 2, 2, 1, 4, 0},
					{2, 0, 0, 0, 0, 2},
					{1, 0, 0, 0, 0, 3},
					{2, 0, 0, 0, 0, 2},
					{3, 0, 0, 0, 0, 1},
					{0, 2, 2, 4, 1, 0}};*/

	int tab[6][6] = {{0, 1, 3, 2, 3, 0},
					{1, 0, 0, 0, 0, 3},
					{2, 0, 0, 0, 0, 2},
					{3, 0, 0, 0, 0, 1},
					{2, 0, 0, 0, 0, 2},
					{0, 2, 1, 3, 2, 0}};


	int x = 0, y = 0;

	see_param_x(tab, x, y);
	see_param_y(tab, x, y);	
	detect_alone_vert(tab, 1, 1);
	detect_alone_hori(tab, 1, 1);

	see_param_x(tab, x, y);
	see_param_y(tab, x, y);
	detect_alone_vert(tab, 1, 1);
	detect_alone_hori(tab, 1, 1);
	detect_twice_vert(tab, x, y);
	detect_twice_hori(tab, x, y);


	print_tab(tab, x, y);

return (0);
}

