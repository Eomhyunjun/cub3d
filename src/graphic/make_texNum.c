/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_texNum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 20:55:01 by heom              #+#    #+#             */
/*   Updated: 2021/05/14 12:29:50 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int		make_texNum(t_all *all, int stepX, int stepY, int side)
{
	int texNum;

	if (side == 0)
		texNum = stepX > 0 ? 0 : 1;
	else
		texNum = stepY > 0 ? 3 : 2;	
	return (texNum);
}