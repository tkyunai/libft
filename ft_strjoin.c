/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkyunai <tkyunai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 16:03:02 by tkyunai           #+#    #+#             */
/*   Updated: 2020/11/28 13:01:56 by tkyunai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*rtn;
	size_t	i;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	rtn = malloc(sizeof(char) * ((ft_strlen(s1) + ft_strlen(s2)) + 1));
	if (rtn == NULL)
		return (NULL);
	while (*s1)
	{
		rtn[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		rtn[i] = *s2;
		s2++;
		i++;
	}
	rtn[i] = '\0';
	return (rtn);
}
