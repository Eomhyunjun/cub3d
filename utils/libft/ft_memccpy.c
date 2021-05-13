/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 15:25:22 by heom              #+#    #+#             */
/*   Updated: 2020/11/26 21:36:58 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char *dest;
	unsigned char *srcc;

	dest = (unsigned char *)dst;
	srcc = (unsigned char *)src;
	while (n > 0)
	{
		*dest = *srcc;
		if (*srcc == (unsigned char)c)
			return (++dest);
		srcc++;
		dest++;
		n--;
	}
	return (NULL);
}
