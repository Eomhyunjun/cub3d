/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:20:04 by heom              #+#    #+#             */
/*   Updated: 2021/05/16 16:20:14 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	set_hit(t_all *all, t_calc *cal)
{
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
		if ('x' > all->map[cal->mapy][cal->mapx])
			cal->hit = 1;
	}
}