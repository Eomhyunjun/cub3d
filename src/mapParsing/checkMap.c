/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:09:27 by heom              #+#    #+#             */
/*   Updated: 2021/05/04 15:35:42 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int	check_map(char **map, int x, int y)
{
	int i;
    int	g_dirx[8] = {-1, 0, 1, 0, -1, -1, 1, 1}; 
    int	g_diry[8] = {0, 1, 0, -1, -1, 1, 1, -1};
    
	if (map[y][x] == '1' || map[y][x] == 'x')
		return (1);
	if (map[y][x] == ' ')	
		return (0);
	map[y][x] = 'x';
	i = -1;
	while (++i < 8)
		if (check_map(map, x + g_dirx[i], y + g_diry[i]) == 0)
			return (0);
	return (1);
}

int     mapErrCehck(char **map)
{
    int is_zero = 0;
    int x = 0;
    int y = 0;
    
    while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == '0')	
			{
				is_zero = 1;
				if (check_map(map, x, y) == 0)
				{
					write(1, "ERROR\n", 6);
					return (0) ;
				}
			}
	}
	if (is_zero == 0)
		write(1, "ERROR\n", 6);
	else
		write(1, "OK\n", 3);
	return (0);
    return (1);
}

char    **checkMap(t_list *map_list, char **map, t_info *parse_info)
{
    int res;
    char *space;
    /*Linkedlist->matrix*/
    map = makeMatrix(map_list, map, parse_info->longlen);
    mapErrCehck(map);
    return (map);
}