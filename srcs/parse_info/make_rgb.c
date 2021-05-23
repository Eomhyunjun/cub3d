/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:13:24 by heom              #+#    #+#             */
/*   Updated: 2021/05/23 16:18:23 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int		make_rgb(char *line, t_info *parse_info, int start, int i)
{
	char	*bottle;
	char	**trgb;
	int		t;
	int		r;
	int		g;
	int		b;
	int		res;

	bottle = ft_strndup(line, start, i);
	trgb = ft_split(bottle, ',');
	t = 0;
	r = ft_atoi(trgb[0]);
	g = ft_atoi(trgb[1]);
	b = ft_atoi(trgb[2]);
	if (line[0] == 'F' && line[1] == ' ')
		parse_info->f = create_trgb(t, r, g, b);
	else if (line[0] == 'C' && line[1] == ' ')
		parse_info->c = create_trgb(t, r, g, b);
	res = color_len_chk(r, g, b);
	free(bottle);
	split_free(trgb);
	return (res);
}
