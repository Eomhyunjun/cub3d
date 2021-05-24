# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heom <heom@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 19:25:57 by heom              #+#    #+#              #
#    Updated: 2021/05/24 20:12:04 by heom             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror -g

LXFLAGS = $(MLXOPT) -framework OpenGL -framework AppKit -lz $(DEBUGF) -O3

RM = rm -f

MLXDIR = mlx/

MLXOPT = -L./mlx -lmlx

LIBMLX = libmlx.a

LIBDIR = utils/libft/

MAIN = \
	main.c \

SRCS = \
	get_next_line_arg \
	parsing_all \
	split_free \
	print_err \
	
INFO_PARSE = \
	info_check \
	parsing_info \
	parse_r \
	parse_news \
	parse_rgb \
	dup_check \
	make_rgb \
	color \
	color_len_chk \

MAP_PARSE = \
	make_matrix \
	put_space \
	check_map \
	copy_map \
	parsing_map \

GRAPHIC = \
	set \
	mlx_process \
	main_loop \
	init \
	buf \
	texture_init \
	key \
	make_texnum \
	rotation \
	calc \
	sprite \

SAVE = \
	save_bitmap \
	make_bitmap_file \

GNL =	get_next_line \
		get_next_line_utils \

FIL =	$(addsuffix .c, $(addprefix srcs/, $(SRCS))) \
		$(addsuffix .c, $(addprefix srcs/parse_info/, $(INFO_PARSE))) \
		$(addsuffix .c, $(addprefix srcs/map_parsing/, $(MAP_PARSE))) \
		$(addsuffix .c, $(addprefix srcs/graphic/, $(GRAPHIC))) \
		$(addsuffix .c, $(addprefix srcs/save/, $(SAVE))) \
		$(addsuffix .c, $(addprefix utils/gnl/, $(GNL))) \
		$(MAIN)

OBJ = $(FIL:.c=.o)

all : $(NAME)

.c.o:
	$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJ)
	make -C $(LIBDIR) all
	make -C ./get_screen all
	cp $(MLXDIR)/$(LIBMLX) ./
	$(CC) -o $@ $(LXFLAGS) $(LIBDIR)/libft.a $(LIBMLX) $^ 

clean :
		$(RM) $(OBJ)
		$(RM) bitmap.bmp
		make -C $(LIBDIR) clean
		make -C ./get_screen clean

fclean : clean
		$(RM) $(NAME)
		make -C $(LIBDIR) fclean
		make -C ./get_screen clean
		rm -f $(LIBMLX)

re: fclean all

.PHONY: all, clean, fclean, re