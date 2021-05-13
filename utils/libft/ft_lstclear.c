/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/02 22:14:23 by heom              #+#    #+#             */
/*   Updated: 2020/12/03 17:21:51 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *now;
	t_list *nxt;

	if (lst == 0 || del == 0)
		return ;
	now = *lst;
	while (now)
	{
		nxt = now->next;
		ft_lstdelone(now, del);
		now = nxt;
	}
	*lst = 0;
}
