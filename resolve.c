/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolve.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/17 14:51:06 by vcaquant          #+#    #+#             */
/*   Updated: 2016/01/22 21:05:39 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		put_tetri(t_tetri *tab, char square[26][27], int pos, t_var *var)
{
	int		nbsharp_put;

	nbsharp_put = 0;
	init_put_tetri(tab, var, pos);
	while (nbsharp_put != 4)
	{
		if (nbsharp_put == 1)
			put_tetri_one(tab, var);
		else if (nbsharp_put == 2)
			put_tetri_two(tab, var);
		else if (nbsharp_put == 3)
			put_tetri_three(tab, var);
		if (square[var->y][var->x] == '.' || nbsharp_put == 0)
			square[var->y][var->x] = tab[pos].name;
		else
		{
			cor_error(tab, square, var->pos, nbsharp_put);
			return (0);
		}
		nbsharp_put++;
	}
	return (1);
}

void	parsingv3(char square[26][27], t_tetri *tab, int nbtetri, t_var *var)
{
	inityx(var);
	var->pos = 0;
	while (var->pos != nbtetri)
	{
		if (trytoput(square, tab, var))
			var->pos++;
		else if (var->pos > 0)
		{
			var->pos--;
			cor_error(tab, square, var->pos, 4);
			while (trytoputprev(square, tab, var) && var->pos > 0)
			{
				var->pos--;
				cor_error(tab, square, var->pos, 4);
			}
		}
	}
	display_result(square, var);
}

void	resolve(t_tetri *tab, t_var *var, int nbtetri)
{
	char			square[26][27];

	initab(square);
	smallest(nbtetri, var);
	chgsmall(square, 0, var);
	parsingv3(square, tab, nbtetri, var);
}
