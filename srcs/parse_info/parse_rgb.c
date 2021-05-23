/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:25:32 by heom              #+#    #+#             */
/*   Updated: 2021/05/23 19:45:24 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int		parse_rgb(char *line, t_info *parse_info, int start)
{
	int	i;
	int	j;
	int	res;

	i = 0;
	j = 0;
	res = 0;
	while (line[start] == ' ')
		start++;
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
		else
			return (0);
	}
	res = make_rgb(line, parse_info, start, i);
	while (line[i] == ' ')
		i++;
	if (line[i] != '\0')
		return (0);
	return (res);
}
