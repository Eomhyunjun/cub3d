/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/24 01:10:08 by heom              #+#    #+#             */
/*   Updated: 2020/11/30 06:28:19 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
