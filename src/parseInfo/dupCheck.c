/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dupCheck.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:26:53 by heom              #+#    #+#             */
/*   Updated: 2021/05/04 10:05:53 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int dupCheck(char *line, t_info *parse_info)
{
    int res;

    res = 1;
    if (line[0] == 'R' && parse_info->dup[0] == 0)
        parse_info->dup[0] = 1;
    else if (line[0] == 'N' && parse_info->dup[1] == 0)
        parse_info->dup[1] = 1;
    else if (line[0] == 'S' && line[1] == 'O' && parse_info->dup[2] == 0)
        parse_info->dup[2] = 1;
    else if (line[0] == 'W' && parse_info->dup[3] == 0)
        parse_info->dup[3] = 1;
    else if (line[0] == 'E' && parse_info->dup[4] == 0)
        parse_info->dup[4] = 1;
    else if (line[0] == 'S' && parse_info->dup[5] == 0)
        parse_info->dup[5] = 1;
    else if (line[0] == 'F' && parse_info->dup[6] == 0)
        parse_info->dup[6] = 1;
    else if (line[0] == 'C' && parse_info->dup[7] == 0)
        parse_info->dup[7] = 1;
    else
        res = 0;    
    if (line[0] == '\0')
        res = 1;
    return (res);
}