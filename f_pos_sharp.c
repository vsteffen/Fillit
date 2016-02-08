/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_pos_sharp.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 14:46:25 by vcaquant          #+#    #+#             */
/*   Updated: 2016/01/22 21:02:02 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	in_pos_sharp_two(t_tetri *tab, t_var *var, int pos_y, int pos_x)
{
	tab[var->pos].sharp_two_y = pos_y - var->y;
	tab[var->pos].sharp_two_x = pos_x - var->x;
}

void	in_pos_sharp_three(t_tetri *tab, t_var *var, int pos_y, int pos_x)
{
	tab[var->pos].sharp_three_y = pos_y - var->y;
	tab[var->pos].sharp_three_x = pos_x - var->x;
}

void	in_pos_sharp_four(t_tetri *tab, t_var *var, int pos_y, int pos_x)
{
	tab[var->pos].sharp_four_y = pos_y - var->y;
	tab[var->pos].sharp_four_x = pos_x - var->x;
}

void	init_in_pos_sharp(t_var *var, int pos)
{
	var->pos = pos;
	var->y = 0;
	var->x = 0;
}

void	index_pos_sharp(t_tetri *tab, t_var *var, int pos_y, int pos_x)
{
	if (var->nbsharp == 2)
		in_pos_sharp_two(tab, var, pos_y, pos_x);
	else if (var->nbsharp == 3)
		in_pos_sharp_three(tab, var, pos_y, pos_x);
	else if (var->nbsharp == 4)
		in_pos_sharp_four(tab, var, pos_y, pos_x);
}
