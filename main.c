/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:24:29 by heom              #+#    #+#             */
/*   Updated: 2021/05/09 21:11:08 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"


void all_init(t_all *all, t_info *parse_info)
{
	all->posX = 22.0;
	all->posY = 11.5;
	all->dirX = -1.0;
	all->dirY = 0.0;
	all->planeX = 0.0;
	all->planeY = 0.66;
	all->moveSpeed = 0.05;
	all->rotSpeed = 0.05;

	all.mlx = mlx_init();

	all->width = ft_atoi(parse_info->rw);
	all->height = ft_atoi(parse_info->rh);
	all.win = mlx_new_window(all.mlx, all->width, all->height, "my_cub3");
	all.img.img = mlx_new_window(all.mlx, all->width, all->height);
	all.img.data = (int *)mlx_get_data_addr(all.img.img, &all.img.bits_per_pixel, &all.img.line_length, &all.img.endian);
}

void	calc(t_all *all)
{
	int x;

}

void	draw(t_all *all)
{
	for (int y = 0; y < all->height; y++)
	{
		for (int x = 0; x < all->width; x++)
		{
			all->img.data[y * all->width + x] = all->buf[y][x];
		}
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
}

int	main_loop(t_info *info)
{
	calc(info);
	draw(info);
	return (0);
}

int		mlx_process(t_info *parse_info, char **map)
{
	t_all	all;
	all_init(&all, parse_info);

	all.buf = (int **)malloc(sizeof(int *) * all->height);
	//buf 할당
	for (int i = 0; i < all->height; i++)
	{
		all.buf[i] = (int *)malloc(sizeof(int) * all->width);
	}

	//buf 초기화
	for (int i = 0; i < all->height; i++)
	{
		for (int j = 0; j < all->width; j++)
		{
			all.buf[i][j] = 0;
		}
	}
	
	//texture 초기화
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < texHeight * texWidth; j++)
		{
			info.texture[i][j] = 0;
		}
	}

	for (int x = 0; x < texWidth; x++)
	{
		for (int y = 0; y < texHeight; y++)
		{
			int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
			int ycolor = y * 256 / texHeight;
			int xycolor = y * 128 / texHeight + x * 128 / texWidth;
			info.texture[0][texWidth * y + x] = 65536 * 254 * (x != y && x != texWidth - y); //flat red texture with black cross
			info.texture[1][texWidth * y + x] = xycolor + 256 * xycolor + 65536 * xycolor; //sloped greyscale
			info.texture[2][texWidth * y + x] = 256 * xycolor + 65536 * xycolor; //sloped yellow gradient
			info.texture[3][texWidth * y + x] = xorcolor + 256 * xorcolor + 65536 * xorcolor; //xor greyscale
			info.texture[4][texWidth * y + x] = 256 * xorcolor; //xor green
			info.texture[5][texWidth * y + x] = 65536 * 192 * (x % 16 && y % 16); //red bricks
			info.texture[6][texWidth * y + x] = 65536 * ycolor; //red gradient
			info.texture[7][texWidth * y + x] = 128 + 256 * 128 + 65536 * 128; //flat grey texture
		}
	}

	mlx_loop_hook(all.mlx, &main_loop, &all);
	mlx_hoop(all.win, X_EVENT_KEY_PRESS, 0, &key_press, &all);

	mlx_loop_hook(all.mlx);
}

int			main(void)
{
	int		res;
	char	**map;
	t_info	parse_info;
	t_list	*map_list;

	res = 0;
	ft_bzero(&parse_info, sizeof(t_info));
	parse_info.dup[8] = '\0';
	map_list = NULL;
	if (!(res = parsing_all(&parse_info, map_list, &map)))
	{ // map에 값 잘못 넣으면 NULL 값 리턴되게 했는데 세그먼트 뜸;;
		printf("ERRRRRRRRRRRRR\n");
		return (0);
	}
	printf("====================================================\n");
	int i = 0;
	while (map[i])
	{
		printf("|%s|\n", map[i]);
		i++;
	}
	printf("====================================================\n");
	if (res == 0) //print remove
		printf("hello duple err");
	mlx_process(parse_info, map);
	return (0);
}