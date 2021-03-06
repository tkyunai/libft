/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkyunai <tkyunai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 18:49:22 by tkyunai           #+#    #+#             */
/*   Updated: 2020/11/28 13:01:19 by tkyunai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strdup(const char *src)
{
	int		i;
	char	*p;

	i = ft_strlen(src);
	p = malloc(sizeof(char) * (i + 1));
	if (p == NULL)
		return (NULL);
	ft_strlcpy(p, src, i + 1);
	return (p);
}
