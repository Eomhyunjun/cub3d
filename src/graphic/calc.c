/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:21:42 by heom              #+#    #+#             */
/*   Updated: 2021/05/19 20:56:32 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void sort_spr(t_all *all, t_sprite *spr, int spr_num)
{
	int i;
	int j;
	int k;
	t_sprite *temp;

	i = 0;
	j = 0;
	k = 0;
	while (k < all->spr_num)
	{
		while (i < all->spr_num)
		{
			while (j < i)
			{
				if(spr[k].disty > spr[k+1].disty)
				{
					temp = &spr[k];
					spr[k] = spr[k+1];
					spr[k+1] = *temp;
				}
				j++;
			}
			j = 0;
			i++;
		}
		k++;
	}
	printf("spr[0] x : %f, y : %f , distx : %f, disty : %f, coefx : %f, coefy : %f, depth_unit : %f, centerx : %f\n", spr[0].x, spr[0].y, spr[0].distx, spr[0].disty, spr[0].coefx, spr[0].coefy, spr[0].depth_unit, spr[0].centerx);
	printf("spr[1] x : %f, y : %f , distx : %f, disty : %f, coefx : %f, coefy : %f, depth_unit : %f, centerx : %f\n", spr[1].x, spr[1].y, spr[1].distx, spr[1].disty, spr[1].coefx, spr[1].coefy, spr[1].depth_unit, spr[1].centerx);
	printf("spr[2] x : %f, y : %f , distx : %f, disty : %f, coefx : %f, coefy : %f, depth_unit : %f, centerx : %f\n", spr[2].x, spr[2].y, spr[2].distx, spr[2].disty, spr[2].coefx, spr[2].coefy, spr[2].depth_unit, spr[2].centerx);
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
			if (all->texture[4][pixel] != ' ')
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
	//printf("width : %d height : %d\nposx : %f, posy : %f \n dirx : %f, diry : %f\nplanex : %f, planey : %f\n\n", all->width, all->height, all->posx, all->posy, all->dirx, all->diry, all->planex, all->planey);
	while (x < all->width)
	{
		all->spr_cnt = 0;
		calc_init(all, &cal, x);
		set_step_side(all, &cal);
		set_hit(all, &cal, spr);
		set_draw_point(all, &cal, x);
		set_tex_point(all, &cal);
		put_back_buf(all, x);
		put_wall_buf(all, &cal, x);
		x++;
	}
	sort_spr(all, spr, all->spr_num);
	for(int i = 0; i < all->spr_num; i++)
		put_spr_buf(all, &spr[i]);
}
