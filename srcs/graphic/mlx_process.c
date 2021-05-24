/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_process.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 15:28:48 by heom              #+#    #+#             */
/*   Updated: 2021/05/24 13:59:11 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int		mlx_process(t_info *parse_info, char **map)
{
	t_all	all;

	ft_bzero(&all, sizeof(all));
	all.map = map;
	all_init(&all, parse_info);
	all.map[parse_info->pos[1]][parse_info->pos[0]] = 'x';
	if (!(texture_init(&all, parse_info)))
		return (0);
	mlx_hook(all.win, X_EVENT_KEY_PRESS, 0, &key_press, &all);
	mlx_hook(all.win, X_EVENT_KEY_RELEASE, 0, &key_release, &all);
	mlx_hook(all.win, X_EVENT_KEY_EXIT, (1L << 17), &exit_loop, &all);
	mlx_loop_hook(all.mlx, &main_loop, &all);
	mlx_loop(all.mlx);
	return (1);
}
