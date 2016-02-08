/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other_verif.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 20:05:14 by vcaquant          #+#    #+#             */
/*   Updated: 2016/01/22 20:08:11 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	verif_char(t_tetri *tab, int pos)
{
	int		pos_x;
	int		pos_y;

	pos_y = 0;
	while (pos_y < 4)
	{
		pos_x = 0;
		while (pos_x < 4)
		{
			if (tab[pos].piece[pos_y][pos_x] != '.' &&
					tab[pos].piece[pos_y][pos_x] != '#' &&
					tab[pos].piece[pos_y][pos_x] != '\n' &&
					tab[pos].piece[pos_y][pos_x] != '\0')
				ft_error();
			pos_x++;
		}
		pos_y++;
	}
}

void	defminx(t_tetri *tab, int pos, t_var *var)
{
	int		pos_x;
	int		pos_y;
	int		tmp;

	pos_y = 0;
	tmp = 0;
	while (pos_y < 4)
	{
		pos_x = 0;
		if (tmp > var->minx)
			var->minx = tmp;
		tmp = 0;
		while (pos_x < 3)
		{
			if (tab[pos].piece[pos_y][pos_x] == '#')
				tmp++;
			pos_x++;
		}
		pos_y++;
	}
	if (tmp > var->minx)
		var->minx = tmp;
}

void	defminy(t_tetri *tab, int pos, t_var *var)
{
	int		pos_x;
	int		pos_y;
	int		tmp;

	pos_x = 0;
	tmp = 0;
	while (pos_x < 3)
	{
		pos_y = 0;
		if (tmp > var->minx)
			var->minx = tmp;
		tmp = 0;
		while (pos_y < 4)
		{
			if (tab[pos].piece[pos_y][pos_x] == '#')
				tmp++;
			pos_y++;
		}
		pos_x++;
	}
	if (tmp > var->minx)
		var->minx = tmp;
	if (var->minx == 0)
		var->minx = 4;
}
