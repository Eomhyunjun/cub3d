/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:56:51 by heom              #+#    #+#             */
/*   Updated: 2021/05/05 16:05:13 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3.h"

int parsing_all(t_info  *parse_info, t_list  *map_list, char **map)
{
    char    *line;
    int     fd;
    int     longlen;
    int     res;

    fd = open("map.cub", O_RDWR);

    //info_check
    while (get_next_line_arg(fd, &line, &res))
    {
        if ((res = parsing_info(line, parse_info)) == 0)
            return (0); /* duple err */
        if (res == 2)
            break ; /* readAll */
        free(line);
    }
    
    //map_check
    while (1)
    {
        parsing_map(line, &map_list, parse_info);
        if (!(get_next_line_arg(fd, &line, &res)))
        {
            parsing_map(line, &map_list, parse_info);
            break;
        }
    }
    if(!(map = check_map(map_list, map, parse_info)))
        return (0); /*map err*/

    //print remove
    printf(" Rw : %s\n Rh : %s\n NO : %s\n SO : %s\n WE : %s\n EA : %s\n S : %s\n F : %s\n C : %s\n", parse_info->rw, parse_info->rh, parse_info->no, parse_info->so,parse_info->we,parse_info->ea,parse_info->s,parse_info->f,parse_info->c);
    int i = 0;
    printf("====================================================\n");
    while (map[i])
    {
        printf("|%s|\n", map[i]);
        i++;
    }
    printf("====================================================\n");

    //result
    ft_lstclear(&map_list, free);
    if (res == 0 && *map != NULL) //printf 없어야 통과함
        return (1); /* eof */
    return (0); /* get_next_line err */
}