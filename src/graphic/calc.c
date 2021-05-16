/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 16:21:42 by heom              #+#    #+#             */
/*   Updated: 2021/05/16 21:38:18 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	calc(t_all *all)
{
	int x;
	t_calc cal;

	x = 0;
	//printf("width : %d height : %d\nposx : %f, posy : %f \n dirx : %f, diry : %f\nplanex : %f, planey : %f\n\n", all->width, all->height, all->posx, all->posy, all->dirx, all->diry, all->planex, all->planey);
	while (x < all->width)
	{
		calc_init(all, &cal, x);
		set_step_side(all, &cal);
		set_hit(all, &cal);
		set_draw_point(all, &cal);
		cal.texnum = make_texnum(all, cal.stepx, cal.stepy, cal.side);

		double wallx;
		if (cal.side == 0)
			wallx = all->posy + cal.perpwalldist * cal.raydiry;
		else
			wallx = all->posx + cal.perpwalldist * cal.raydirx;
		wallx -= floor(wallx);

		int tex = (int)(wallx * (double)texwidth);
		if (cal.side == 0 && cal.raydirx > 0)
			tex = texwidth - tex - 1;
		if (cal.side == 1 && cal.raydiry < 0)
			tex = texwidth - tex - 1;

		double step = 1.0 * texheight / cal.lineheight;
		double texPos = (cal.drawstart - all->height / 2 + cal.lineheight / 2) * step;
	
		for (int y = 0; y < all->height / 2; y++)
		{
				all->buf[y][x] = all->texture[5][0];
		}

		for (int y = all->height / 2; y < all->height; y++)
		{
				all->buf[y][x] = all->texture[6][0];
		}

		for (int y = cal.drawstart; y < cal.drawend; y++)
		{
			int texy = (int)texPos & (texheight - 1);
			texPos += step;
			int color = all->texture[cal.texnum][texheight * texy + tex];
			if (cal.side == 1)
				color = (color >> 1) & 8355711;
			all->buf[y][x] = color;
		}
		x++;
	}

	//printf("width : %d height : %d\nposx : %f, posy : %f \n dirx : %f, diry : %f\nplanex : %f, planey : %f\n\n", all->width, all->height, all->posx, all->posy, all->dirx, all->diry, all->planex, all->planey);
}