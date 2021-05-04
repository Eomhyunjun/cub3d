/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putSpace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/04 09:59:16 by heom              #+#    #+#             */
/*   Updated: 2021/05/04 14:15:44 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../cub3.h"

char    *putSpace(int longlen)
{
    char    *str;
    char    *ptr;

    longlen += 2;
    str = malloc(longlen + 1);
    ptr = str;
    while (longlen--)
        *ptr++ = ' ';
    *ptr = '\0';
    return (str);
}