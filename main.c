/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:24:29 by heom              #+#    #+#             */
/*   Updated: 2021/05/04 10:15:23 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

int parsingAll(void)
{
    t_info  parse_info;
    t_list  *map_list;
    char    *line;
    char    **map;
    int     fd;
    int     longlen;
    int     res;

    ft_bzero(&parse_info, sizeof(t_info));
    parse_info.dup[8] = '\0';
    fd = open("map.cub", O_RDWR);

    //info_check
    while (get_next_line_arg(fd, &line, &res))
    {
        if ((res = parsingInfo(line, &parse_info)) == 0)
            return (0); /* duple err */
        if (res == 2)
            break ; /* readAll */
    }
    
    //map_check
    map_list = ft_lstnew("start");
    while (1)
    {
        parsingMap(line, &map_list, &parse_info);
        if (!(get_next_line_arg(fd, &line, &res)))
        {
            parsingMap(line, &map_list, &parse_info);
            break;
        }
    }
    if(!(map = checkMap(map_list, map, &parse_info)))
        return (0); /*map err*/
    //print remove
    printf(" Rw : %s\n Rh : %s\n NO : %s\n SO : %s\n WE : %s\n EA : %s\n S : %s\n F : %s\n C : %s\n", parse_info.rw, parse_info.rh, parse_info.no, parse_info.so,parse_info.we,parse_info.ea,parse_info.s,parse_info.f,parse_info.c);
    int i = 0;
    while (map[i])
    {
        printf("%s\n", map[i]);
        i++;
    }

    //result
    if (res == 0 && map_list != NULL) //printf 없어야 통과함
        return (1); /* eof */
    return (0); /* get_next_line err */
}

int     main(void)
{
    int res;

    res = 0;
    res = parsingAll();

    if (res == 0)           //print remove
        printf("hello duple err");
    return (0);
}