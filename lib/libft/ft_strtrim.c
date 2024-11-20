/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:33:03 by aohssine          #+#    #+#             */
/*   Updated: 2024/01/01 13:23:57 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (*(s1 + start) && ft_strchr(set, *(s1 + start)))
		start++;
	if (!(*(s1 + start)))
		return (ft_substr(s1, 0, 0));
	end = ft_strlen(s1) - 1;
	while (*(s1 + end) && ft_strchr(set, *(s1 + end)))
		end--;
	return ((char *)(ft_substr(s1, start, end - start + 1)));
}
