/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info_check.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/22 00:22:34 by heom              #+#    #+#             */
/*   Updated: 2021/05/22 00:45:07 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int		info_check(int fd, char **line, t_info *parse_info)
{
	int i;
	int res;

	i = 0;
	res = 0;
	while (get_next_line_arg(fd, line, &res))
	{
		if ((res = parsing_info(*line, parse_info)) == 0)
			return (0); /* duple err */
		if (res == 2)
			break; /* readAll */
		free(*line);
	}
	while (i < 9)
		if (parse_info->dup[i++] != 1)
			return (0);
	return (1);
}