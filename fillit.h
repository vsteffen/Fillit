/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/14 16:30:03 by vcaquant          #+#    #+#             */
/*   Updated: 2016/01/22 22:10:56 by vcaquant         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include "srclibft/libft.h"
# define BUFF_SIZE 21

typedef struct	s_tetri
{
	char		piece[4][4];
	char		name;
	int			bsharpy;
	int			bsharpx;
	int			sharp_one_y;
	int			sharp_one_x;
	int			sharp_two_y;
	int			sharp_two_x;
	int			sharp_three_y;
	int			sharp_three_x;
	int			sharp_four_y;
	int			sharp_four_x;
	int			put;
	int			count;
}				t_tetri;

typedef struct	s_var
{
	int			x;
	int			y;
	int			a;
	int			b;
	int			ftetrix;
	int			ftetriy;
	int			count;
	int			pos;
	int			small;
	int			smally;
	int			smallx;
	int			minx;
	int			nbsharp;
}				t_var;

void			verif_char(t_tetri *tab, int pos);
void			defminx(t_tetri *tab, int pos, t_var *var);
void			defminy(t_tetri *tab, int pos, t_var *var);

void			cor_error(t_tetri *tab, char square[26][27], int pos,
					int nbsharp_put);
void			cor_small(char square[26][27], int small, t_var *var);
void			chgsmall(char square[26][27], int change, t_var *var);
void			smallest(int nbtetri, t_var *var);

void			display_result(char square[26][27], t_var *var);
void			initab(char square[26][27]);

void			next1(t_tetri *tab, t_var *var);
void			previous(t_var *var, t_tetri *tab);
void			next(t_var *var);
void			inityx(t_var *var);

int				lechien(char square[26][27], t_var *var);
int				grossechienne(t_tetri *tab, t_var *var, int y, int x);
void			chgyx(t_var *var, int y, int x);
int				trytoputprev(char square[26][27], t_tetri *tab, t_var *var);
int				trytoput(char square[26][27], t_tetri *tab, t_var *var);

void			index_pos_sharp(t_tetri *tab, t_var *var, int pos_y,
					int pos_x);
void			in_pos_sharp_two(t_tetri *tab, t_var *var, int pos_y,
					int pos_x);
void			in_pos_sharp_three(t_tetri *tab, t_var *var, int pos_y,
					int pos_x);
void			in_pos_sharp_four(t_tetri *tab, t_var *var, int pos_y,
					int pos_x);
void			init_in_pos_sharp(t_var *var, int pos);

void			put_tetri_one(t_tetri *tab, t_var *var);
void			put_tetri_two(t_tetri *tab, t_var *var);
void			put_tetri_three(t_tetri *tab, t_var *var);
void			init_put_tetri(t_tetri *tab, t_var *var, int pos);

int				put_tetri(t_tetri *tab, char square[26][27], int pos,
					t_var *var);
void			parsingv3(char square[26][27], t_tetri *tab, int nbtetri,
					t_var *var);
void			resolve(t_tetri *tab, t_var *var, int nbtetri);

void			pos_sharp(t_tetri *tab, int pos, t_var *var);
int				nbsharpfound(t_tetri *tab, int pos);
int				connexion_pos_y(t_tetri *tab, int pos, int connexion);
int				connexion_pos_x(t_tetri *tab, int pos);
void			verif_sharp(t_tetri *tab, int nbtetri, t_var *var);

void			ft_error(void);
int				patternfound(char buff[BUFF_SIZE]);
void			buff_in_struct(t_tetri *tab, char buff[BUFF_SIZE], int pos);
int				read_file(char **av, t_tetri *tab);

#endif
