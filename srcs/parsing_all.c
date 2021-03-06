/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_all.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/05 15:56:51 by heom              #+#    #+#             */
/*   Updated: 2021/05/23 20:23:02 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3.h"

int		parsing_all(t_info *parse_info, t_list *map_list \
					, char ***map, char *argv)
{
	char	*line;
	int		fd;
	int		res;

	fd = open(argv, O_RDWR);
	if (!info_check(fd, &line, parse_info))
		return (0);
	while (1)
	{
		parsing_map(line, &map_list, parse_info);
		if (!(get_next_line_arg(fd, &line, &res)))
		{
			parsing_map(line, &map_list, parse_info);
			break ;
		}
	}
	if (!(*map = check_map(map_list, parse_info)))
	{
		ft_lstclear(&map_list, free);
		return (0);
	}
	ft_lstclear(&map_list, free);
	if (res == 0 && *map != NULL)
		return (1);
	return (0);
}
