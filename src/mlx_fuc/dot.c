/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:57:14 by heom              #+#    #+#             */
/*   Updated: 2021/05/07 15:59:07 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	init_player(t_mini *mini)
{
	mlx_pixel_put(mini->mlx, mini->win, mini->player.x, mini->player.y, mini->player.color);
}

void	move_dot_left(t_mini *mini)
{
	int	old_x = mini->player.x;
	int old_y = mini->player.y;
	int	black = 0x000000;
	if ((0 < mini->player.x && mini->player.x <= mini->width) &&
		(0 < mini->player.y && mini->player.x <= mini->height))
	{
		//draw old spot with black first
		mlx_pixel_put(mini->mlx, mini->win, old_x, old_y, black);
		//then draw new spot
		mlx_pixel_put(mini->mlx, mini->win, --mini->player.x, mini->player.y, mini->player.color);
	}
}

void	move_dot_right(t_mini *mini)
{
	int	old_x = mini->player.x;
	int old_y = mini->player.y;
	int	black = 0x000000;
	if ((0 < mini->player.x && mini->player.x <= mini->width) &&
		(0 < mini->player.y && mini->player.x <= mini->height))
	{
		//draw old spot with black first
		mlx_pixel_put(mini->mlx, mini->win, old_x, old_y, black);
		//then draw new spot
		mlx_pixel_put(mini->mlx, mini->win, ++mini->player.x, mini->player.y, mini->player.color);
	}
}

void	move_dot_up(t_mini *mini)
{
	int	old_x = mini->player.x;
	int old_y = mini->player.y;
	int	black = 0x000000;
	if ((0 < mini->player.x && mini->player.x <= mini->width) &&
		(0 < mini->player.y && mini->player.x <= mini->height))
	{
		//draw old spot with black first
		mlx_pixel_put(mini->mlx, mini->win, old_x, old_y, black);
		//then draw new spot
		mlx_pixel_put(mini->mlx, mini->win, mini->player.x, --mini->player.y, mini->player.color);
	}
}

void	move_dot_down(t_mini *mini)
{
	int	old_x = mini->player.x;
	int old_y = mini->player.y;
	int	black = 0x000000;
	if ((0 < mini->player.x && mini->player.x <= mini->width) &&
		(0 < mini->player.y && mini->player.x <= mini->height))
	{
		//draw old spot with black first
		mlx_pixel_put(mini->mlx, mini->win, old_x, old_y, black);
		//then draw new spot
		mlx_pixel_put(mini->mlx, mini->win, mini->player.x, ++mini->player.y, mini->player.color);
	}
}

int		press_key_for_dot(int key, t_mini *mini)
{
	if (key == KEY_A)
		move_dot_left(mini);
	else if (key == KEY_D)
		move_dot_right(mini);
	else if (key == KEY_W)
		move_dot_up(mini);
	else if (key == KEY_S)
		move_dot_down(mini);
	return (0);
}