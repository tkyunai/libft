/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkyunai <tkyunai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:39:13 by tkyunai           #+#    #+#             */
/*   Updated: 2020/11/21 20:10:34 by tkyunai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*s_s;

	s_s = (unsigned char *)s;
	while (n--)
	{
		if (*s_s == (unsigned char)c)
			return (s_s);
		s_s++;
	}
	return (NULL);
}
