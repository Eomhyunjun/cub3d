/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:14:32 by heom              #+#    #+#             */
/*   Updated: 2021/05/05 16:02:38 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int     parsing_map(char *line, t_list **map_list, t_info *parse_info)
{
    int     len;

    len = ft_strlen(line);
    if(parse_info->longlen < len)
        parse_info->longlen = len;
    ft_lstadd_back(map_list, ft_lstnew(line));
    return (len);
}