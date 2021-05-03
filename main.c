/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:24:29 by heom              #+#    #+#             */
/*   Updated: 2021/05/03 17:06:50 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

int     parsingMap(char *line, t_list **map_list, t_info *parse_info)
{
    if(parse_info->longlen < ft_strlen(line))
        parse_info->longlen = ft_strlen(line);
    ft_lstadd_back(map_list, ft_lstnew(line));
    return (ft_strlen(line));
}

int     get_next_line_arg(int fd, char **line, int *res)
{
    *res = get_next_line(fd, line);
    return (*res);
}


int     copyMap(t_list *map_list, char **map)
{
    int i;
    i = 0;

    (*map)[i++] = ' ';
    while (map_list->content[i - 1])
    {
        (*map)[i] = map_list->content[i - 1];
        i++;
    }
    (*map)[i++] = ' ';
    (*map)[i] = '\0';
    return (1);
}
char    *putSpace(char *space, int longlen)
{
    char tmp[longlen + 1];
    int i;
    
    i = 0;
    tmp[longlen] = '\0';
    while(i < longlen)
    {
        tmp[i++] = ' ';
    }
    space = tmp;
    return (space);
}
char    **makeMatrix(t_list *map_list, char **map, int longlen)
{
    int     lstsize;
    int     i;

    i = 0;
    lstsize = ft_lstsize(map_list) + 2;
    if(!(map = (char **)malloc(sizeof(char *) * lstsize)))
        return (NULL);
    while(map_list)
    {
        if (!(map[i] = (char *)malloc(sizeof(char) * (ft_strlen(map_list->content) + 3))))
            return (0);
        copyMap(map_list, &map[i]);
        map_list = map_list->next;
        i++;
    }
    map[i] = NULL;
    return (map);
}

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