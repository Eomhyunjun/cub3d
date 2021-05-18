/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/17 21:34:30 by heom              #+#    #+#             */
/*   Updated: 2021/05/18 14:02:06 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	tmp_sprite(t_all all, t_cal cal, t_list *sprtie_list)
{
	char spr_point[2];
	spr_point[0] = cal->mapx + 0.5;
	spr_point[1] = cal->mapy + 0.5;

	all->sprite->content = spr_point;
	ft_lstadd_back(&sprtie_list, ft_lstnew(all->sprite));
}

void	set_coef(t_all all, t_sprite *sprite)
{
	sprite->coefx = all->diry * sprite->distx - all->dirx * sprite->disty;
	sprite->coefy = -all->planey * sprite->distx + all->planex * sprite->disty;
	sprite->coefx /= (all->planex* all->diry - all->dirx * all->planey);
	sprite->coefy /= (all->planex* all->diry - all->dirx * all->planey);
}



void	set_sprite(t_all *all, t_calc *cal)
{
	t_sprite	sprite;
	
	sprite.dist_x =sprite.x - all->posx;
	sprite.dist_y =sprite.y - all->posy;
	set_coef(all, &sprite);
	sprite.centerx = sprtie.dist_x * all->width / 2;
	sprite.depth_unit = sprite.centerx * sprite.coefx / sprite.coefy;
	sprite.dist = sprtie.distx * sprite.distx + sprite.disty * sprite.disty;
	all->sprite = &sprite;
}