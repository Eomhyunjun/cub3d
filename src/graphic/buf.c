/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:46:44 by heom              #+#    #+#             */
/*   Updated: 2021/05/18 14:35:11 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	put_back_buf(t_all *all, int x)
{
		for (int y = 0; y < all->height / 2; y++)
		{
				all->buf[y][x] = all->texture[5][0];
		}

		for (int y = all->height / 2; y < all->height; y++)
		{
				all->buf[y][x] = all->texture[6][0];
		}
}


void	put_wall_buf(t_all *all,t_calc *cal, int x)
{
		for (int y = cal->drawstart; y < cal->drawend; y++)
		{
			cal->texy = (int)cal->texpos & (texheight - 1);
			cal->texpos += cal->step;
			cal->color = all->texture[cal->texnum][texheight * cal->texy + cal->tex];
			if (cal->side == 1)
				cal->color = (cal->color >> 1) & 8355711;
			all->buf[y][x] = cal->color;
		}
		all->zbuf[x] = cal->perpwalldist;
}

void	malloc_buf(t_all *all)
{
	int i;
	int j;

	i = 0;
	all->buf = (int **)malloc(sizeof(int *) * all->height);
	while (i < all->height)
		all->buf[i++] = (int *)malloc(sizeof(int) * all->width);
	i = 0;
	j = 0;
	while (i < all->height)
	{
		while(j < all->width)
			all->buf[i][j++] = 0;
		i++;
	}
}