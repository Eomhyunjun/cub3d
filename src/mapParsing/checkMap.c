/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkMap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:09:27 by heom              #+#    #+#             */
/*   Updated: 2021/05/04 13:47:39 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int     mapErrCehck(char **map)
{

    // map_index_print
    // int i;
    // int j;

    // i = 0;
    // j = 0;

    // while (map[i])
    // {
    //     while(map[i][j])
    //     {
    //         printf("map[%d][%d] : %c\n", i,j,map[i][j]);
    //         j++;
    //     }
    //     j = 0;
    //     i++;
    // }
    return (1);
}

char    **checkMap(t_list *map_list, char **map, t_info *parse_info)
{
    int res;
    char *space;
    /* make skin */
 // ft_lstadd_back(&map_list, NULL);
    /*Linkedlist->matrix*/
    map = makeMatrix(map_list, map, parse_info->longlen);
    //mapErrCehck(map);
    return (map);
}