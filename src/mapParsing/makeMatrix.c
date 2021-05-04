/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   makeMatrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:55:34 by heom              #+#    #+#             */
/*   Updated: 2021/05/04 15:16:10 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

char    **makeMatrix(t_list *map_list, char **map, int longlen)
{
    int     lstsize;
    int     i;

    i = 0;
    lstsize = ft_lstsize(map_list) + 3;
    if(!(map = (char **)malloc(sizeof(char *) * lstsize)))
        return (NULL);
    map[i++] = putSpace(longlen);
    while(map_list)
    {
        if (!(map[i] = (char *)malloc(sizeof(char) * (longlen + 3))))
            return (0);
        copyMap(map_list, &map[i], longlen);
        map_list = map_list->next;
        i++;
    }
    map[i++] = putSpace(longlen);
    map[i] = NULL;
    return (map);
}