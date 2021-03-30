CC = gcc
CFLAGS = -Lmlx -lmlx -framework OpenGL -framework AppKit

all :
	$(CC) $(CFLAGS) main.c color.c
	./a.out
