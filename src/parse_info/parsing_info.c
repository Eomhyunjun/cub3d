/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:24:55 by heom              #+#    #+#             */
/*   Updated: 2021/05/05 16:07:51 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int     parsing_info(char *line, t_info *parse_info)
{
    int res;

    res = 0;
    if (line[0] == '\0')
        res = 1;
    else if (line[0] == 'R' && line[1] == ' ')
        res = parse_r(line, parse_info);
    else if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
        res = parse_news(line, parse_info, 3);
    else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
        res = parse_news(line, parse_info, 3);
    else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
        res = parse_news(line, parse_info, 3);
    else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
        res = parse_news(line, parse_info, 3);
    else if (line[0] == 'S' && line[1] == ' ')
        res = parse_news(line, parse_info, 2);
    else if (line[0] == 'F' && line[1] == ' ')
        res = parse_rgb(line, parse_info, 2);
    else if (line[0] == 'C' && line[1] == ' ')
        res = parse_rgb(line, parse_info, 2);
    else
        res = 2;
    
    if (res == 1)
        res = dup_check(line, parse_info);
    return (res);
}