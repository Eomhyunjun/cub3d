/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:21:42 by heom              #+#    #+#             */
/*   Updated: 2021/05/23 17:55:44 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void sort_spr(t_all *all, t_sprite *spr)
{
	int i;
	int j;
	t_sprite temp;

	j = 0;
	while (j < all->spr_num - 1)
	{
		i = 0;
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
		j++;
	}
}

void	draw_sprite(t_all *all,t_sprite *spr,int x,int spr_x)
{
	int	pixel;
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
		pixel = (int)(spr_x * spr->tex_step) + \
				(int)(spr_y * spr->tex_step) * texheight;
		if (x < all->width && y < all->height && \
				pixel < texheight * texwidth)
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

	x = -1;
	while (++x < all->width)
	{
		if (x >= spr->drawstart && x <= spr->drawend)
		{
			spr_x = x - spr->drawstart;
			if (all->zbuf[x] > spr->coefy && spr_x > 0 && x < all->width && spr->coefy > 0 )
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
	sort_spr(all, spr);
	for(int i = 0; i < all->spr_num; i++)
		put_spr_buf(all, &spr[i]);
}
