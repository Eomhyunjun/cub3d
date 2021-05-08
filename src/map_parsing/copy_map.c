/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:11:23 by heom              #+#    #+#             */
/*   Updated: 2021/05/07 15:02:53 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int     is_ok(char map_val)
{
    if (map_val == ' ' || map_val == '0' || map_val == '1' || map_val == '2')
        return (1);
    else if (map_val == 'N' || map_val == 'S' || map_val == 'E' || map_val == 'W')
        return (1);
    return (0);
}

int     copy_map(t_list *map_list, char **map, int longlen)
{
    int i;
    i = 0;

    (*map)[i++] = ' ';
    while (map_list->content[i - 1])
    {
        (*map)[i] = map_list->content[i - 1];
        if(is_ok((*map)[i]) == 0)
            return (0);
        i++;
    }
    while (i <= longlen)
        (*map)[i++] = ' ';
    (*map)[i++] = ' ';
    (*map)[i] = '\0';
    return (1);
}