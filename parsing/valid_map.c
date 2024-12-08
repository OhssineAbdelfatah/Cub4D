/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:16:34 by aohssine          #+#    #+#             */
/*   Updated: 2024/12/07 18:27:28 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */



#include"../includes/parsing.h"

// int valid_map(char **map)
// {
//     if()

//     else if ()
//     return 0;
// }

void	valid_map(__unused int x ,__unused int y ,__unused char **map ,__unused int *valid)
{
	// exit(0);
	// if (map[x][y] == '1' || map[x][y] == '\0' || map[x][y]== NULL
	// 	|| map[x][y] == 'V' || map[x][y] == 'X')
	// 	return (0);
	if(map && map[x] && map[x][y] == '1')
		return ;
	// if( map[x] == NULL || map[x][y] == ' ' || map[x][y] == '\0' )
	// 	*valid = 1;
	// if(map[x][y] == '0')
	// {
	// 	if( y + 1  < ft_strslen(map) )
	// 		valid_map(x , y + 1, map, valid);
	// 	if( y - 1 > 0 )
	// 		valid_map(x , y - 1, map, valid);
	// 	if( x + 1 < ft_strslen(map) )
	// 		valid_map(x + 1, y, map, valid);
	// 	if( x - 1 > 0 )
	// 		valid_map(x - 1, y, map, valid);
	// }
	// map[x][y] = '1';
	return ;
}