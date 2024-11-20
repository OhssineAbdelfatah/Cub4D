/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/07 18:43:10 by aohssine          #+#    #+#             */
/*   Updated: 2024/01/03 16:29:05 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	int		i;
	char	*new;
	char	*temp;

	if (!s1)
		return (NULL);
	i = ft_strlen(s1);
	new = (char *)malloc(i * sizeof(char) + 1);
	if (!new)
		return (NULL);
	temp = new;
	while (*s1)
		*temp++ = *s1++;
	*temp = '\0';
	return (new);
}
