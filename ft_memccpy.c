/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkyunai <tkyunai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:39:13 by tkyunai           #+#    #+#             */
/*   Updated: 2020/11/15 16:07:20 by tkyunai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*s_dst;
	unsigned const char	*s_src;
	size_t				i;

	s_dst = (unsigned char *)dst;
	s_src = (unsigned const char *)src;
	i = 0;
	while (i < n)
	{
		s_dst[i] = s_src[i];
		if (s_src[i] == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
