/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_utils3.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 16:58:28 by aohssine          #+#    #+#             */
/*   Updated: 2025/02/17 16:58:29 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	find_pos(char **map, t_pos *pos)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (__direction(map[i][j]))
			{
				pos->x_hor = j;
				pos->y_ver = i;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}

char	*find_info_value(int type, t_map_lst *info)
{
	while (info)
	{
		if (info->type == type)
			return (info->value);
		info = info->next;
	}
	return (NULL);
}

char	*fetch_index_splited(char *str)
{
	char	**strs;
	char	*new;

	strs = split2(str);
	new = ft_strdup(strs[1]);
	return (free_split(strs), new);
}
