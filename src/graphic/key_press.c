/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 20:15:57 by heom              #+#    #+#             */
/*   Updated: 2021/05/14 16:15:44 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int		key_press(int key, t_all *all)
{
	if (key == K_ESC)
		exit(0);
	if (key == K_W)
		all->k_w = 1;
	if (key == K_S)
		all->k_s = 1;
	if (key == K_A)
		all->k_a = 1;
	if (key == K_D)
		all->k_d = 1;
	if (key == K_LF)
		all->k_lf = 1;
	if (key == K_RT)
		all->k_rt = 1;
	return (0);
}

int		key_release(int key, t_all *all)
{
	if (key == K_ESC)
		exit(0);
	if (key == K_W)
		all->k_w = 0;
	if (key == K_S)
		all->k_s = 0;
	if (key == K_A)
		all->k_a = 0;
	if (key == K_D)
		all->k_d = 0;
	if (key == K_LF)
		all->k_lf = 0;
	if (key == K_RT)
		all->k_rt = 0;
	return (0);
}