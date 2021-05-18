/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:21:42 by heom              #+#    #+#             */
/*   Updated: 2021/05/18 19:07:44 by heom             ###   ########.fr       */
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
				if(spr[k].disty < spr[k+1].disty)
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
}
