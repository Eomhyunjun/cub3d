/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:46:44 by heom              #+#    #+#             */
/*   Updated: 2021/05/24 14:03:04 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	put_back_buf(t_all *all, int x)
{
	int y;

	y = 0;
	while (y < all->height / 2)
	{
		all->img.data[y++ * all->width + x] = all->texture[5][0];
	}
	y = all->height / 2;
	while (y < all->height)
	{
		all->img.data[y++ * all->width + x] = all->texture[6][0];
	}
}

void	put_wall_buf(t_all *all, t_calc *cal, int x)
{
	int y;

	y = cal->drawstart;
	while (y < cal->drawend)
	{
		cal->texy = (int)cal->texpos & (TEXHEIGHT - 1);
		cal->texpos += cal->step;
		cal->color = all->texture[cal->texnum]\
		[TEXHEIGHT * cal->texy + cal->tex];
		if (cal->side == 1)
			cal->color = (cal->color >> 1) & 8355711;
		all->img.data[y * all->width + x] = cal->color;
		y++;
	}
	all->zbuf[x] = cal->perpwalldist;
}
