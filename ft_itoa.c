/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkyunai <tkyunai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/15 18:48:14 by tkyunai           #+#    #+#             */
/*   Updated: 2020/11/22 15:45:52 by tkyunai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_itostr(char **str, int sign, long n, size_t cnt)
{
	int		i;

	i = 0;
	cnt++;
	if (10 <= n)
	{
		i = ft_itostr(str, sign, n / 10, cnt);
		if (i == -1)
			return (-1);
	}
	else
	{
		if (sign == -1)
			cnt++;
		*str = malloc(sizeof(char) * (cnt + 1));
		if (*str == NULL)
			return (-1);
		if (sign == -1)
			(*str)[i++] = '-';
	}
	(*str)[i] = (n % 10) + '0';
	i++;
	if (cnt == 1)
		(*str)[i] = '\0';
	return (i);
}

char			*ft_itoa(int n)
{
	int	sign;
	long	l;
	char	*str;

	l = n;
	sign = 1;
	str = NULL;
	if (l < 0)
	{
		l *= -1;
		sign = -1;
	}
	if (ft_itostr(&str, sign, l, 0) == -1)
		return (NULL);
	else
		return (str);
}
