/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkyunai <tkyunai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/18 08:47:07 by tkyunai           #+#    #+#             */
/*   Updated: 2020/12/02 20:14:11 by tkyunai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			ft_atoi(const char *str)
{
	int				i;
	int				sign;
	long long		rtn;

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
	while (ft_isdigit(str[i]))
	{
		if (rtn > (rtn * 10 + str[i] - '0') / 10)
			return (sign == -1 ? (0) : (-1));
		rtn = rtn * 10 + str[i] - '0';
		i++;
	}
	return ((int)rtn * sign);
}
