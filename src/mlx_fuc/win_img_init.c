/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_img_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:54:26 by heom              #+#    #+#             */
/*   Updated: 2021/05/07 16:01:54 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	win_img_init(t_mini *mini)
{
	mini->player.color = 0xFF0000;
	mini->player.x = 100;
	mini->player.y = 100;
	mini->grid_color = 0xFFFFFF;
	mini->mlx = mlx_init();
	mini->win = mlx_new_window(mini->mlx, mini->width, mini->height, "HEOM's Cub3d Mini_Map");
    mini->img.img = mlx_new_image(mini->mlx, mini->width, mini->height);
}