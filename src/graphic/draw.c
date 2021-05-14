/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 20:14:44 by heom              #+#    #+#             */
/*   Updated: 2021/05/14 11:16:15 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	draw(t_all *all)
{
	for (int y = 0; y < all->height; y++)
	{
		for (int x = 0; x < all->width; x++)
		{
			all->img.data[y * all->width + x] = all->buf[y][x];
		}
	}
	mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
}