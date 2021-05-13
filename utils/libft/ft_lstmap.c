/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heom <heom@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/03 16:50:31 by heom              #+#    #+#             */
/*   Updated: 2020/12/03 17:35:19 by heom             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*fst;
	t_list	*nxt;
	t_list	*now;

	if (lst == 0 || f == 0)
		return (NULL);
	if ((fst = ft_lstnew(f(lst->content))) == NULL)
		return (NULL);
	now = fst;
	lst = lst->next;
	while (lst)
	{
		if ((nxt = ft_lstnew(f(lst->content))) == NULL)
		{
			ft_lstclear(&fst, del);
			return (NULL);
		}
		now->next = nxt;
		now = nxt;
		lst = lst->next;
	}
	return (fst);
}
