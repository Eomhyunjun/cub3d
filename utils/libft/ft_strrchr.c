/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 14:57:22 by heom              #+#    #+#             */
/*   Updated: 2020/11/25 15:47:12 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *p;

	p = s;
	while (*p)
		p++;
	while (p != s)
	{
		if (*p == (char)c)
			return ((char*)p);
		p--;
	}
	if (*s == (char)c)
		return ((char*)s);
	return (NULL);
}
