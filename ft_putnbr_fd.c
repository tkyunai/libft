/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkyunai <tkyunai@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/21 20:00:35 by tkyunai           #+#    #+#             */
/*   Updated: 2020/11/26 19:51:44 by tkyunai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_wrtnbr(long n, int fd)
{
	char	c;

	if (n < 0)
	{
		write(fd, "-", 1);
		n *= -1;
	}
	if (10 <= n)
		ft_wrtnbr(n / 10, fd);
	c = (n % 10) + '0';
	write(fd, &c, 1);
}

void		ft_putnbr_fd(int n, int fd)
{
	ft_wrtnbr((long)n, fd);
}
