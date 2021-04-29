/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/25 19:39:24 by heom              #+#    #+#             */
/*   Updated: 2021/03/01 14:23:06 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*bottle;
	int		i;

	i = 0;
	if ((s1 == 0) || (s2 == 0))
		return (0);
	if (!(bottle = (char *)malloc(sizeof(char) *
					(ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (NULL);
	while (*s1)
		bottle[i++] = *s1++;
	while (*s2)
		bottle[i++] = *s2++;
	bottle[i] = '\0';
	return (bottle);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (c == 0)
		return ((char *)s);
	return (0);
}

char	*ft_strdup(const char *s1)
{
	char	*copy;
	char	*res;
	int		i;

	i = 0;
	while (s1[i])
		i++;
	if (!(copy = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	res = copy;
	while (*s1)
		*copy++ = *s1++;
	*copy = '\0';
	return (res);
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (*s++)
		i++;
	return (i);
}
