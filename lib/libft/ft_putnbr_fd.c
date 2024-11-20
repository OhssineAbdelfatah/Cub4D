/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:01:53 by aohssine          #+#    #+#             */
/*   Updated: 2023/12/21 14:02:08 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;
	char	s;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	else if (n < 0)
	{
		write(fd, "-", 1);
		n = n * (-1);
	}
	if (n < 10)
	{
		c = n + 48;
		write(fd, &c, 1);
	}
	else
	{
		s = n % 10 + 48;
		ft_putnbr_fd(n / 10, fd);
		write(fd, &s, 1);
	}
}
