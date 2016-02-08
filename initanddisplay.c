/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initanddisplay.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/22 20:26:17 by vcaquant          #+#    #+#             */
/*   Updated: 2016/01/22 20:28:04 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	initab(char square[26][27])
{
	unsigned int	y;
	unsigned int	x;

	y = 0;
	x = 0;
	while (y < 26)
	{
		while (x < 27)
		{
			square[y][x] = '.';
			if (y == 25 || x == 0 || x == 26)
				square[y][x] = '#';
			x++;
		}
		square[y][x] = '\0';
		y++;
		x = 0;
	}
}

void	display_result(char square[26][27], t_var *var)
{
	int		y;
	int		x;

	y = 0;
	x = 0;
	while (y < var->small)
	{
		x = 1;
		while (x < (var->small + 1))
		{
			ft_putchar(square[y][x]);
			x++;
		}
		ft_putchar('\n');
		y++;
	}
}
