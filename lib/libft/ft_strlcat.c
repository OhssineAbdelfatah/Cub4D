/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 14:59:55 by aohssine          #+#    #+#             */
/*   Updated: 2024/01/03 16:34:34 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	d_len;
	size_t	s_len;
	size_t	x;
	size_t	y;

	if (!dest && !dstsize)
		return (ft_strlen(src));
	d_len = ft_strlen(dest);
	s_len = ft_strlen(src);
	x = 0;
	y = d_len;
	if (d_len >= dstsize)
		return (dstsize + s_len);
	while (src[x] && (x < dstsize - d_len - 1))
	{
		dest[y] = src[x];
		x++;
		y++;
	}
	dest[y] = '\0';
	return (d_len + s_len);
}
