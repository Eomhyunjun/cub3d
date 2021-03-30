#include "cub3d.h"

void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void		draw(t_data *img)
{
	int x;
	int y;
	int i;
	int j;

	x = 500;
	y = 700;
	i = 0;
	j = 0;
	while (y > 400)
	{
		x -= i;
		while ( x <= 500 + i)
		{
			my_mlx_pixel_put(img, x, y, 0x00FF0000);
			x++;
		}
		y--;
		i++;
		x = 500;
	}
}

int		main(void)
{
	void	*mlx;
	void	*mlx_win;
	t_data	img;

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "mlx_project");
	img.img = mlx_new_image(mlx, 1000, 1000);
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);
	draw(&img);
	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
	mlx_loop(mlx);
}
