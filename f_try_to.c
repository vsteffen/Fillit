/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/14 18:25:54 by vsteffen          #+#    #+#             */
/*   Updated: 2016/01/22 21:05:34 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		lechien(char square[26][27], t_var *var)
{
	initab(square);
	chgsmall(square, 1, var);
	return (0);
}

int		grossechienne(t_tetri *tab, t_var *var, int y, int x)
{
	tab[var->pos].bsharpy = y;
	tab[var->pos].bsharpx = x;
	var->pos++;
	return (0);
}

void	chgyx(t_var *var, int y, int x)
{
	var->y = y;
	var->x = x;
}

int		trytoputprev(char square[26][27], t_tetri *tab, t_var *var)
{
	int				y;
	int				x;
	int				value;

	value = 1;
	next1(tab, var);
	y = tab[var->pos].bsharpy - 1;
	while (y++ < var->small)
	{
		x = 0;
		if (y == tab[var->pos].bsharpy)
			x = tab[var->pos].bsharpx - 1;
		while (x++ <= var->small && value == 1)
		{
			if (square[y][x] == '.')
			{
				chgyx(var, y, x);
				if (y == var->smally && x == var->small && var->pos == 0)
					value = lechien(square, var);
				if (put_tetri(tab, square, var->pos, var))
					value = grossechienne(tab, var, y, x);
			}
		}
	}
	return (value);
}

int		trytoput(char square[26][27], t_tetri *tab, t_var *var)
{
	int				y;
	int				x;

	y = 0;
	while (y < var->small)
	{
		x = 1;
		while (x <= var->small)
		{
			if (square[y][x] == '.')
			{
				var->y = y;
				var->x = x;
				if (put_tetri(tab, square, var->pos, var))
					return (1);
			}
			x++;
		}
		y++;
	}
	return (0);
}
