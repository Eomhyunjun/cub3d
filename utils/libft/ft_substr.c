/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 20:55:36 by heom              #+#    #+#             */
/*   Updated: 2020/11/30 07:14:53 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*c;
	int		i;

	i = 0;
	if (s == 0)
		return (NULL);
	if (!(c = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	if (start >= ft_strlen(s))
		*c = '\0';
	else
	{
		while (len-- && (s[start] != '\0'))
			c[i++] = s[start++];
		c[i] = '\0';
	}
	return (c);
}
