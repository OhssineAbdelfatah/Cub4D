/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 14:48:07 by aohssine          #+#    #+#             */
/*   Updated: 2024/01/03 18:03:56 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_size(int nbr)
{
	size_t	len;

	len = 0;
	if (nbr < 1)
	{
		len++;
		nbr = nbr * -1;
	}
	while (nbr)
	{
		len++;
		nbr = nbr / 10;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	size_t	len;
	char	*nbr;
	size_t	last;

	last = 0;
	len = count_size(n);
	nbr = (char *)malloc((len + 1) * sizeof(char));
	if (!nbr)
		return (NULL);
	nbr[len] = '\0';
	if (n < 0)
	{
		nbr[0] = '-';
		n = n * -1;
		last = 1;
	}
	while (len-- > last)
	{
		if (n < 0)
			nbr[len] = ((n % 10) * (-1) + 48);
		else
			nbr[len] = ((n % 10) + 48);
		n = n / 10;
	}
	return (nbr);
}
