/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 20:15:57 by heom              #+#    #+#             */
/*   Updated: 2021/05/24 14:21:07 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int		key_press(int key, t_all *all)
{
	if (key == K_ESC)
		exit(0);
		
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
		exit(0);
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

void	key_go(t_all *all, int c)
{
	int x;
	int y;

	x = (int)(all->posx + c * all->dirx * all->movespeed);
	y = (int)(all->posy + c * all->diry * all->movespeed);
	if (all->map[(int)(all->posy)][x] == 'x')
		all->posx += c * all->dirx * all->movespeed;
	if (all->map[y][(int)(all->posx)] == 'x')
		all->posy += c * all->diry * all->movespeed;
}

void	key_left(t_all *all, int c)
{
	int x;
	int y;

	x = (int)(all->posx + c * all->diry * all->movespeed);
	y = (int)(all->posy - c * all->dirx * all->movespeed);
	if (all->map[(int)(all->posy)][x] == 'x')
		all->posx += c * all->diry * all->movespeed;
	if (all->map[y][(int)(all->posx)] == 'x')
		all->posy += -c * all->dirx * all->movespeed;
}

void	key_update(t_all *all)
{
	if (all->k_w)
		key_go(all, 1);
	if (all->k_s)
		key_go(all, -1);
	if (all->k_a)
		key_left(all, -1);
	if (all->k_d)
		key_left(all, 1);
	if (all->k_lf)
		rotation(all, all->rotspeed * 180 / M_PI);
	if (all->k_rt)
		rotation(all, -all->rotspeed * 180 / M_PI);
}
