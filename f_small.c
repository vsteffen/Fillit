/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_small.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 20:30:24 by vcaquant          #+#    #+#             */
/*   Updated: 2016/01/22 20:32:56 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	cor_error(t_tetri *tab, char square[26][27], int pos, int nbsharp_put)
{
	int		y;
	int		x;

	y = tab[pos].bsharpy;
	x = tab[pos].bsharpx;
	if (nbsharp_put >= 1)
	{
		square[y][x] = '.';
		y = y + tab[pos].sharp_two_y;
		x = x + tab[pos].sharp_two_x;
	}
	if (nbsharp_put >= 2)
	{
		square[y][x] = '.';
		y = y + tab[pos].sharp_three_y;
		x = x + tab[pos].sharp_three_x;
	}
	if (nbsharp_put >= 3)
		square[y][x] = '.';
	{
		y = y + tab[pos].sharp_four_y;
		x = x + tab[pos].sharp_four_x;
	}
	if (nbsharp_put >= 4)
		square[y][x] = '.';
}

void	cor_small(char square[26][27], int small, t_var *var)
{
	int		y;
	int		x;

	x = 1;
	y = small - 1;
	while (x < small)
	{
		square[y][x] = '.';
		x++;
	}
	while (y >= 0)
	{
		square[y][x] = '.';
		y--;
	}
	var->y = 0;
	var->x = 1;
}

void	chgsmall(char square[26][27], int change, t_var *var)
{
	int		y;
	int		x;
	int		small;

	var->small = var->small + change;
	small = var->small;
	x = 1;
	y = small;
	while (x < (small + 1))
	{
		square[y][x] = '#';
		x++;
	}
	while (y >= 0)
	{
		square[y][x] = '#';
		y--;
	}
	if (change == 1)
		cor_small(square, small, var);
}

void	smallest(int nbtetri, t_var *var)
{
	int		small;

	small = var->minx;
	if (var->minx == 1)
		small = 2;
	while ((small * small) < (nbtetri * 4))
		small++;
	var->small = small;
	var->smally = small - 1;
	var->smallx = small - 3;
}
