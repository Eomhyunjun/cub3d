/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:24:29 by heom              #+#    #+#             */
/*   Updated: 2021/05/13 20:56:58 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

void	calc(t_all *all)
{
	int x;

	x = 0;
	printf("width : %d\n height : %d\n posX : %f, posY : %f \n dirX : %f, dirY : %f\nplaneX : %f, planeY : %f\n\n", all->width, all->height, all->posX, all->posY, all->dirX, all->dirY, all->planeX, all->planeY);

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

		int texNum;

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

		texNum = make_texNum(all, mapY, mapX, side);
			
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
		printf("Error\n Invalid value in map pile");
		return (0);
	}
	if (res == 0)
		printf("Error\n parsing_info duple err\n");
	mlx_process(&parse_info, map);
	split_free(map);
	return (0);
}