# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heom <heom@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 19:25:57 by heom              #+#    #+#              #
#    Updated: 2021/05/23 17:34:12 by heom             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D

CC = gcc

CFLAGS = -Wall -Wextra -Werror

LXFLAGS = $(MLXOPT) -framework OpenGL -framework AppKit -lz $(DEBUGF)

DEBUGF = -g3
# DEBUGF = -g3 -fsanitize=address

RM = rm -f

MLXDIR = mlx/

MLXOPT = -L./mlx -lmlx

LIBDIR = utils/libft/

MAIN = \
	main \

SRCS = \
	src/get_next_line_arg \
	src/parsing_all \
	src/split_free \
	src/print_err \
	
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
	src/graphic/set \
	src/graphic/mlx_process \
	src/graphic/main_loop \
	src/graphic/init \
	src/graphic/buf \
	src/graphic/texture_init \
	src/graphic/draw \
	src/graphic/key \
	src/graphic/make_texnum \
	src/graphic/rotation \
	src/graphic/calc \
	src/graphic/sprite \

GNL =	get_next_line \
		get_next_line_utils \

FIL =	$(MAIN) \
		$(addsuffix .c, $(addprefix srcs/, $(SRC))) \
		$(addsuffix .c, $(addprefix srcs/parse_info/, $(INFO_PARSE))) \
		$(addsuffix .c, $(addprefix srcs/map_parsing/, $(MAP_PARSE))) \
		$(addsuffix .c, $(addprefix srcs/graphic/, $(GRAPHIC))) \
		$(addsuffix .c, $(addprefix utils/gnl/, $(GNL)))

OBJ = $(FIL:.c=.o)

all : $(NAME)

.c.o:
	@$(CC) $(CFLAGS) -o $@ -c $<

$(NAME) : $(OBJ)
	make -C $(LIBDIR) all
	make -C $(MLXDIR) all
	$(CC) -o $(NAME) $(LXFLAGS) $(MAIN) $(UTILS) $(SRCS) $(OBJ) $(LIBDIR)/libft.a mlx/libmlx.dylib

clean :
		$(RM) $(OBJ)
		$(RM) bitmap.bmp
		make -C $(LIBDIR) clean
		make -C $(MLXDIR) clean

fclean : clean
		$(RM) $(NAME)
		make -C $(LIBDIR) fclean
		make -C $(MLXDIR) fclean

re: fclean all

.PHONY: all, clean, fclean, re