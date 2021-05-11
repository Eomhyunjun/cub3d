/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:24:29 by heom              #+#    #+#             */
/*   Updated: 2021/05/11 17:33:31 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"


void all_init(t_all *all, t_info *parse_info)
{
	all->posX = 5;
	all->posY = 5;
	all->dirX = -1.0;
	all->dirY = 0.0;
	all->planeX = 0.0;
	all->planeY = 0.66;
	all->moveSpeed = 0.05;
	all->rotSpeed = 0.05;

	all->mlx = mlx_init();

	all->width = ft_atoi(parse_info->rw);
	all->height = ft_atoi(parse_info->rh);
	all->win = mlx_new_window(all->mlx, all->width, all->height, "my_cub3");
	all->img.img = mlx_new_image(all->mlx, all->width, all->height);
	all->img.data = (int *)mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length, &all->img.endian);
}

void	calc(t_all *all)
{
	int x;

	x = 0;
	//printf("width : %d\n height : %d\n posX : %f, posY : %f \n dirX : %f, dirY : %f\nplaneX : %f, planeY : %f\n\n", all->width, all->height, all->posX, all->posY, all->dirX, all->dirY, all->planeX, all->planeY);

	while (x < all->width)
	{
		double cameraX = 2 * x / (double)all->width - 1;
		double rayDirX = all->dirX + all->planeX * cameraX;
		double rayDirY = all->dirY + all->planeY * cameraX;

		int mapX = (int)all->posX;
		int mapY = (int)all->posY;

		double sideDistX;
		double sideDistY;

		double deltaDistX = fabs(1 / rayDirX);
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;

		int stepX;
		int stepY;

		int hit = 0;
		int side;

		if (rayDirX < 0)
		{
			stepX = -1;
			sideDistX = (all->posX - mapX) * deltaDistX;
		}
		else
		{
			stepX = 1;
			sideDistX = (mapX + 1.0 - all->posX) * deltaDistX;
		}
		if (rayDirY < 0)
		{
			stepY = -1;
			sideDistY = (all->posY - mapY) * deltaDistY;
		}
		else
		{
			stepY = 1;
			sideDistY = (mapY + 1.0 - all->posY) * deltaDistY;
		}

		while (hit == 0)
		{
			int ind = 0;
			if (sideDistX < sideDistY)
			{
				sideDistX += deltaDistX;
				mapX += stepX;
				side = 0;
			}
			else
			{
				sideDistY += deltaDistY;
				mapY += stepY;
				side = 1;
			}
			if ('x' > all->map[mapY][mapX])
				hit = 1;
		}
		if (side == 0)
			perpWallDist = (mapX - all->posX + (1 - stepX) / 2) / rayDirX;
		else
			perpWallDist = (mapY - all->posY + (1 - stepY) / 2) / rayDirY;

		int lineHeight = (int)(all->height / perpWallDist);

		int drawStart = -lineHeight / 2 + all->height / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + all->height / 2;
		if(drawEnd >= all->height)
			drawEnd = all->height - 1;

		int texNum = all->map[mapY][mapX];
		if (texNum == 'x')
			texNum = 0;
		else
			texNum -= '0';
		double wallX;
		if (side == 0)
			wallX = all->posY + perpWallDist * rayDirY;
		else
			wallX = all->posX + perpWallDist * rayDirX;
		wallX -= floor(wallX);

		int texX = (int)(wallX * (double)texWidth);
		if (side == 0 && rayDirX > 0)
			texX = texWidth - texX - 1;
		if (side == 1 && rayDirY < 0)
			texX = texWidth - texX - 1;

		double step = 1.0 * texHeight / lineHeight;
		double texPos = (drawStart - all->height / 2 + lineHeight / 2) * step;
		for (int y = drawStart; y < drawEnd; y++)
		{
			int texY = (int)texPos & (texHeight - 1);
			texPos += step;
			int color = all->texture[texNum][texHeight * texY + texX];
			if (side == 1)
				color = (color >> 1) & 8355711;
			all->buf[y][x] = color;
		}
		x++;
	}
}

int	key_press(int key, t_all *all)
{
	if (key == K_W)
	{
		if (all->map[(int)(all->posY)][(int)(all->posX + all->dirX * all->moveSpeed)] == 'x')
			all->posX += all->dirX * all->moveSpeed;
		else if (all->map[(int)(all->posY + all->dirY * all->moveSpeed)][(int)(all->posX)] == 'x')
			all->posY += all->dirY * all->moveSpeed;
	}
	if (key == K_S)
	{
		if (all->map[(int)(all->posY)][(int)(all->posX - all->dirX * all->moveSpeed)] == 'x')
			all->posX -= all->dirX * all->moveSpeed;
		else if (all->map[(int)(all->posY - all->dirY * all->moveSpeed)][(int)(all->posX)] == 'x')
			all->posY -= all->dirY * all->moveSpeed;
	}
	if (key == K_D)
	{
		double oldDirX = all->dirX;
		all->dirX = all->dirX * cos(-all->rotSpeed) - all->dirY * sin(-all->rotSpeed);
		all->dirY = oldDirX * sin(-all->rotSpeed) + all->dirY * cos(-all->rotSpeed);
		double oldPlaneX = all->planeX;
		all->planeX = all->planeX * cos(-all->rotSpeed) - all->planeY * sin(-all->rotSpeed);
		all->planeY = oldPlaneX * sin(-all->rotSpeed) + all->planeY * cos(-all->rotSpeed);
	}
	if (key == K_A)
	{
		double oldDirX = all->dirX;
		all->dirX = all->dirX * cos(all->rotSpeed) - all->dirY * sin(all->rotSpeed);
		all->dirY = oldDirX * sin(all->rotSpeed) + all->dirY * cos(all->rotSpeed);
		double oldPlaneX = all->planeX;
		all->planeX = all->planeX * cos(all->rotSpeed) - all->planeY * sin(all->rotSpeed);
		all->planeY = oldPlaneX * sin(all->rotSpeed) + all->planeY * cos(all->rotSpeed);
	}
	if (key == K_ESC)
		exit(0);
	return (0);
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

int	main_loop(t_all *all)
{
	calc(all);
	draw(all);
	return (0);
}

int		mlx_process(t_info *parse_info, char **map)
{
	t_all	all;
	all_init(&all, parse_info);
	all.map = map;

	printf("====================================================\n");
	int i = 0;
	int j = 0;
	while (map[i])
	{
		while(map[i][j])
		{
			printf("|%c|", map[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	printf("====================================================\n");

	all.buf = (int **)malloc(sizeof(int *) * all.height);
	//buf 할당
	for (int i = 0; i < all.height; i++)
	{
		all.buf[i] = (int *)malloc(sizeof(int) * all.width);
	}

	//buf 초기화
	for (int i = 0; i < all.height; i++)
	{
		for (int j = 0; j < all.width; j++)
		{
			all.buf[i][j] = 0;
		}
	}
	
	//texture 초기화
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < texHeight * texWidth; j++)
		{
			all.texture[i][j] = 0;
		}
	}

	for (int x = 0; x < texWidth; x++)
	{
		for (int y = 0; y < texHeight; y++)
		{
			int xorcolor = (x * 256 / texWidth) ^ (y * 256 / texHeight);
			int ycolor = y * 256 / texHeight;
			int xycolor = y * 128 / texHeight + x * 128 / texWidth;
			all.texture[0][texWidth * y + x] = create_trgb(50, 0, 0, 0);
			all.texture[1][texWidth * y + x] = create_trgb(50, 50, 0, 0);
			all.texture[2][texWidth * y + x] = create_trgb(50, 0, 50, 0);
			all.texture[3][texWidth * y + x] = create_trgb(50, 0, 0, 50);
			all.texture[4][texWidth * y + x] = create_trgb(50, 100, 100, 0);
			all.texture[5][texWidth * y + x] = create_trgb(50, 0, 100, 100);
			all.texture[6][texWidth * y + x] = create_trgb(50, 100, 0, 100);
			all.texture[7][texWidth * y + x] = create_trgb(50, 50, 50, 50);
		}
	}

	mlx_loop_hook(all.mlx, &main_loop, &all);
	mlx_hook(all.win, X_EVENT_KEY_PRESS, 0, &key_press, &all);

	mlx_loop(all.mlx);
	return (0);
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
	mlx_process(&parse_info, map);
	free(map);
	return (0);
}