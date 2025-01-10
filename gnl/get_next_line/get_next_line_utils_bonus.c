/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:44:00 by ilaasri           #+#    #+#             */
/*   Updated: 2024/01/18 16:44:02 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (s)
	{
		while (s[i])
		{
			i++;
		}
	}
	return (i);
}

int	find_nl(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

char	*ft_strjoin(char *s1, char *s2, int len)
{
	struct s_my2	my1;

	my1.j = len;
	my1.i = 0;
	my1.x = 0;
	my1.s2len = ft_strlen(s2);
	my1.s1len = ft_strlen(s1);
	if (len > my1.s2len)
		my1.j = my1.s2len;
	my1.res = (char *)malloc(my1.j + my1.s1len + 1);
	if (!my1.res)
		return (free(s1), NULL);
	while (my1.i < my1.s1len)
	{
		my1.res[my1.i] = s1[my1.i];
		my1.i++;
	}
	while (my1.x < my1.j)
	{
		my1.res[my1.i + (my1.x)] = s2[my1.x];
		my1.x++;
	}
	my1.res[my1.x + my1.i] = 0;
	return (free(s1), my1.res);
}

char	*ft_substr(char *s, int start, int len)
{
	char	*res;
	int		i;
	int		sublen;
	int		srclen;

	i = 0;
	srclen = ft_strlen(s);
	sublen = len;
	if (srclen <= start)
		return (free(s), NULL);
	if (srclen <= start + len)
		sublen = srclen - start;
	if (sublen == 0 && srclen != 1)
		return (free(s), NULL);
	res = (char *)malloc((sublen + 1) * (sizeof(char)));
	if (!res)
		return (free(s), NULL);
	while (i < sublen)
	{
		res[i] = s[start + i];
		i++;
	}
	res[i] = '\0';
	return (free(s), res);
}
