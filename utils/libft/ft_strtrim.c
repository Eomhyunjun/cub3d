/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 01:10:24 by heom              #+#    #+#             */
/*   Updated: 2020/11/30 07:18:25 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int		is_in_set(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	char		*res;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (s1 == 0)
		return (NULL);
	while (s1[i] && is_in_set(s1[i], set))
		i++;
	if ((j = ft_strlen(s1) - 1) != -1)
		while (j >= 0 && is_in_set(s1[j], set))
			j--;
	if (i >= j)
		return (ft_strdup(""));
	if (!(res = (char*)malloc(sizeof(char) * (j - i + 2))))
		return (NULL);
	ft_strlcpy(res, &s1[i], j - i + 2);
	return (res);
}
