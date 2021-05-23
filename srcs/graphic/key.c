/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 20:15:57 by heom              #+#    #+#             */
/*   Updated: 2021/05/23 13:10:41 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int		key_press(int key, t_all *all)
{
	if (key == K_ESC)
	{
		//while (1);
		exit(0);
	}
	if (key == K_W)
		all->k_w = 1;
	if (key == K_S)
		all->k_s = 1;
	if (key == K_A)
		all->k_a = 1;
	if (key == K_D)
		all->k_d = 1;
	if (key == K_LF)
		all->k_lf = 1;
	if (key == K_RT)
		all->k_rt = 1;
	return (0);
}

int		key_release(int key, t_all *all)
{
	if (key == K_ESC)
	{
		//while (1);
		exit(0);
	}
	if (key == K_W)
		all->k_w = 0;
	if (key == K_S)
		all->k_s = 0;
	if (key == K_A)
		all->k_a = 0;
	if (key == K_D)
		all->k_d = 0;
	if (key == K_LF)
		all->k_lf = 0;
	if (key == K_RT)
		all->k_rt = 0;
	return (0);
}

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
		rotation(all, all->rotspeed * 180 / M_PI);
	if (all->k_rt)
		rotation(all, -all->rotspeed * 180 / M_PI);
}