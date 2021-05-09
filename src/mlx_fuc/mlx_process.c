/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 15:53:15 by heom              #+#    #+#             */
/*   Updated: 2021/05/09 16:28:49 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int 	mlx_process(t_info parse_info, char **map)
{
	void	*mlx;
	void	*win;
	t_mini	mini;

	mini.width = ft_atoi(parse_info.rw);
	mini.height = ft_atoi(parse_info.rh);
	mini.cols = parse_info.cols + 2;
	mini.rows = parse_info.longlen + 2;
	mini.map = map;
	about_init(&mini);
	//doge.img
	//mini.img.img = mlx_xpm_file_to_image(mlx, "./doge.xpm", &mini.cols, &mini.rows);
	//mlx_put_image_to_window(mini.mlx, mini.win, mini.img.img, 0, 0);
	draw_mini_map(&mini);
	init_player(&mini);
	mlx_hook(mini.win, X_EVENT_KEY_PRESS, 0, &press_key_for_dot, &mini);
	mlx_loop(mini.mlx);
	return (0);
}