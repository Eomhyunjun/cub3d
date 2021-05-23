/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_texnum.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/13 20:55:01 by heom              #+#    #+#             */
/*   Updated: 2021/05/23 17:53:50 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

int		make_texnum(int stepx, int stepy, int side)
{
	int texnum;

	if (side == 0)
		texnum = stepx > 0 ? 0 : 1;
	else
		texnum = stepy > 0 ? 3 : 2;
	return (texnum);
}
