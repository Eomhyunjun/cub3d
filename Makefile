CC = gcc
CFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

all :
	$(CC) $(CFLAGS) -g3 -fsanitize=address main.c color.c
	./a.out
