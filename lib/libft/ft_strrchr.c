/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 19:30:32 by aohssine          #+#    #+#             */
/*   Updated: 2023/12/13 18:41:46 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;

	if ((char)*s == '\0' && (char)c != '\0')
		return (0);
	i = ft_strlen(s);
	if ((char)c == '\0' && (char)s[i] == '\0')
		return ((char *)&s[i]);
	i = i - 1;
	while ((char)s[i] && i)
	{
		if ((char)s[i] == (char)c)
			return ((char *)(&s[i]));
		i--;
	}
	if (s[0] == (char)c)
		return ((char *)(s));
	return (NULL);
}
