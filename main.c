/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:24:29 by heom              #+#    #+#             */
/*   Updated: 2021/05/14 21:04:14 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

void	calc_init(t_all *all, t_calc *cal, int x)
{
	cal->cameraX = 2 * x / (double)all->width - 1;
	cal->rayDirX = all->dirX + all->planeX * cal->cameraX;
	cal->rayDirY = all->dirY + all->planeY * cal->cameraX;
	cal->mapX = (int)all->posX;
	cal->mapY = (int)all->posY;
	cal->deltaDistX = (cal->rayDirY == 0) ? 0 : ((cal->rayDirX == 0) ? 1 : fabs(1 / cal->rayDirX));
	cal->deltaDistY = (cal->rayDirX == 0) ? 0 : ((cal->rayDirY == 0) ? 1 : fabs(1 / cal->rayDirY));
	cal->hit = 0;
}

void	set_step_side(t_all *all, t_calc *cal)
{
		if (cal->rayDirX < 0)
		{
			cal->stepX = -1;
			cal->sideDistX = (all->posX - cal->mapX) * cal->deltaDistX;
		}
		else
		{
			cal->stepX = 1;
			cal->sideDistX = (cal->mapX + 1.0 - all->posX) * cal->deltaDistX;
		}
		if (cal->rayDirY < 0)
		{
			cal->stepY = -1;
			cal->sideDistY = (all->posY - cal->mapY) * cal->deltaDistY;
		}
		else
		{
			cal->stepY = 1;
			cal->sideDistY = (cal->mapY + 1.0 - all->posY) * cal->deltaDistY;
		}
}

void	set_hit(t_all *all, t_calc *cal)
{
	while (cal->hit == 0)
	{
		if (cal->sideDistX < cal->sideDistY)
		{
			cal->sideDistX += cal->deltaDistX;
			cal->mapX += cal->stepX;
			cal->side = 0;
		}
		else
		{
			cal->sideDistY += cal->deltaDistY;
			cal->mapY += cal->stepY;
			cal->side = 1;
		}
		if ('x' > all->map[cal->mapY][cal->mapX])
			cal->hit = 1;
	}
}

void	calc(t_all *all)
{
	int x;
	t_calc cal;

	x = 0;
	//printf("width : %d height : %d\nposX : %f, posY : %f \n dirX : %f, dirY : %f\nplaneX : %f, planeY : %f\n\n", all->width, all->height, all->posX, all->posY, all->dirX, all->dirY, all->planeX, all->planeY);
	while (x < all->width)
	{
		calc_init(all, &cal, x);
		set_step_side(all, &cal);
		set_hit(all, &cal);
		
		if (cal.side == 0)
			cal.perpWallDist = (cal.mapX - all->posX + (1 - cal.stepX) / 2) / cal.rayDirX;
		else
			cal.perpWallDist = (cal.mapY - all->posY + (1 - cal.stepY) / 2) / cal.rayDirY;

		int lineHeight = (int)(all->height / cal.perpWallDist);
		if (cal.perpWallDist <= 0.01 && cal.perpWallDist >= -0.01)
			lineHeight = 0;

		int drawStart = -lineHeight / 2 + all->height / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawEnd = lineHeight / 2 + all->height / 2;
		if(drawEnd >= all->height)
			drawEnd = all->height - 1;
			
		cal.texNum = make_texNum(all, cal.stepX, cal.stepY, cal.side);

		double wallX;
		if (cal.side == 0)
			wallX = all->posY + cal.perpWallDist * cal.rayDirY;
		else
			wallX = all->posX + cal.perpWallDist * cal.rayDirX;
		wallX -= floor(wallX);

		int texX = (int)(wallX * (double)texWidth);
		if (cal.side == 0 && cal.rayDirX > 0)
			texX = texWidth - texX - 1;
		if (cal.side == 1 && cal.rayDirY < 0)
			texX = texWidth - texX - 1;

		double step = 1.0 * texHeight / lineHeight;
		double texPos = (drawStart - all->height / 2 + lineHeight / 2) * step;
	
		for (int y = 0; y < all->height / 2; y++)
		{
				all->buf[y][x] = all->texture[5][0];
		}

		for (int y = all->height / 2; y < all->height; y++)
		{
				all->buf[y][x] = all->texture[6][0];
		}

		for (int y = drawStart; y < drawEnd; y++)
		{
			int texY = (int)texPos & (texHeight - 1);
			texPos += step;
			int color = all->texture[cal.texNum][texHeight * texY + texX];
			if (cal.side == 1)
				color = (color >> 1) & 8355711;
			all->buf[y][x] = color;
		}
		x++;
	}

	//printf("width : %d height : %d\nposX : %f, posY : %f \n dirX : %f, dirY : %f\nplaneX : %f, planeY : %f\n\n", all->width, all->height, all->posX, all->posY, all->dirX, all->dirY, all->planeX, all->planeY);

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
	parse_info.pos[0] = -1;
	map_list = NULL;
	if (!(res = parsing_all(&parse_info, map_list, &map)))
	{
		printf("Error\n Invalid value in map pile");
		return (0);
	}
	res = mlx_process(&parse_info, map);
	if (res == 0)
		printf("Error\n parsing_info duple err\n");
	split_free(map);
	return (0);
}