/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:34:30 by heom              #+#    #+#             */
/*   Updated: 2021/05/19 21:07:05 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int		is_x_here(t_all *all, t_calc *cal, t_sprite *spr)
{
	int i;

	i = 0;
	while (i < all->spr_num)
	{
		if(spr[i].x == (int)cal->mapx && spr[i].y == (int)cal->mapy)
			return (1);
		i++;
	}
	return (0);
}

void	set_coef(t_all *all, t_sprite *spr)
{
	spr->coefx = all->diry * spr->distx - all->dirx * spr->disty;
	spr->coefy = -all->planey * spr->distx + all->planex * spr->disty;
	spr->coefx /= (all->planex * all->diry - all->dirx * all->planey);
	spr->coefy /= (all->planex * all->diry - all->dirx * all->planey);
	all->spr_cnt++;
}

void	set_sprite(t_all *all, t_calc *cal, t_sprite *spr)
{
	spr->x = (int)cal->mapx;
	spr->y = (int)cal->mapy;
	spr->distx =spr->x - all->posx;
	spr->disty =spr->y - all->posy;
	set_coef(all, spr);
	spr->centerx = (spr->coefx/spr->coefy + 1) * all->width / 2;
	spr->depth_unit = fabs(spr->coefx / spr->coefy);
	spr->real_depth = spr->coefx / spr->depth_unit;
	spr->size = all->height / spr->real_depth;
	spr->drawstart = spr->centerx - spr->size / 2;
	spr->drawend = spr->centerx + spr->size /2;
	if (spr->drawstart < 0)
		spr->drawstart = 0;
	if (spr->drawend < 0)
		spr->drawend = 0;
	spr->tex_scale = spr->size / texwidth;
	spr->tex_step = 1.0 / spr->tex_scale;
}
