/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkyunai <tkyunai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/22 17:13:03 by tkyunai           #+#    #+#             */
/*   Updated: 2020/11/26 20:02:53 by tkyunai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_lstsize(t_list *lst)
{
	int	rtn;

	if (lst == NULL)
		return (0);
	rtn = 0;
	while (lst != NULL)
	{
		rtn++;
		lst = lst->next;
	}
	return (rtn);
}
