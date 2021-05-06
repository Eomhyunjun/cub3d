/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:25:32 by heom              #+#    #+#             */
/*   Updated: 2021/05/04 10:06:04 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int    parse_rgb(char *line, t_info *parse_info, int start)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (line[start] == ' ')
        start++;
    i = start;
    while (ft_isdigit(line[i]) || line[i] == ',')
    {
        if (ft_isdigit(line[i]))
            i++;
        else if((line[i] == ',' && ft_isdigit(line[i+1]) == 1) && j <= 1)
        {
            i++;
            j++;
        }
        else 
            return (0); /* ',' num over err or Out of specification  */
    }
    if (line[0] == 'F' && line[1] == ' ')
        parse_info->f = ft_strndup(line, start, i); // need free
    else if (line[0] == 'C' && line[1] == ' ')
        parse_info->c = ft_strndup(line, start, i); // need free
    return (1);
}