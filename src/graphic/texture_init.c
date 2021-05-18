/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_init.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 16:33:47 by heom              #+#    #+#             */
/*   Updated: 2021/05/16 22:05:05 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int		load_image(t_all *all, int *texture, char *path, t_img *img)
{
	int x;
	int y;

	x = 0;
	y = 0;
	img->img = mlx_xpm_file_to_image(all->mlx, path, &img->img_width, &img->img_height);
	if (img->img == NULL)
	{
		printf("Error\n strange_file_name\n");
		return (0);
	}
	img->data = (int *)mlx_get_data_addr(img->img, &img->bits_per_pixel, &img->line_length, &img->endian);
	while (y < img->img_height)
	{
		while (x < img->img_width)
		{
			texture[img->img_width * y + x] = img->data[img->img_width * y + x];
			x++;
		}
		y++;
		x = 0;
	}
	mlx_destroy_image(all->mlx, img->img);
	return (1);
}

int	 put_texture(t_all *all, t_info *parse_info, t_img	*img)
{
	if(!(load_image(all, all->texture[0], parse_info->ea, img)))
		return (0);
	if(!(load_image(all, all->texture[1], parse_info->we, img)))
		return (0);
	if(!(load_image(all, all->texture[2], parse_info->so, img)))
		return (0);
	if(!(load_image(all, all->texture[3], parse_info->no, img)))
		return (0);
	if(!(load_image(all, all->texture[4], parse_info->s, img)))
		return (0);
	return (1);
}

int		texture_init(t_all *all, t_info *parse_info)
{
	int i;
	int j;
	int res;
	t_img	img;

	i = -1;
	j = -1;
	res = 1;
	while (++i < 5)
	{
		while (++j < texheight * texwidth)
		{
			all->texture[i][j++] = 0;
		}
		i++;
		j = 0;
	}
	i = 0;
	j = 0;
	res = put_texture(all, parse_info, &img);
	all->texture[5][0] = create_trgb(parse_info->f);
	all->texture[6][0] = create_trgb(parse_info->c);
	return (res);
}