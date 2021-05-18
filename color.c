/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:37:20 by heom              #+#    #+#             */
/*   Updated: 2021/05/17 15:45:54 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

int		create_trgb(char *trgb)
{
	char	**bottle;
	int		t;
	int		r;
	int		g;
	int		b;

	bottle = ft_split(trgb, ',');
	t = 0;
	r = ft_atoi(bottle[0]);
	g = ft_atoi(bottle[1]);
	b = ft_atoi(bottle[2]);
	split_free(bottle);
	return (t << 24 | r << 16 | g << 8 | b);
}
