/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:34:30 by heom              #+#    #+#             */
/*   Updated: 2021/05/21 20:03:30 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int		is_x_here(t_all *all, t_calc *cal, t_sprite *spr)
{
	int i;

	i = 0;
	while (i < all->spr_num)
	{
		if(spr[i].x == (int)cal->mapx + 0.5 && spr[i].y == (int)cal->mapy + 0.5)
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
	spr->x = (int)cal->mapx + 0.5;
	spr->y = (int)cal->mapy + 0.5;
	if (spr->x == 0)
		spr->x = 0.0001;
	spr->distx =spr->x - all->posx;
	spr->disty =spr->y - all->posy;
	set_coef(all, spr);
	spr->centerx = (spr->coefx/spr->coefy + 1) * all->width / 2;
	spr->depth_unit = fabs(spr->coefx / spr->coefy);
	spr->real_depth = fabs(spr->coefx / spr->depth_unit);
	spr->size = (int)(all->height / spr->real_depth / 2);
	spr->drawstart = spr->centerx - spr->size / 2;
	spr->drawend = spr->centerx + spr->size /2;
	spr->tex_scale = spr->size / texwidth;
	spr->tex_step = 1.0 / spr->tex_scale;
}
