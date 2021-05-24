/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_loop.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/16 14:40:41 by heom              #+#    #+#             */
/*   Updated: 2021/05/24 16:09:42 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int		malloc_zbuf(t_all *all)
{
	double *buf;

	if (!(buf = (double *)malloc(sizeof(double) * all->width)))
		return (0);
	buf = ft_memset((void *)buf, 0, all->width);
	all->zbuf = buf;
	return (1);
}

int		exit_loop(t_all *all)
{
	(void)all;
	split_free(all->map);
	mlx_destroy_image(all->mlx, all->img.img);
	exit(0);
	return (0);
}

int		main_loop(t_all *all)
{
	if (!(malloc_zbuf(all)))
		return (0);
	calc(all);
	mlx_put_image_to_window(all->mlx, all->win, all->img.img, 0, 0);
	free(all->zbuf);
	key_update(all);
	return (0);
}
