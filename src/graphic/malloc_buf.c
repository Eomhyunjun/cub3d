/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_buf.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:46:44 by heom              #+#    #+#             */
/*   Updated: 2021/05/13 17:03:38 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	malloc_buf(t_all *all)
{
	int i;
	int j;

	i = 0;
	all->buf = (int **)malloc(sizeof(int *) * all->height);
	while (i < all->height)
		all->buf[i++] = (int *)malloc(sizeof(int) * all->width);
	i = 0;
	j = 0;
	while (i < all->height)
	{
		while(j < all->width)
			all->buf[i][j++] = 0;
		i++;
	}
}