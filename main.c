/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:24:29 by heom              #+#    #+#             */
/*   Updated: 2021/04/29 22:40:21 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

int parsingMap(char *line, t_list **map_list)
{
    ft_lstadd_back(map_list, ft_lstnew(line));
    return (1);
}

int get_next_line_arg(int fd, char **line, int *res)
{
    *res = get_next_line(fd, line);
    return (*res);
}

int parsingAll(void)
{
    t_info  parse_info;
    t_list  *map_list;
    char    *line;
    int     fd;
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
    while (get_next_line_arg(fd, &line, &res))
    {
        if (!(parsingMap(line, &map_list)))
            return (0); /* parsing err */
    }

    //print remove
    printf(" Rw : %s\n Rh : %s\n NO : %s\n SO : %s\n WE : %s\n EA : %s\n S : %s\n F : %s\n C : %s\n", parse_info.rw, parse_info.rh, parse_info.no, parse_info.so,parse_info.we,parse_info.ea,parse_info.s,parse_info.f,parse_info.c);
    while (map_list != NULL)
    {
        printf("map : %s\n", map_list->content);
        map_list = map_list->next;
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