/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkyunai <tkyunai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 21:22:24 by tkyunai           #+#    #+#             */
/*   Updated: 2020/11/13 08:14:45 by tkyunai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*s_s;
	char	*rtn;

	rtn = NULL;
	s_s = (char *)s;
	if (*s_s == (char)c)
		rtn = s_s;
	while (*s_s++)
	{
		if (*s_s == (char)c)
			rtn = s_s;
	}
	return (rtn);
}
