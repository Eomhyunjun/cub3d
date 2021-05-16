/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   all_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:32:13 by heom              #+#    #+#             */
/*   Updated: 2021/05/16 14:38:10 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	all_init(t_all *all, t_info *parse_info)
{
	all->posx = parse_info->pos[0];
	all->posy = parse_info->pos[1];
	all->dirx = -1.0;
	all->diry = 0.0;
	all->planex = 0.0;
	all->planey = 0.66;
	rotation_pro(parse_info, all);
	all->movespeed = 0.05;
	all->rotspeed = 0.05;

	all->mlx = mlx_init();

	all->width = ft_atoi(parse_info->rw);
	all->height = ft_atoi(parse_info->rh);
	all->win = mlx_new_window(all->mlx, all->width, all->height, "my_cub3");
	all->img.img = mlx_new_image(all->mlx, all->width, all->height);
	all->img.data = (int *)mlx_get_data_addr(all->img.img, &all->img.bits_per_pixel, &all->img.line_length, &all->img.endian);
}