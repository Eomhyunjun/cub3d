# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heom <heom@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 19:25:57 by heom              #+#    #+#              #
#    Updated: 2021/05/09 19:53:33 by heom             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit $(DEBUGF)
DEBUGF = -g3 -fsanitize=address

SRC = main.c \
	libft/libft.a \
	src/get_next_line_arg.c \
	src/parsing_all.c \
	src/get_next_line/get_next_line.c \
	src/get_next_line/get_next_line_utils.c \
	src/parse_info/parsing_info.c \
	src/parse_info/parse_r.c \
	src/parse_info/parse_news.c \
	src/parse_info/parse_rgb.c \
	src/parse_info/dup_check.c \
	src/map_parsing/make_matrix.c \
	src/map_parsing/put_space.c \
	src/map_parsing/check_map.c \
	src/map_parsing/copy_map.c \
	src/map_parsing/parsing_map.c \


all :
	$(CC) $(CFLAGS) $(SRC)

re : all

