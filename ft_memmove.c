/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkyunai <tkyunai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:39:13 by tkyunai           #+#    #+#             */
/*   Updated: 2020/11/28 13:09:55 by tkyunai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char		*s_dst;
	unsigned const char	*s_src;

	if (dst == src || len == 0)
		return (dst);
	s_dst = (unsigned char *)dst;
	s_src = (unsigned const char *)src;
	if (s_src < s_dst)
	{
		while (len--)
			*(s_dst + len) = *(s_src + len);
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
