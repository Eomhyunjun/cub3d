# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: heom <heom@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/29 19:25:57 by heom              #+#    #+#              #
#    Updated: 2021/05/04 13:43:11 by heom             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -L mlx -lmlx -framework OpenGL -framework AppKit $(DEBUGF)
DEBUGF = -g3 -fsanitize=address

SRC = main.c \
	libft/libft.a \
	src/arg.c \
	src/get_next_line/get_next_line.c \
	src/get_next_line/get_next_line_utils.c \
	src/parseInfo/parsingInfo.c \
	src/parseInfo/parse_r.c \
	src/parseInfo/parse_news.c \
	src/parseInfo/parse_rgb.c \
	src/parseInfo/dupCheck.c \
	src/mapParsing/makeMatrix.c \
	src/mapParsing/putSpace.c \
	src/mapParsing/checkMap.c \
	src/mapParsing/copyMap.c \
	src/mapParsing/parsingMap.c \


all :
	$(CC) $(CFLAGS) $(SRC)

re : all

