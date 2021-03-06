/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:55:34 by heom              #+#    #+#             */
/*   Updated: 2021/05/23 20:49:43 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

char	**make_matrix(t_list *map_list, char **map, t_info *parse_info)
{
	int	lstsize;
	int	i;

	i = 0;
	lstsize = ft_lstsize(map_list) + 3;
	if (!(map = (char **)malloc(sizeof(char *) * lstsize)))
		return (NULL);
	map[i++] = put_space(parse_info->longlen);
	while (map_list)
	{
		if (!(map[i] = (char *)malloc(parse_info->longlen + 3)))
			return (NULL);
		if (!(copy_map(map_list, &map[i], parse_info, i)))
			return (NULL);
		map_list = map_list->next;
		i++;
	}
	map[i++] = put_space(parse_info->longlen);
	if (parse_info->pos[0] < 0)
		return (NULL);
	map[i] = NULL;
	return (map);
}
