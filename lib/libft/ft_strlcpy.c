/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 12:49:03 by aohssine          #+#    #+#             */
/*   Updated: 2024/01/01 16:04:42 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	srcsize;
	size_t	i;

	i = 0;
	srcsize = 0;
	while (src[srcsize++])
		;
	while (*src && i < dstsize - 1 && dstsize)
	{
		*dst++ = (unsigned char)*src++;
		i++;
	}
	if (dstsize)
		*dst = '\0';
	return (--srcsize);
}
