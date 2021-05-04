/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putspace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:59:16 by heom              #+#    #+#             */
/*   Updated: 2021/05/04 10:06:32 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

char    *putSpace(char *space, int longlen)
{
    char tmp[longlen + 1];
    int i;
    
    i = 0;
    tmp[longlen] = '\0';
    while(i < longlen)
    {
        tmp[i++] = ' ';
    }
    space = tmp;
    return (space);
}