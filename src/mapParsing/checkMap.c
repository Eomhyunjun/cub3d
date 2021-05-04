/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:09:27 by heom              #+#    #+#             */
/*   Updated: 2021/05/04 10:09:55 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

char    **checkMap(t_list *map_list, char **map, t_info *parse_info)
{
    int res;
    char *space;

    map_list->content = putSpace(space, parse_info->longlen);
    ft_lstadd_back(&map_list, ft_lstnew(map_list->content));
    map = makeMatrix(map_list, map, parse_info->longlen);
    //makeSkin(map);
    return (map);
}