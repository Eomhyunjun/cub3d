/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_space.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:59:16 by heom              #+#    #+#             */
/*   Updated: 2021/05/09 16:03:47 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

char 		*put_space(int longlen)
{
	char	*str;
	char	*ptr;

	longlen += 2;
	str = malloc(longlen + 1);
	ptr = str;
	while (longlen--)
		*ptr++ = ' ';
	*ptr = '\0';
	return (str);
}