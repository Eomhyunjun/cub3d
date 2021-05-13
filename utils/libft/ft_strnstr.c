/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 14:52:09 by heom              #+#    #+#             */
/*   Updated: 2020/11/30 07:27:34 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*hst;
	const char	*nd;
	size_t		n_size;

	hst = haystack;
	nd = needle;
	if (*needle == '\0')
		return ((char*)haystack);
	n_size = ft_strlen(needle);
	while (*haystack && (len >= n_size))
	{
		if (*haystack == *needle)
		{
			hst = haystack;
			if (!ft_strncmp(haystack, needle, n_size))
				return ((char*)hst);
			else
				needle = nd;
		}
		haystack++;
		len--;
	}
	return (0);
}
