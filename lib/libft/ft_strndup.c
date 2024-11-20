/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 01:39:57 by aohssine          #+#    #+#             */
/*   Updated: 2024/11/10 23:12:50 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strndup(const char *s1, size_t size)
{
	int		i;
	char	*new;

	i = ft_strlen(s1);
	if (size > (size_t)i)
		return (NULL);
	new = (char *)malloc(size * sizeof(char) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (*s1 && (size_t)i < size)
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

char	*ft_strnmdup(const char *s1, size_t n, size_t m)
{
	int		i;
	char	*new;

	i = ft_strlen(s1);
	if (n > (size_t)i || m > (size_t)i)
		return (NULL);
	new = (char *)malloc((m - n) * sizeof(char) + 1);
	if (!new)
		return (NULL);
	i = 0;
	while (*s1 && (size_t)i + n <= m)
	{
		new[i] = s1[i + n];
		i++;
	}
	new[i] = '\0';
	return (new);
}
