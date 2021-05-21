/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:21:42 by heom              #+#    #+#             */
/*   Updated: 2021/05/21 19:48:33 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void sort_spr(t_all *all, t_sprite *spr, int spr_num)
{
	int i;
	int j;
	t_sprite temp;

	i = 0;
	j = 0;
	while (j < all->spr_num - 1)
	{
		while (i < all->spr_num - j - 1)
		{
			if(spr[i].real_depth < spr[i + 1].real_depth)
			{
				temp = spr[i];
				spr[i] = spr[i+1];
				spr[i+1] = temp;
			}
			i++;
		}
		i = 0;
		j++;
	}

	// for(int i = 0; i < all->spr_num; i++)
	// {
	// printf("before : spr[%d] length : %f, x : %f, y : %f , distx : %f, disty : %f, coefx : %f, coefy : %f, depth_unit : %f, centerx : %f\n",i, spr[i].real_depth, spr[i].x, spr[i].y, spr[i].distx, spr[i].disty, spr[i].coefx, spr[i].coefy, spr[i].depth_unit, spr[i].centerx);
	// }
}

void	draw_sprite(t_all *all,t_sprite *spr,int x,int spr_x)
{
	int	pixel;
	int	dot;
	int	center;
	int	spr_y;
	int	y;

	center = all->height / 2;
	y = (center - spr->size / 2) - 1;
	if (y < 0)
		y = -1;
	spr_y = -1;
	while (++y < center + spr->size / 2)
	{
		++spr_y;
		dot = (int)(x + all->width * y);
		pixel = (int)(spr_x * spr->tex_step) + \
				(int)(spr_y * spr->tex_step) * texheight;
		if (x < all->width && y < all->height && \
				pixel < pow(texheight, 2))
		{
			if (all->texture[4][pixel] & 0x00FFFFFF)
				all->buf[y][x] = all->texture[4][pixel];
		}
	}
}

void	put_spr_buf(t_all *all, t_sprite *spr)
{
	int x;
	int spr_x;

	x = spr->drawstart - 1;
	while (++x < all->width)
	{
		if (x >= spr->drawstart && x <= spr->drawend)
		{
			spr_x = x - spr->drawstart;
			if (all->zbuf[x] > spr->coefy && spr_x > 0)
				draw_sprite(all, spr, x, spr_x);
		}
	}
}



void	calc(t_all *all)
{
	int x;
	t_calc cal;
	t_sprite *spr;

	x = 0;
	spr = sprite_init(all);
	all->spr_cnt = 0;
	//printf("width : %d height : %d\nposx : %f, posy : %f \n dirx : %f, diry : %f\nplanex : %f, planey : %f\n\n", all->width, all->height, all->posx, all->posy, all->dirx, all->diry, all->planex, all->planey);
	while (x < all->width)
	{
		calc_init(all, &cal, x);
		set_step_side(all, &cal);
		set_hit(all, &cal, spr);
		set_draw_point(all, &cal, x);
		set_tex_point(all, &cal);
		put_back_buf(all, x);
		put_wall_buf(all, &cal, x);
		x++;
	}
	printf("hihi : %d\n", all->spr_cnt);
	sort_spr(all, spr, all->spr_num);
	for(int i = 0; i < all->spr_num; i++)
		put_spr_buf(all, &spr[i]);
}
