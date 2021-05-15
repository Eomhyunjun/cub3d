/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:56:51 by heom              #+#    #+#             */
/*   Updated: 2021/05/15 15:29:08 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3.h"

int 	parsing_all(t_info *parse_info, t_list *map_list, char ***map)
{
	char	*line;
	int 	fd;
	int 	longlen;
	int 	res;

	fd = open("map.cub", O_RDWR);
	while (get_next_line_arg(fd, &line, &res))
	{
		if ((res = parsing_info(line, parse_info)) == 0)
			return (0); /* duple err */
		if (res == 2)
			break; /* readAll */
		free(line);
	}
	while (1)
	{
		parsing_map(line, &map_list, parse_info);
		if (!(get_next_line_arg(fd, &line, &res)))
		{
			parsing_map(line, &map_list, parse_info);
			break;
		}
	}
	if (!(*map = check_map(map_list, parse_info)))
	{
		ft_lstclear(&map_list, free);
		return (0); /*map err*/
	}
	ft_lstclear(&map_list, free);
	if (res == 0 && *map != NULL)
		return (1);				  /* eof */
	return (0);					  /* get_next_line err */
}