CC = gcc
CFLAGS = -L mlx -lmlx -framework OpenGL -framework AppKit -g

all :
	$(CC) $(CFLAGS) main.c src/get_next_line.c src/get_next_line_utils.c libft/libft.a
