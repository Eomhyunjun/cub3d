/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/16 16:00:49 by heom              #+#    #+#             */
/*   Updated: 2020/11/30 05:52:31 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *dest;
	unsigned char *srcc;

	dest = (unsigned char*)dst;
	srcc = (unsigned char*)src;
	if (dest == src)
		return (dst);
	if (dest < srcc)
	{
		while (len--)
			*dest++ = *srcc++;
	}
	else
	{
		dest += len - 1;
		srcc += len - 1;
		while (len--)
			*dest-- = *srcc--;
	}
	return (dst);
}
