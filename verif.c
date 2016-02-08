/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsteffen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/15 21:50:08 by vsteffen          #+#    #+#             */
/*   Updated: 2016/01/22 21:01:57 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	pos_sharp(t_tetri *tab, int pos, t_var *var)
{
	int		pos_x;
	int		pos_y;
	int		nbsharp;

	init_in_pos_sharp(var, pos);
	pos_y = 0;
	nbsharp = 1;
	while (pos_y < 4)
	{
		pos_x = 0;
		while (pos_x < 4)
		{
			if (tab[pos].piece[pos_y][pos_x] == '#')
			{
				var->nbsharp = nbsharp;
				index_pos_sharp(tab, var, pos_y, pos_x);
				nbsharp++;
				var->y = pos_y;
				var->x = pos_x;
			}
			pos_x++;
		}
		pos_y++;
	}
}

int		nbsharpfound(t_tetri *tab, int pos)
{
	int		pos_x;
	int		pos_y;
	int		nbsharp;

	nbsharp = 0;
	pos_x = 0;
	pos_y = 0;
	while (pos_x < 4)
	{
		while (pos_y < 4)
		{
			if (tab[pos].piece[pos_y][pos_x] == '#')
				nbsharp++;
			pos_y++;
		}
		pos_x++;
		pos_y = 0;
	}
	return (nbsharp);
}

int		connexion_pos_y(t_tetri *tab, int pos, int connexion)
{
	int		pos_x;
	int		pos_y;

	connexion = 0;
	pos_x = 0;
	pos_y = 0;
	while (pos_x < 4)
	{
		while (pos_y < 3)
		{
			if (tab[pos].piece[pos_y][pos_x] == '#' &&
					tab[pos].piece[pos_y + 1][pos_x] == '#')
				connexion++;
			pos_y++;
		}
		pos_x++;
		pos_y = 0;
	}
	return (connexion);
}

int		connexion_pos_x(t_tetri *tab, int pos)
{
	int		pos_x;
	int		pos_y;
	int		connexion;

	connexion = 0;
	pos_y = 0;
	while (pos_y < 4)
	{
		pos_x = 0;
		while (pos_x < 3)
		{
			if ((tab[pos].piece[pos_y][pos_x] == '#') &&
					(tab[pos].piece[pos_y][pos_x + 1] == '#'))
				connexion++;
			pos_x++;
		}
		pos_y++;
	}
	return (connexion);
}

void	verif_sharp(t_tetri *tab, int nbtetri, t_var *var)
{
	int				pos;
	int				connexion;
	unsigned int	nbsharp;

	pos = 0;
	var->minx = 0;
	while (pos < nbtetri)
	{
		verif_char(tab, pos);
		defminx(tab, pos, var);
		defminy(tab, pos, var);
		connexion = connexion_pos_x(tab, pos);
		connexion += connexion_pos_y(tab, pos, connexion);
		nbsharp = nbsharpfound(tab, pos);
		if (connexion < 3 || nbsharp != 4)
			ft_error();
		pos_sharp(tab, pos, var);
		pos++;
	}
}
