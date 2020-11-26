/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkyunai <tkyunai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/14 21:22:24 by tkyunai           #+#    #+#             */
/*   Updated: 2020/11/13 08:12:38 by tkyunai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_s;

	s_s = (char *)s;
	if (*s_s == (char)c)
		return (s_s);
	while (*s_s++)
	{
		if (*s_s == (char)c)
			return (s_s);
	}
	return (NULL);
}
