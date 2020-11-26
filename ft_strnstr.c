/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkyunai <tkyunai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 07:43:36 by tkyunai           #+#    #+#             */
/*   Updated: 2020/11/10 07:59:19 by tkyunai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;
	char	*s_haystack;
	char	*s_needle;

	s_haystack = (char *)haystack;
	s_needle = (char *)needle;
	if (s_needle[0] == '\0')
		return (s_haystack);
	i = 0;
	while (s_haystack[i] && i < len)
	{
		j = i;
		while (s_haystack[j] == s_needle[j - i] && s_haystack[j] && j < len)
		{
			j++;
			if (s_needle[j - i] == '\0')
				return (&s_haystack[i]);
		}
		i++;
	}
	return (NULL);
}
