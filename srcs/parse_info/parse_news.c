/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_news.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:25:21 by heom              #+#    #+#             */
/*   Updated: 2021/05/23 14:29:14 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int		parse_news(char *line, t_info *parse_info, int start)
{
	int	i;

	i = 0;
	while (line[i])
		i++;
	while (line[start] == ' ')
		start++;
	if (line[0] == 'N' && line[1] == 'O' && line[2] == ' ')
		parse_info->no = ft_strndup(line, start, i);
	else if (line[0] == 'S' && line[1] == 'O' && line[2] == ' ')
		parse_info->so = ft_strndup(line, start, i);
	else if (line[0] == 'W' && line[1] == 'E' && line[2] == ' ')
		parse_info->we = ft_strndup(line, start, i);
	else if (line[0] == 'E' && line[1] == 'A' && line[2] == ' ')
		parse_info->ea = ft_strndup(line, start, i);
	else if (line[0] == 'S' && line[1] == ' ')
		parse_info->s = ft_strndup(line, start, i);
	while (line[i] == ' ')
		i++;
	return (1);
}
