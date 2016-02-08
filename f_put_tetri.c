/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_put_tetri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 18:19:01 by vcaquant          #+#    #+#             */
/*   Updated: 2016/01/22 21:04:08 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	put_tetri_one(t_tetri *tab, t_var *var)
{
	var->y = var->y + tab[var->pos].sharp_two_y;
	var->x = var->x + tab[var->pos].sharp_two_x;
}

void	put_tetri_two(t_tetri *tab, t_var *var)
{
	var->y = var->y + tab[var->pos].sharp_three_y;
	var->x = var->x + tab[var->pos].sharp_three_x;
}

void	put_tetri_three(t_tetri *tab, t_var *var)
{
	var->y = var->y + tab[var->pos].sharp_four_y;
	var->x = var->x + tab[var->pos].sharp_four_x;
}

void	init_put_tetri(t_tetri *tab, t_var *var, int pos)
{
	tab[pos].bsharpy = var->y;
	tab[pos].bsharpx = var->x;
}
