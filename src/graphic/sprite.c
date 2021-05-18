/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:34:30 by heom              #+#    #+#             */
/*   Updated: 2021/05/18 19:10:00 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int		is_x_here(t_all *all, t_calc *cal, t_sprite *spr)
{
	int i;

	i = 0;
	while (i < all->spr_num)
	{
		if(spr[i].x == cal->mapx && spr[i].y == cal->mapy)
		{
			return (0);
		}
		i++;
	}
	return (1);
}

void	set_coef(t_all *all, t_sprite *spr)
{
	spr[all->spr_cnt].coefx = all->diry * spr[all->spr_cnt].distx - all->dirx * spr[all->spr_cnt].disty;
	spr[all->spr_cnt].coefy = -all->planey * spr[all->spr_cnt].distx + all->planex * spr[all->spr_cnt].disty;
	spr[all->spr_cnt].coefx /= (all->planex* all->diry - all->dirx * all->planey);
	spr[all->spr_cnt].coefy /= (all->planex* all->diry - all->dirx * all->planey);
	all->spr_cnt++;
}

void	tmp_sprite(t_all *all, t_calc *cal, t_sprite *spr)
{
	spr[all->spr_cnt].x = cal->mapx;
	spr[all->spr_cnt].y = cal->mapy;
	spr[all->spr_cnt].distx =spr[all->spr_cnt].x - all->posx;
	spr[all->spr_cnt].disty =spr[all->spr_cnt].y - all->posy;
	set_coef(all, spr);
	spr[all->spr_cnt].centerx = spr[all->spr_cnt].distx * all->width / 2;
	spr[all->spr_cnt].depth_unit = spr[all->spr_cnt].centerx * spr[all->spr_cnt].coefx / spr[all->spr_cnt].coefy;
	spr[all->spr_cnt].dist = spr[all->spr_cnt].distx * spr[all->spr_cnt].distx + spr[all->spr_cnt].disty * spr[all->spr_cnt].disty;
}
