/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_rgb.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/23 16:13:24 by heom              #+#    #+#             */
/*   Updated: 2021/05/23 19:53:19 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int		make_rgb(char *line, t_info *parse_info, int start, int i)
{
	char	*bottle;
	char	**trgb;
	int		r;
	int		g;
	int		b;

	bottle = ft_strndup(line, start, i);
	trgb = ft_split(bottle, ',');
	r = ft_atoi(trgb[0]);
	g = ft_atoi(trgb[1]);
	b = ft_atoi(trgb[2]);
	if (line[0] == 'F' && line[1] == ' ')
		parse_info->f = create_trgb(0, ft_atoi(trgb[0]), g, b);
	else if (line[0] == 'C' && line[1] == ' ')
		parse_info->c = create_trgb(0, ft_atoi(trgb[0]), g, b);
	if (!(color_len_chk(r, g, b)))
		return (0);
	free(bottle);
	split_free(trgb);
	return (1);
}
