/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_draw_point.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:20:50 by heom              #+#    #+#             */
/*   Updated: 2021/05/16 16:38:36 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void set_draw_point(t_all *all, t_calc *cal)
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
}