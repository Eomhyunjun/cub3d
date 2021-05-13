/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 20:15:57 by heom              #+#    #+#             */
/*   Updated: 2021/05/13 20:16:08 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int	key_press(int key, t_all *all)
{
	if (key == K_W)
	{
		if (all->map[(int)(all->posY)][(int)(all->posX + all->dirX * all->moveSpeed)] == 'x')
			all->posX += all->dirX * all->moveSpeed;
		if (all->map[(int)(all->posY + all->dirY * all->moveSpeed)][(int)(all->posX)] == 'x')
			all->posY += all->dirY * all->moveSpeed;
	}
	if (key == K_S)
	{
		if (all->map[(int)(all->posY)][(int)(all->posX - all->dirX * all->moveSpeed)] == 'x')
			all->posX -= all->dirX * all->moveSpeed;
		if (all->map[(int)(all->posY - all->dirY * all->moveSpeed)][(int)(all->posX)] == 'x')
			all->posY -= all->dirY * all->moveSpeed;
	}
	if (key == K_D)
	{
		double oldDirX = all->dirX;
		all->dirX = all->dirX * cos(-all->rotSpeed) - all->dirY * sin(-all->rotSpeed);
		all->dirY = oldDirX * sin(-all->rotSpeed) + all->dirY * cos(-all->rotSpeed);
		double oldPlaneX = all->planeX;
		all->planeX = all->planeX * cos(-all->rotSpeed) - all->planeY * sin(-all->rotSpeed);
		all->planeY = oldPlaneX * sin(-all->rotSpeed) + all->planeY * cos(-all->rotSpeed);
	}
	if (key == K_A)
	{
		double oldDirX = all->dirX;
		all->dirX = all->dirX * cos(all->rotSpeed) - all->dirY * sin(all->rotSpeed);
		all->dirY = oldDirX * sin(all->rotSpeed) + all->dirY * cos(all->rotSpeed);
		double oldPlaneX = all->planeX;
		all->planeX = all->planeX * cos(all->rotSpeed) - all->planeY * sin(all->rotSpeed);
		all->planeY = oldPlaneX * sin(all->rotSpeed) + all->planeY * cos(all->rotSpeed);
	}
	if (key == K_ESC)
		exit(0);
	return (0);
}