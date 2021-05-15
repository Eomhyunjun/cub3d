/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:02:04 by heom              #+#    #+#             */
/*   Updated: 2021/05/15 20:49:28 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"



void	key_update(t_all *all)
{
	if (all->k_w)
	{
		if (all->map[(int)(all->posy)][(int)(all->posx + all->dirx * all->movespeed)] == 'x')
			all->posx += all->dirx * all->movespeed;
		if (all->map[(int)(all->posy + all->diry * all->movespeed)][(int)(all->posx)] == 'x')
			all->posy += all->diry * all->movespeed;
	}
	if (all->k_s)
	{
		if (all->map[(int)(all->posy)][(int)(all->posx - all->dirx * all->movespeed)] == 'x')
			all->posx -= all->dirx * all->movespeed;
		if (all->map[(int)(all->posy - all->diry * all->movespeed)][(int)(all->posx)] == 'x')
			all->posy -= all->diry * all->movespeed;
	}
	if (all->k_a)
	{
		if (all->map[(int)(all->posy)][(int)(all->posx - all->diry * all->movespeed)] == 'x')
			all->posx -= all->diry * all->movespeed;
		if (all->map[(int)(all->posy + all->dirx * all->movespeed)][(int)(all->posx)] == 'x')
			all->posy += all->dirx * all->movespeed;
	}
	if (all->k_d)
	{
		if (all->map[(int)(all->posy - all->dirx * all->movespeed)][(int)(all->posx)] == 'x')
			all->posy -= all->dirx * all->movespeed;
		if (all->map[(int)(all->posy)][(int)(all->posx + all->diry * all->movespeed)] == 'x')
			all->posx += all->diry * all->movespeed;
	}
	if (all->k_lf)
		rotation(all, all->rotspeed * 108 / M_PI);
	if (all->k_rt)
		rotation(all, -all->rotspeed * 108 / M_PI);
}