/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:25:32 by heom              #+#    #+#             */
/*   Updated: 2021/05/24 16:03:26 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

static	int	remove_space(char *line, int c)
{
	while (line[c] == ' ')
		c++;
	return (c);
}

int			parse_rgb(char *line, t_info *parse_info, int start)
{
	int		i;
	int		j;
	int		res;

	i = 0;
	j = 0;
	start = remove_space(line, start);
	i = start;
	while (ft_isdigit(line[i]) || line[i] == ',')
	{
		if (ft_isdigit(line[i]))
			i++;
		else if ((line[i] == ',' && ft_isdigit(line[i + 1]) == 1) && j <= 1)
		{
			i++;
			j++;
		}
	}
	j = i;
	i = remove_space(line, i);
	if (line[i] != '\0')
		return (0);
	res = make_rgb(line, parse_info, start, j);
	return (res);
}
