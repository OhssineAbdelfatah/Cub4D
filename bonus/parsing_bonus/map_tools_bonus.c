/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:43:08 by aohssine          #+#    #+#             */
/*   Updated: 2025/02/21 00:16:23 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing_bonus.h"

int	bonus_obj(char c)
{
	return (c == 'e' || c == 'O' || c == 'D');
}

int	valid_door(char **map, t_pos p)
{
	if (p.x_hor + 1 > (int)ft_strlen(map[p.y_ver])
		|| p.x_hor - 1 < 0
		|| p.y_ver + 1 > ft_strslen(map)
		|| p.y_ver - 1 < 0)
		return (1);
	if (map[p.y_ver][p.x_hor - 1] != map[p.y_ver][p.x_hor + 1]
		&& (map[p.y_ver][p.x_hor + 1] != '0'
		|| map[p.y_ver][p.x_hor + 1] != '1'))
		return (1);
	if (map[p.y_ver + 1][p.x_hor] != map[p.y_ver - 1][p.x_hor]
		&& (map[p.y_ver - 1][p.x_hor] != '0'
		|| map[p.y_ver - 1][p.x_hor] != '1'))
		return (1);
	return (0);
}
