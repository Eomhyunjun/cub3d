#include "cub3d.h"
#include <stdio.h>
#include <stdlib.h>

#define X_EVENT_KEY_PRESS		2
#define X_EVENT_KEY_release		3
#define X_EVENT_KEY_EXIT		17 //exit key code

//Mac key code example
//All the key code example other than below is described on the site linked in READEME.md
#define KEY_ESC			53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2


void		my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

//int		draw(t_data *img, t_param *param)

int		draw(t_param *param)
{
	int x;
	int y;
	int i;
	int j;

	x = param->left;
	y = param->up + 300;
	i = 0;
	j = 0;
	
	printf("param.up: %d, param.left: %d, param->r: %d, param->g: %d, param->b: %d\n", param->up, param->left, param->r, param->g, param->b);
	if (param->up < 0)
		return (0);
	while (y > param->up)
	{
		x -= i;
		while ( x <= 500 + i)
		{
			my_mlx_pixel_put(param->img, x, y, create_trgb(100, param->r, param->g, param->b));
			x++;
		}
		y--;
		i++;
		x = 500;
	}

	mlx_put_image_to_window(param->mlx, param->mlx_win, param->img->img, 0, 0);
	return (0);
}

void	param_init(t_param *param, t_data *img, void *mlx, void *mlx_win)
{
	param->mlx = mlx;
	param->mlx_win = mlx_win;
	param->r = 100;
	param->g = 100;
	param->b = 100;
	param->up = 0;
	param->left = 500;
	param->img = img;
}

int		key_press(int keycode, t_param *param)
{
	static int a = 0;

	if (keycode == KEY_W)
		param->up += 10;
	else if (keycode == KEY_S)
		param->up -= 10;
	else if (keycode == KEY_A)
		param->left+=10;
	else if (keycode == KEY_D)
		param->left-=10;
	else if (keycode == KEY_Q)
		param->r+=10;
	else if (keycode == KEY_E)
		param->g+=10;
	else if (keycode == KEY_R)
		param->b+=10;
	else if (keycode == KEY_ESC)
		exit(0);
	
	return (0);
}

int		main(void)
{
	void		*mlx;
	void		*mlx_win;
	t_data		img;
	t_param		param;
	

	mlx = mlx_init();
	mlx_win = mlx_new_window(mlx, 1000, 1000, "mlx_project"); //window 상자
	img.img = mlx_new_image(mlx, 1000, 1000); // image 상자
	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length, &img.endian);

	

	//draw(&img, &param); // put으로 그리기
/*	
	for(int i = 0; i < 1000; ++i)
		printf("%d", img.addr[i]);
		*/
	param_init(&param, &img, mlx, mlx_win);
	//draw(&param);
	mlx_hook(mlx_win, X_EVENT_KEY_PRESS, 0, &key_press, &param);
	mlx_loop_hook(mlx, draw, &param);
	mlx_loop(mlx);

	return (0);
}
