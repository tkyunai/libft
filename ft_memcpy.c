/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkyunai <tkyunai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:39:13 by tkyunai           #+#    #+#             */
/*   Updated: 2020/11/28 12:59:10 by tkyunai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char		*s_dst;
	unsigned const char	*s_src;

	if (dst == src || n == 0)
		return (dst);
	s_dst = (unsigned char *)dst;
	s_src = (unsigned const char *)src;
	while (n--)
		*s_dst++ = *s_src++;
	return (dst);
}
