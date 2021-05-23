/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/15 16:48:21 by heom              #+#    #+#             */
/*   Updated: 2021/05/15 19:04:49 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

void	rotation(t_all *all, int degree)
{
	double rad;
	double olddirx;
	double oldPlanex;

	rad = (degree * M_PI) / 180;
	olddirx = all->dirx;
	all->dirx = all->dirx * cos(rad) - all->diry * sin(rad);
	all->diry = olddirx * sin(rad) + all->diry * cos(rad);
	oldPlanex = all->planex;
	all->planex = all->planex * cos(rad) - all->planey * sin(rad);
	all->planey = oldPlanex * sin(rad) + all->planey * cos(rad);
}

void	rotation_pro(t_info *parse_info, t_all *all)
{
	char dir;

	dir = all->map[parse_info->pos[1]][parse_info->pos[0]];
	if (dir == 'W')
		return ;
	rotation(all, 90);
	if (dir == 'S')
		return ;
	rotation(all, 90);
	if (dir == 'E')
		return ;
	rotation(all, 90);
	if (dir == 'N')
		return ;
	return ;
}