/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:55:53 by heom              #+#    #+#             */
/*   Updated: 2021/05/07 16:00:33 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	draw_wall(t_mini *mini, int y, int x)
	{
		int penX;
		int penY;

		penY = y * 25;
		while (penY < (y + 1) * 25)
		{
			penX = x * 25;
			while(penX < (x + 1) * 25)
			{
				mlx_pixel_put(mini->mlx, mini->win, penX, penY, mini->grid_color);
				penX++;
			}
			penY++;
		}
	}

int		draw_mini_map(t_mini *mini)
{
	int	i;
	int j;
	int	pen;

	i = 0;
	while (i <= mini->cols)
	{
		pen = 0;
		while (pen <= mini->rows * 25){
			mlx_pixel_put(mini->mlx, mini->win, pen, i * 25, mini->grid_color);
			pen++;
		}
		i++;
	}
	i = 0;
	while (i <= mini->rows)
	{
		pen = 0;
		while (pen <= mini->cols * 25)
		{
			mlx_pixel_put(mini->mlx, mini->win, i * 25, pen, mini->grid_color);
			pen++;
		}
		i++;
	}
	i = 0;
	while (mini->map[i])
	{
		j = 0;
		while(mini->map[i][j])
		{
			if (mini->map[i][j] == '1')
			{
				draw_wall(mini, i, j);
			}
			j++;
		}
		i++;
	}	

	return (0);
}