/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:40:41 by heom              #+#    #+#             */
/*   Updated: 2021/05/16 14:40:49 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int	main_loop(t_all *all)
{
	calc(all);
	draw(all);
	key_update(all);
	
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