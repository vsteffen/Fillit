/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_parsing.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 20:20:33 by vcaquant          #+#    #+#             */
/*   Updated: 2016/01/22 20:22:26 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	next1(t_tetri *tab, t_var *var)
{
	if (tab[var->pos].bsharpx < var->small)
		tab[var->pos].bsharpx++;
	else
	{
		tab[var->pos].bsharpx = 1;
		tab[var->pos].bsharpy++;
	}
}

void	previous(t_var *var, t_tetri *tab)
{
	var->y = tab[var->pos].bsharpy;
	var->x = tab[var->pos].bsharpx;
}

void	next(t_var *var)
{
	if (var->x < var->small)
		var->x++;
	else
	{
		var->x = 1;
		var->y++;
	}
}

void	inityx(t_var *var)
{
	var->y = 0;
	var->x = 1;
}
