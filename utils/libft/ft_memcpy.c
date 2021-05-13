/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 03:45:36 by heom              #+#    #+#             */
/*   Updated: 2020/11/30 06:08:34 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *dest;
	unsigned char *srcc;

	if (dst == src)
		return (dst);
	dest = (unsigned char*)dst;
	srcc = (unsigned char*)src;
	while (n--)
		*dest++ = *srcc++;
	return (dst);
}
