/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_r.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:25:29 by heom              #+#    #+#             */
/*   Updated: 2021/05/23 16:34:00 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void		remove_space(char **line)
{
	while (**line == ' ')
		(*line)++;
}

int			r_val_chk(char **line, char stop)
{
	while (**line)
	{
		if (ft_isdigit(**line))
			(*line)++;
		else if (**line == stop)
			break ;
		else
			return (0);
	}
	return (1);
}

int			r_ran_chk(int rw, int rh)
{
	int max;

	max = 2147483647;
	if(0 < rw && rw <= max && 0 < rh && rh <= max)
		return (1);
	return (0);
}

int			parse_r(char *line, t_info *parse_info)
{
	char	**bottle;
	char	*start;
	int		res;

	res = 0;
	start = line;
	line += 2;
	remove_space(&line);
	res = r_val_chk(&line, ' ');
	if (*line == '\0' || res == 0)
		return (0);
	remove_space(&line);
	res = r_val_chk(&line, '\0');
	remove_space(&line);
	if (*line != '\0' || res == 0)
		return (0);
	bottle = ft_split(start, ' ');
	parse_info->rw = ft_atoi(bottle[1]);
	parse_info->rh = ft_atoi(bottle[2]);
	res = r_ran_chk(parse_info->rw, parse_info->rh);
	free(bottle);
	return (res);
}
