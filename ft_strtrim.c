/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkyunai <tkyunai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 17:15:00 by tkyunai           #+#    #+#             */
/*   Updated: 2020/11/22 16:26:49 by tkyunai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isset(char c, char *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

static int	calc_start_end(char const *s1, char const *set, int start, int end)
{
	if (end == 0)
	{
		while (s1[start])
		{
			if (!(ft_isset(s1[start], (char*)set)))
				break ;
			start++;
		}
		return (start);
	}
	else
	{
		while (start < end)
		{
			if (!(ft_isset(s1[end], (char *)set)))
				break ;
			end--;
		}
		return (end);
	}
}

char		*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	start = calc_start_end(s1, set, 0, 0);
	end = calc_start_end(s1, set, start, ft_strlen(s1) - 1);
	if (end < start)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start + 1));
}
