/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 00:16:14 by aohssine          #+#    #+#             */
/*   Updated: 2024/11/10 23:12:24 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	s2len;

	i = 0;
	if (!s1 || !s2)
		return (0);
	else
	{
		s2len = ft_strlen(s2);
		while (i < s2len)
		{
			if (s1[i] != s2[i])
				return (0);
			i++;
		}
		if ((size_t)s2len != ft_strlen(s1))
			return (0);
	}
	return (1);
}
