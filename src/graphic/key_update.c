/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_update.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/14 14:02:04 by heom              #+#    #+#             */
/*   Updated: 2021/05/14 16:13:22 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	key_update(t_all *all)
{
	if (all->k_w)
	{
		if (all->map[(int)(all->posY)][(int)(all->posX + all->dirX * all->moveSpeed)] == 'x')
			all->posX += all->dirX * all->moveSpeed;
		if (all->map[(int)(all->posY + all->dirY * all->moveSpeed)][(int)(all->posX)] == 'x')
			all->posY += all->dirY * all->moveSpeed;
	}
	if (all->k_s)
	{
		if (all->map[(int)(all->posY)][(int)(all->posX - all->dirX * all->moveSpeed)] == 'x')
			all->posX -= all->dirX * all->moveSpeed;
		if (all->map[(int)(all->posY - all->dirY * all->moveSpeed)][(int)(all->posX)] == 'x')
			all->posY -= all->dirY * all->moveSpeed;
	}
	if (all->k_a)
	{
		if (all->map[(int)(all->posY)][(int)(all->posX - all->dirY * all->moveSpeed)] == 'x')
			all->posX -= all->dirY * all->moveSpeed;
		if (all->map[(int)(all->posY + all->dirX * all->moveSpeed)][(int)(all->posX)] == 'x')
			all->posY += all->dirX * all->moveSpeed;
	}
	if (all->k_d)
	{
		if (all->map[(int)(all->posY - all->dirX * all->moveSpeed)][(int)(all->posX)] == 'x')
			all->posY -= all->dirX * all->moveSpeed;
		if (all->map[(int)(all->posY)][(int)(all->posX + all->dirY * all->moveSpeed)] == 'x')
			all->posX += all->dirY * all->moveSpeed;
	}
	if (all->k_lf)
	{
		double oldDirX = all->dirX;
		all->dirX = all->dirX * cos(all->rotSpeed) - all->dirY * sin(all->rotSpeed);
		all->dirY = oldDirX * sin(all->rotSpeed) + all->dirY * cos(all->rotSpeed);
		double oldPlaneX = all->planeX;
		all->planeX = all->planeX * cos(all->rotSpeed) - all->planeY * sin(all->rotSpeed);
		all->planeY = oldPlaneX * sin(all->rotSpeed) + all->planeY * cos(all->rotSpeed);
	}
	if (all->k_rt)
	{
		double oldDirX = all->dirX;
		all->dirX = all->dirX * cos(-all->rotSpeed) - all->dirY * sin(-all->rotSpeed);
		all->dirY = oldDirX * sin(-all->rotSpeed) + all->dirY * cos(-all->rotSpeed);
		double oldPlaneX = all->planeX;
		all->planeX = all->planeX * cos(-all->rotSpeed) - all->planeY * sin(-all->rotSpeed);
		all->planeY = oldPlaneX * sin(-all->rotSpeed) + all->planeY * cos(-all->rotSpeed);
	}
}