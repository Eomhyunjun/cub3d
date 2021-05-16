# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heom <heom@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 19:25:57 by heom              #+#    #+#              #
#    Updated: 2021/05/16 14:44:27 by heom             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit $(DEBUGF)
DEBUGF = -g3 -fsanitize=address

MAIN = \
	main.c \
	color.c \

UTILS = \
	utils/libft/libft.a \
	utils/get_next_line/get_next_line.c \
	utils/get_next_line/get_next_line_utils.c \

SRCS = \
	src/get_next_line_arg.c \
	src/parsing_all.c \
	src/split_free.c \
	\
	src/parse_info/parsing_info.c \
	src/parse_info/parse_r.c \
	src/parse_info/parse_news.c \
	src/parse_info/parse_rgb.c \
	src/parse_info/dup_check.c \
	\
	src/map_parsing/make_matrix.c \
	src/map_parsing/put_space.c \
	src/map_parsing/check_map.c \
	src/map_parsing/copy_map.c \
	src/map_parsing/parsing_map.c \
	\
	src/graphic/mlx_process.c \
	src/graphic/main_loop.c \
	src/graphic/all_init.c \
	src/graphic/malloc_buf.c \
	src/graphic/texture_init.c \
	src/graphic/draw.c \
	src/graphic/key_press.c \
	src/graphic/key_update.c \
	src/graphic/make_texnum.c \
	src/graphic/rotation.c \

all :
	$(CC) $(CFLAGS) $(MAIN) $(UTILS) $(SRCS)

re : all

