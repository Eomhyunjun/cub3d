/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 20:14:44 by heom              #+#    #+#             */
/*   Updated: 2021/05/23 18:02:18 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	draw(t_all *all)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (y < all->height)
	{
		while (x < all->width)
		{
			all->img.data[y * all->width + x] = all->buf[y][x];
			x++;
		}
		y++;
		x = 0;
	}
	mlx_sync(MLX_SYNC_IMAGE_WRITABLE, all->img.img);
	mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
	mlx_sync(MLX_SYNC_WIN_CMD_COMPLETED, all->win);
}
