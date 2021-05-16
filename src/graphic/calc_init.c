/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:17:27 by heom              #+#    #+#             */
/*   Updated: 2021/05/16 16:17:37 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	calc_init(t_all *all, t_calc *cal, int x)
{
	cal->camerax = 2 * x / (double)all->width - 1;
	cal->raydirx = all->dirx + all->planex * cal->camerax;
	cal->raydiry = all->diry + all->planey * cal->camerax;
	cal->mapx = (int)all->posx;
	cal->mapy = (int)all->posy;
	cal->deltadistx = (cal->raydiry == 0) ? 0 : ((cal->raydirx == 0) ? 1 : fabs(1 / cal->raydirx));
	cal->deltadisty = (cal->raydirx == 0) ? 0 : ((cal->raydiry == 0) ? 1 : fabs(1 / cal->raydiry));
	cal->hit = 0;
}