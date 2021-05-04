/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copyMap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:11:23 by heom              #+#    #+#             */
/*   Updated: 2021/05/04 15:16:11 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int     copyMap(t_list *map_list, char **map, int longlen)
{
    int i;
    i = 0;

    (*map)[i++] = ' ';
    while (map_list->content[i - 1])
    {
        (*map)[i] = map_list->content[i - 1];
        i++;
    }
    while (i <= longlen)
        (*map)[i++] = ' ';
    (*map)[i++] = ' ';
    (*map)[i] = '\0';
    return (1);
}