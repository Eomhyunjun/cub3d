/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:20:04 by heom              #+#    #+#             */
/*   Updated: 2021/05/23 17:55:28 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	set_step_side(t_all *all, t_calc *cal)
{
		if (cal->raydirx < 0)
		{
			cal->stepx = -1;
			cal->sidedistx = (all->posx - cal->mapx) * cal->deltadistx;
		}
		else
		{
			cal->stepx = 1;
			cal->sidedistx = (cal->mapx + 1.0 - all->posx) * cal->deltadistx;
		}
		if (cal->raydiry < 0)
		{
			cal->stepy = -1;
			cal->sidedisty = (all->posy - cal->mapy) * cal->deltadisty;
		}
		else
		{
			cal->stepy = 1;
			cal->sidedisty = (cal->mapy + 1.0 - all->posy) * cal->deltadisty;
		}
}


void	set_hit(t_all *all, t_calc *cal, t_sprite *spr)
{
	int res;
	while (cal->hit == 0)
	{
		if (cal->sidedistx < cal->sidedisty)
		{
			cal->sidedistx += cal->deltadistx;
			cal->mapx += cal->stepx;
			cal->side = 0;
		}
		else
		{
			cal->sidedisty += cal->deltadisty;
			cal->mapy += cal->stepy;
			cal->side = 1;
		}
		if (all->map[cal->mapy][cal->mapx] == '2')
		{
			if (!(res = is_x_here(all, cal, spr)))
			{
				set_sprite(all, cal, &spr[all->spr_cnt]);
			}
		}
		if (all->map[cal->mapy][cal->mapx] == '1')
			cal->hit = 1;
	}
}

void	set_draw_point(t_all *all, t_calc *cal, int x)
{
	if (cal->side == 0)
		cal->perpwalldist = (cal->mapx - all->posx + (1 - cal->stepx) / 2) / cal->raydirx;
	else
		cal->perpwalldist = (cal->mapy - all->posy + (1 - cal->stepy) / 2) / cal->raydiry;
	
	cal->lineheight = (int)(all->height / cal->perpwalldist);
	if (cal->perpwalldist <= 0.01 && cal->perpwalldist >= -0.01)
		cal->lineheight = 0;
	cal->drawstart = -cal->lineheight / 2 + all->height / 2;
	if(cal->drawstart < 0)
		cal->drawstart = 0;
	cal->drawend = cal->lineheight / 2 + all->height / 2;
	if(cal->drawend >= all->height)
		cal->drawend = all->height - 1;
	all->zbuf[x] = cal->perpwalldist;
}

void	set_tex_point(t_all *all, t_calc *cal)
{
		cal->texnum = make_texnum(cal->stepx, cal->stepy, cal->side);

		if (cal->side == 0)
			cal->wallx = all->posy + cal->perpwalldist * cal->raydiry;
		else
			cal->wallx = all->posx + cal->perpwalldist * cal->raydirx;
		cal->wallx -= floor(cal->wallx);

		cal->tex = (int)(cal->wallx * (double)texwidth);
		if (cal->side == 0 && cal->raydirx > 0)
			cal->tex = texwidth - cal->tex - 1;
		if (cal->side == 1 && cal->raydiry < 0)
			cal->tex = texwidth - cal->tex - 1;

		cal->step = 1.0 * texheight / cal->lineheight;
		cal->texpos = (cal->drawstart - all->height / 2 + cal->lineheight / 2) * cal->step;
}

