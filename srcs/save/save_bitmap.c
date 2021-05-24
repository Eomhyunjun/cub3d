/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_bitmap.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/24 19:59:58 by heom              #+#    #+#             */
/*   Updated: 2021/05/24 20:26:36 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int		save_bitmap(t_all *all)
{
	if (!(malloc_zbuf(all)))
		return (0);
	calc(all);
	if ((make_bitmap_file(all)))
		print_err("save_err");
	free(all->zbuf);
	exit_loop(all);
	return (0);
}
