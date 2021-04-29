# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heom <heom@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 19:25:57 by heom              #+#    #+#              #
#    Updated: 2021/04/29 22:00:12 by heom             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -L mlx -lmlx -framework OpenGL -framework AppKit $(DEBUGF)
DEBUGF = -g3 -fsanitize=address

SRC = main.c \
	libft/libft.a \
	src/get_next_line/get_next_line.c \
	src/get_next_line/get_next_line_utils.c \
	src/parsingInfo.c \
	src/parse_r.c \
	src/parse_news.c \
	src/parse_rgb.c \
	src/dupCheck.c \

all :
	$(CC) $(CFLAGS) $(SRC)

re : all

