/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkyunai <tkyunai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 13:28:36 by tkyunai           #+#    #+#             */
/*   Updated: 2020/11/22 15:59:34 by tkyunai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (src == NULL)
		return (0);
	while (src[i] != '\0')
	{
		if (dstsize != 0 && i < ((int)dstsize - 1))
		{
			dst[i] = src[i];
			j = i + 1;
		}
		i++;
	}
	if (0 < dstsize)
		dst[j] = '\0';
	return (i);
}
