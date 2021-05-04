/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingMap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 10:14:32 by heom              #+#    #+#             */
/*   Updated: 2021/05/04 10:14:46 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int     parsingMap(char *line, t_list **map_list, t_info *parse_info)
{
    if(parse_info->longlen < ft_strlen(line))
        parse_info->longlen = ft_strlen(line);
    ft_lstadd_back(map_list, ft_lstnew(line));
    return (ft_strlen(line));
}