/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkyunai <tkyunai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 08:47:07 by tkyunai           #+#    #+#             */
/*   Updated: 2020/11/26 17:56:09 by tkyunai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int				i;
	int				sign;
	unsigned long	rtn;

	i = 0;
	sign = 1;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' ||
			str[i] == '\r' || str[i] == '\f' || str[i] == ' ')
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	rtn = 0;
	while ('0' <= str[i] && str[i] <= '9')
	{
		rtn = rtn * 10 + (str[i] - '0');
		i++;
	}
	if (sign == 1 && LONG_MAX < rtn)
		return (-1);
	else if (sign == -1 && LONG_MAX < rtn - 1)
		return (0);
	else
		return ((int)rtn * sign);
}
