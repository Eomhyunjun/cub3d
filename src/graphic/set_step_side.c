/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_step_side.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:19:14 by heom              #+#    #+#             */
/*   Updated: 2021/05/16 16:19:21 by heom             ###   ########.fr       */
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