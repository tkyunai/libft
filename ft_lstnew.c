/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkyunai <tkyunai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 16:39:30 by tkyunai           #+#    #+#             */
/*   Updated: 2020/11/25 17:41:54 by tkyunai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *rtn;

	rtn = malloc(sizeof(t_list));
	if (rtn == NULL)
		return (NULL);
	rtn->content = content;
	rtn->next = NULL;
	return (rtn);
}
