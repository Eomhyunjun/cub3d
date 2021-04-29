/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:25:29 by heom              #+#    #+#             */
/*   Updated: 2021/04/29 19:25:30 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3.h"

int     parse_r(char *line, t_info *parse_info)
{
    char    **bottle;
    char    *start;
    
    start = line;
    line += 2;
    while (*line == ' ')
        line++;
    
    if (!ft_isdigit(*line))
        return (0); //parsing err

    while (*line)
    {
        if (ft_isdigit(*line))
            line++;
        else if (*line == ' ')
            break ;
        else
            return (0); //parsing err
    }
    while (*line == ' ')
        line++;
    while (*line)
    {
        if (ft_isdigit(*line))
            line++;
        else if (*line == '\0')
            break;
        else
            return (0); //parsing err
    }

    bottle = ft_split(start, ' '); // need free
    parse_info->rw = bottle[1];
    parse_info->rh = bottle[2];
    return (1);
}