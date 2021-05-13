/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:28:48 by heom              #+#    #+#             */
/*   Updated: 2021/05/13 17:03:35 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int	main_loop(t_all *all)
{
	calc(all);
	draw(all);
	return (0);
}

int		mlx_process(t_info *parse_info, char **map)
{
	t_all	all;
	
	all_init(&all, parse_info);
	all.map = map;

	printf("printf_map_in_all\n");
	printf("====================================================\n");
	int i = 0;
	int j = 0;
	while (map[i])
	{
		while(map[i][j])
		{
			printf("|%c|", map[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	printf("====================================================\n");
	
	malloc_buf(&all);
	texture_init(&all, parse_info);
	mlx_loop_hook(all.mlx, &main_loop, &all);
	mlx_hook(all.win, X_EVENT_KEY_PRESS, 0, &key_press, &all);

	mlx_loop(all.mlx);
	return (0);
}