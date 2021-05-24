/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:09:27 by heom              #+#    #+#             */
/*   Updated: 2021/05/24 14:10:41 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	put_dirx(int *dirx)
{
	dirx[0] = -1;
	dirx[1] = 0;
	dirx[2] = 1;
	dirx[3] = 0;
	dirx[4] = -1;
	dirx[5] = -1;
	dirx[6] = 1;
	dirx[7] = 1;
}

void	put_diry(int *diry)
{
	diry[0] = 0;
	diry[1] = 1;
	diry[2] = 0;
	diry[3] = -1;
	diry[4] = -1;
	diry[5] = 1;
	diry[6] = 1;
	diry[7] = -1;
}

int		exam_map(char **map, int x, int y)
{
	int	i;
	int	g_dirx[8];
	int	g_diry[8];

	put_dirx(g_dirx);
	put_diry(g_diry);
	if (map[y][x] == '1' || map[y][x] == 'x' || map[y][x] == '2')
		return (1);
	if (map[y][x] == ' ')
		return (0);
	if (map[y][x] != 'E' && map[y][x] != 'W' &&\
		map[y][x] != 'N' && map[y][x] != 'S')
		map[y][x] = 'x';
	i = -1;
	while (++i < 8)
		if (exam_map(map, x + g_dirx[i], y + g_diry[i]) == 0)
			return (0);
	return (1);
}

int		map_errchk(char **map)
{
	int	is_zero;
	int	x;
	int	y;

	is_zero = 0;
	x = 0;
	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
			if (map[y][x] == '0')
			{
				is_zero = 1;
				if (exam_map(map, x, y) == 0)
					return (0);
			}
	}
	if (is_zero == 0)
		return (0);
	return (1);
}

char	**check_map(t_list *map_list, t_info *parse_info)
{
	char **map;

	map = NULL;
	map = make_matrix(map_list, map, parse_info);
	parse_info->cols = ft_lstsize(map_list);
	if (map == NULL)
		return (NULL);
	if (map_errchk(map) == 0)
		return (NULL);
	return (map);
}
