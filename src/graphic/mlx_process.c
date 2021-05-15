/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:28:48 by heom              #+#    #+#             */
/*   Updated: 2021/05/15 18:24:23 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int	main_loop(t_all *all)
{
	key_update(all);
	calc(all);
	draw(all);

	printf("printf_map_in_all\n");
	printf("====================================================\n");
	int i = 0;
	int j = 0;
	while (all->map[i])
	{
		while(all->map[i][j])
		{
			if(i == (int)all->posy && j == (int)all->posx)
				printf("|P|");
			else
				printf("|%c|", all->map[i][j]);
			j++;
		}
		printf("\n");
		j = 0;
		i++;
	}
	printf("====================================================\n");
	
	return (0);
}

int		mlx_process(t_info *parse_info, char **map)
{
	t_all	all;
	
	all.map = map;
	all_init(&all, parse_info);
	all.map[parse_info->pos[1]][parse_info->pos[0]] = 'x';
	malloc_buf(&all);
	if(!(texture_init(&all, parse_info)))
		return (0);
	mlx_hook(all.win, X_EVENT_KEY_PRESS, 0, &key_press, &all);
	mlx_hook(all.win, X_EVENT_KEY_RELEASE, 0, &key_release, &all);
	mlx_loop_hook(all.mlx, &main_loop, &all);
	mlx_loop(all.mlx);
	return (1);
}