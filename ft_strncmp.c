/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkyunai <tkyunai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 08:07:08 by tkyunai           #+#    #+#             */
/*   Updated: 2020/11/15 23:43:16 by tkyunai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned const char *ss1;
	unsigned const char *ss2;

	ss1 = (unsigned const char *)s1;
	ss2 = (unsigned const char *)s2;
	if (n == 0)
		return (0);
	while (n--)
	{
		if (*ss1 != *ss2)
			return (*ss1 - *ss2);
		if (*ss1 == '\0')
			return (0);
		ss1++;
		ss2++;
	}
	return (0);
}
