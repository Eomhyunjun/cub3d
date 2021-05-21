/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/17 15:26:18 by heom              #+#    #+#             */
/*   Updated: 2021/05/21 21:58:06 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, int a, int b)
{
	char	*copy;
	char	*res;
	int		i;

	i = 0;
	if (!(copy = (char *)malloc(sizeof(char) * (b - a + 2))))
		return (NULL);
	res = copy;
	while (a <= b)
		copy[i++] = s1[a++];
	copy[i] = '\0';
	return (res);
}
