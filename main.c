/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/09 20:09:11 by vcaquant          #+#    #+#             */
/*   Updated: 2016/01/20 19:18:23 by vsteffen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_error(void)
{
	ft_putstr("error\n");
	exit(0);
}

int		patternfound(char buff[BUFF_SIZE])
{
	unsigned int	i;
	unsigned int	nbpattern;

	nbpattern = 0;
	i = 0;
	while (buff[i])
	{
		if (buff[i] == '\n')
			nbpattern++;
		i++;
	}
	return (nbpattern);
}

void	buff_in_struct(t_tetri *tab, char buff[BUFF_SIZE], int pos)
{
	unsigned int	pos_x;
	unsigned int	pos_y;

	pos_x = 0;
	pos_y = 0;
	while (*buff)
	{
		if (*buff == '\n')
		{
			if (pos_x != 4)
				ft_error();
			tab[pos].piece[pos_y][pos_x] = '\0';
			pos_y++;
			pos_x = 0;
			buff++;
		}
		tab[pos].piece[pos_y][pos_x] = *buff;
		buff++;
		pos_x++;
	}
	tab[pos].piece[pos_y][pos_x] = '\0';
}

int		read_file(char **av, t_tetri *tab)
{
	char			buff[BUFF_SIZE + 1];
	int				ret;
	int				fd;
	int				pos;
	unsigned int	nb_eol;

	pos = 0;
	nb_eol = 0;
	fd = open(av[1], O_RDONLY);
	if (fd == -1)
		ft_error();
	while ((ret = read(fd, buff, BUFF_SIZE)))
	{
		buff[ret] = '\0';
		nb_eol += patternfound(buff);
		buff_in_struct(tab, buff, pos);
		tab[pos].name = 'A' + pos;
		pos++;
	}
	if (close(fd) == -1 || (nb_eol % 5) != 4)
		ft_error();
	return (pos);
}

int		main(int ac, char **av)
{
	int		nbtetri;
	t_tetri	*tab;
	t_var	*var;

	if (ac != 2)
		ft_error();
	tab = malloc(27 * sizeof(t_tetri));
	var = malloc(sizeof(t_var));
	if (!tab || !var)
		ft_error();
	nbtetri = read_file(av, tab);
	verif_sharp(tab, nbtetri, var);
	resolve(tab, var, nbtetri);
	free(tab);
	free(var);
	return (0);
}
