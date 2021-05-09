/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   about_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:54:26 by heom              #+#    #+#             */
/*   Updated: 2021/05/09 19:02:04 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	about_init(t_mini *mini)
{
	mini->player.color = 0xFF0000;
	mini->player.x = 60;
	mini->player.y = 60;
	mini->grid_color = 0xFFFFFF;
	mini->mlx = mlx_init();
	mini->win = mlx_new_window(mini->mlx, mini->width, mini->height, "HEOM's Cub3d Mini_Map");
    mini->img.img = mlx_new_image(mini->mlx, mini->width, mini->height);
	mini->img.data = (int *)mlx_get_data_addr(mini->img.img, &(mini->img.bits_per_pixel), &(mini->img.line_length), &(mini->img.endian));

	mini->dir.x = -1;
	mini->dir.y = 0;
	mini->plane.x = 0;
	mini->plane.y = 0.66;

	double time = 0;
	double oldTime = 0;
	int x = 0;
	mini->camera.x = 2 * x / mini->width - 1;
	mini->rayDir.x = mini->dir.x + mini->plane.x * mini->camera.x;
	mini->rayDir.y = mini->dir.y + mini->plane.y * mini->camera.x;
	int mapX = int(mini->player.x);
	int mapY = int(mini->player.y);

	double sideDistX;
	double sideDistY;
	double deltaDistX = abs(1 / mini->rayDir.x);
	double deltaDistY = abs(1 / mini->rayDir.y);
}