/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/30 19:37:20 by heom              #+#    #+#             */
/*   Updated: 2021/03/30 20:23:42 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int		create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int		get_t(int trgb)
{
	return (trgb & (0xff << 24));
}

int		get_r(int trgb)
{
	return (trgb & (0xff << 16));
}

int		get_g(int trgb)
{
	return (trgb & (0xff << 8));
}
int		get_b(int trgb)
{
	return (trgb & 0xff);
}
