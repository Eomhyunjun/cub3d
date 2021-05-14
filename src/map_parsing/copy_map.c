/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:11:23 by heom              #+#    #+#             */
/*   Updated: 2021/05/14 20:15:57 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int 	is_ok(char map_val, t_info *parse_info, int x, int y)
{
	if (map_val == ' ' || map_val == '0' || map_val == '1' || map_val == '2')
		return (1);
	else if (map_val == 'N' || map_val == 'S' || map_val == 'E' || map_val == 'W')
	{
		parse_info->dir = map_val;
		parse_info->pos[0] = x;
		parse_info->pos[1] = y;
		return (1);
	}
	return (0);
}

int 	copy_map(t_list *map_list, char **map, t_info *parse_info, int y)
{
	int x;
	x = 0;

	(*map)[x++] = ' ';
	while (map_list->content[x - 1])
	{
		(*map)[x] = map_list->content[x - 1];
		if (is_ok((*map)[x], parse_info, x, y) == 0)
			return (0);
		x++;
	}
	while (x <= parse_info->longlen)
		(*map)[x++] = ' ';
	(*map)[x++] = ' ';
	(*map)[x] = '\0';
	return (1);
}