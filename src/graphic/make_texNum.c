/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_texNum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 20:55:01 by heom              #+#    #+#             */
/*   Updated: 2021/05/13 20:57:40 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int		make_texNum(t_all *all, int y, int x, int side)
{
	int texNum;

	texNum = all->map[y][x];
	if (texNum == '1')
	{
		if (all->dirX >= 0 && all->dirY >= 0)
			if (side == 1)
				return (0);
			else
				return (3);
		else if (all->dirX > 0 && all->dirY < 0)
			if (side == 1)
				return (2);
			else
				return (0);
		else if (all->dirX < 0 && all->dirY > 0)
			if (side == 1)
				return (3);
			else
				return (1);
		else if (all->dirX <= 0 && all->dirY <= 0)
		{
			if (side == 1)
				return (1);
			else
				return (2);
		}
	}
	return (5);
}