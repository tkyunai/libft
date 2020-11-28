/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkyunai <tkyunai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:15:00 by tkyunai           #+#    #+#             */
/*   Updated: 2020/11/28 13:56:52 by tkyunai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;
	size_t	len;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	len = ft_strlen(s1);
	start = 0;
	while (start < len && ft_strchr(set, s1[start]))
		start++;
	end = len;
	while (start < end && ft_strchr(set, s1[end]))
		end--;
	if (end < start)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start + 1));
}
