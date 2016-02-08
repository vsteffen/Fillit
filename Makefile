# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: vcaquant <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/11/27 03:44:14 by vcaquant          #+#    #+#              #
#    Updated: 2016/01/22 21:49:21 by vcaquant         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC_PATH = ./

SRC_NAME = srclibft/ft_atoi.c \
		   srclibft/ft_strrchr.c \
		   srclibft/ft_bzero.c \
		   srclibft/ft_isalnum.c \
		   srclibft/ft_isalpha.c \
		   srclibft/ft_isascii.c \
		   srclibft/ft_isdigit.c \
		   srclibft/ft_isprint.c \
		   srclibft/ft_memccpy.c \
		   srclibft/ft_memchr.c \
		   srclibft/ft_memcmp.c \
		   srclibft/ft_memset.c \
		   srclibft/ft_memmove.c \
		   srclibft/ft_memcpy.c \
		   srclibft/ft_putchar.c \
		   srclibft/ft_putchar_fd.c \
		   srclibft/ft_putstr.c \
		   srclibft/ft_putstr_fd.c \
		   srclibft/ft_strcat.c \
		   srclibft/ft_strchr.c \
		   srclibft/ft_strcmp.c \
		   srclibft/ft_strcpy.c \
		   srclibft/ft_strdup.c \
		   srclibft/ft_strlcat.c \
		   srclibft/ft_strlen.c \
		   srclibft/ft_strncat.c \
		   srclibft/ft_strncmp.c \
		   srclibft/ft_strncpy.c \
		   srclibft/ft_strnstr.c \
		   srclibft/ft_strstr.c \
		   srclibft/ft_tolower.c \
		   srclibft/ft_toupper.c \
		   srclibft/ft_putendl.c \
		   srclibft/ft_putendl_fd.c \
		   srclibft/ft_putnbr.c \
		   srclibft/ft_putnbr_fd.c \
		   srclibft/ft_itoa.c \
		   srclibft/ft_memalloc.c \
		   srclibft/ft_memdel.c \
		   srclibft/ft_strclr.c \
		   srclibft/ft_strdel.c \
		   srclibft/ft_strequ.c \
		   srclibft/ft_striter.c \
		   srclibft/ft_striteri.c \
		   srclibft/ft_strjoin.c \
		   srclibft/ft_strmap.c \
		   srclibft/ft_strmapi.c \
		   srclibft/ft_strnequ.c \
		   srclibft/ft_strnew.c \
		   srclibft/ft_strsplit.c \
		   srclibft/ft_strsub.c \
		   srclibft/ft_strtrim.c \
		   srclibft/ft_strnncpy.c \
		   main.c \
		   verif.c \
		   resolve.c \
		   f_parsing.c \
		   f_pos_sharp.c \
		   f_put_tetri.c \
		   f_small.c \
		   f_try_to.c \
		   initanddisplay.c \
		   other_verif.c \

OBJ_PATH = ./

INC_PATH = ./

LIB_PATH = ./

NAME = fillit

CC = gcc

CFLAGS = -Werror -Wall -Wextra

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
LIB = $(addprefix -L,$(LIB_PATH))
INC = $(addprefix -I,$(INC_PATH))

all: $(NAME)

$(NAME): $(OBJ)
	    $(CC) $(CFLAGS) $(SRC) -I $(INC) -o $(NAME)

clean:
	/bin/rm -rf $(NAME)

fclean: clean

re: clean fclean all

.PHONY : all clean fclean re
