/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/29 19:24:29 by heom              #+#    #+#             */
/*   Updated: 2021/05/16 14:38:28 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3.h"

void	calc_init(t_all *all, t_calc *cal, int x)
{
	cal->camerax = 2 * x / (double)all->width - 1;
	cal->raydirx = all->dirx + all->planex * cal->camerax;
	cal->raydiry = all->diry + all->planey * cal->camerax;
	cal->mapx = (int)all->posx;
	cal->mapy = (int)all->posy;
	cal->deltadistx = (cal->raydiry == 0) ? 0 : ((cal->raydirx == 0) ? 1 : fabs(1 / cal->raydirx));
	cal->deltadisty = (cal->raydirx == 0) ? 0 : ((cal->raydiry == 0) ? 1 : fabs(1 / cal->raydiry));
	cal->hit = 0;
}

void	set_step_side(t_all *all, t_calc *cal)
{
		if (cal->raydirx < 0)
		{
			cal->stepx = -1;
			cal->sidedistx = (all->posx - cal->mapx) * cal->deltadistx;
		}
		else
		{
			cal->stepx = 1;
			cal->sidedistx = (cal->mapx + 1.0 - all->posx) * cal->deltadistx;
		}
		if (cal->raydiry < 0)
		{
			cal->stepy = -1;
			cal->sidedisty = (all->posy - cal->mapy) * cal->deltadisty;
		}
		else
		{
			cal->stepy = 1;
			cal->sidedisty = (cal->mapy + 1.0 - all->posy) * cal->deltadisty;
		}
}

void	set_hit(t_all *all, t_calc *cal)
{
	while (cal->hit == 0)
	{
		if (cal->sidedistx < cal->sidedisty)
		{
			cal->sidedistx += cal->deltadistx;
			cal->mapx += cal->stepx;
			cal->side = 0;
		}
		else
		{
			cal->sidedisty += cal->deltadisty;
			cal->mapy += cal->stepy;
			cal->side = 1;
		}
		if ('x' > all->map[cal->mapy][cal->mapx])
			cal->hit = 1;
	}
}

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
		
		if (cal.side == 0)
			cal.perpwalldist = (cal.mapx - all->posx + (1 - cal.stepx) / 2) / cal.raydirx;
		else
			cal.perpwalldist = (cal.mapy - all->posy + (1 - cal.stepy) / 2) / cal.raydiry;

		int lineheight = (int)(all->height / cal.perpwalldist);
		if (cal.perpwalldist <= 0.01 && cal.perpwalldist >= -0.01)
			lineheight = 0;

		int drawStart = -lineheight / 2 + all->height / 2;
		if(drawStart < 0)
			drawStart = 0;
		int drawend = lineheight / 2 + all->height / 2;
		if(drawend >= all->height)
			drawend = all->height - 1;
			
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

		double step = 1.0 * texheight / lineheight;
		double texPos = (drawStart - all->height / 2 + lineheight / 2) * step;
	
		for (int y = 0; y < all->height / 2; y++)
		{
				all->buf[y][x] = all->texture[5][0];
		}

		for (int y = all->height / 2; y < all->height; y++)
		{
				all->buf[y][x] = all->texture[6][0];
		}

		for (int y = drawStart; y < drawend; y++)
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

int			main(int argc, char **argv)
{
	int		res;
	char	**map;
	t_info	parse_info;
	t_list	*map_list;

	if (argc == 2)
	{
		res = 0;
		ft_bzero(&parse_info, sizeof(t_info));
		parse_info.dup[8] = '\0';
		parse_info.pos[0] = -1;
		map_list = NULL;
		if (!(res = parsing_all(&parse_info, map_list, &map, argv[1])))
		{
			printf("error\n Invalid value in map pile");
			return (0);
		}
		if (res == 0)
			printf("error\n parsing_info duple err\n");
		res = mlx_process(&parse_info, map);
		split_free(map);
	}
	else if (argc == 3)
	{
		//save position
		return (0);
	}
		return (0);
}