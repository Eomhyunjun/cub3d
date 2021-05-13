/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:26:18 by heom              #+#    #+#             */
/*   Updated: 2021/05/04 14:01:22 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int n)
{
	char	*copy;
	char	*res;
	int		len;

	len = ft_strlen(s1);
	if (n < len)
		len = n;
	if (!(copy = malloc(len + 1))))
		return (NULL);
	res = copy;
	while (*s1 && len--)
		*copy++ = *s1++;
	*copy = '\0';
	return (res);
}