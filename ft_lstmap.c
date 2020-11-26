/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkyunai <tkyunai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 19:19:48 by tkyunai           #+#    #+#             */
/*   Updated: 2020/11/27 08:11:05 by tkyunai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list *crtlst;
	t_list *addlst;

	if (lst == NULL || f == NULL)
		return (NULL);
	if ((crtlst = ft_lstnew(f(lst->content))) == NULL)
		return (NULL);
	lst = lst->next;
	while (lst != NULL)
	{
		if ((addlst = ft_lstnew(f(lst->content))) == NULL)
		{
			ft_lstclear(&crtlst, del);
			return (NULL);
		}
		ft_lstadd_back(&crtlst, addlst);
		lst = lst->next;
	}
	return (crtlst);
}
