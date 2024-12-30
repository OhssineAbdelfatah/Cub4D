/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 11:16:34 by aohssine          #+#    #+#             */
/*   Updated: 2024/12/30 02:55:11 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

// int valid_map(char **map)
// {
//     if()

//     else if ()
//     return (0);
// }

// void	valid_map(int x, int y, char **map, int *valid)
// {
// 	(void)x;
// 	(void)y;
// 	(void)map;
// 	(void)valid;
// 	// exit(0);
// 	// if (map[x][y] == '1' || map[x][y] == '\0' || map[x][y]== NULL
// 	// 	|| map[x][y] == 'V' || map[x][y] == 'X')
// 	// 	return (0);
// 	if (map && map[x] && map[x][y] == '1')
// 		return ;
// 	// if( map[x] == NULL || map[x][y] == ' ' || map[x][y] == '\0' )
// 	// 	*valid = 1;
// 	// if(map[x][y] == '0')
// 	// {
// 	// 	if( y + 1  < ft_strslen(map) )
// 	// 		valid_map(x , y + 1, map, valid);
// 	// 	if( y - 1 > 0 )
// 	// 		valid_map(x , y - 1, map, valid);
// 	// 	if( x + 1 < ft_strslen(map) )
// 	// 		valid_map(x + 1, y, map, valid);
// 	// 	if( x - 1 > 0 )
// 	// 		valid_map(x - 1, y, map, valid);
// 	// }
// 	// map[x][y] = '1';
// 	return ;
// }

t_pos first_corner(char **map)
{
	t_pos indx;
	
	indx.y_ver = 0;
	while(map[indx.y_ver])
	{
		indx.x_hor = 0;
		while(map[indx.y_ver][indx.x_hor])
		{
			if(map[indx.y_ver][indx.x_hor] == '0' )
			{
				return indx;
			}
			indx.x_hor++;
		}
		indx.y_ver++;
	}
	return indx;
}

int check_directions_ver(char ** map, t_pos pos)
{
	if(pos.y_ver - 1  > 0 
		&& map[pos.y_ver - 1][pos.x_hor] != '0' 
		&& map[pos.y_ver - 1][pos.x_hor] != '1'
		&& !__direction(map[pos.y_ver - 1 ][pos.x_hor])) // check left indice ( x - 1 )
	{
		printf("-1[%c][[%c]]\n",map[pos.y_ver][pos.x_hor - 1 ], map[pos.y_ver][pos.x_hor]);
		return 1;
	}
	else if (pos.y_ver + 1 < (int)ft_strslen(map) 
		&& map[pos.y_ver+ 1][pos.x_hor] != '0' 
		&& map[pos.y_ver+ 1][pos.x_hor] != '1'
		&& !__direction(map[pos.y_ver + 1][pos.x_hor]) )
		// || (map[pos.x_hor + 1] == '\0')) )// check left indice ( x + 1 )
	{
		printf("[(%d-%d)[%c]][(%d-%d)%c]+1\n" , pos.y_ver, pos.x_hor, map[pos.y_ver][pos.x_hor] , pos.y_ver, pos.x_hor+1,map[pos.y_ver][pos.x_hor + 1 ] );
		return 1;
	}
	else if (pos.y_ver + 1 == (int)ft_strslen(map))
		return 1;
	return 0;
}
int check_directions_hor(char **map ,t_pos pos)
{
	if(pos.x_hor - 1 > 0 
		&& map[pos.y_ver][pos.x_hor - 1 ] != '0' 
		&& map[pos.y_ver][pos.x_hor - 1 ] != '1'
		&& !__direction(map[pos.y_ver][pos.x_hor - 1 ])) // check left indice ( x - 1 )
		{
			printf("-1[%c][[%c]]\n",map[pos.y_ver][pos.x_hor - 1 ], map[pos.y_ver][pos.x_hor]);
			return 1;
		}
	else if (pos.x_hor + 1 < (int)ft_strlen(map[pos.y_ver]) 
		&& map[pos.y_ver][pos.x_hor + 1 ] != '0' 
		&& map[pos.y_ver][pos.x_hor + 1 ] != '1'
		&& !__direction(map[pos.y_ver][pos.x_hor + 1 ]) )
		// || (map[pos.x_hor + 1] == '\0')) )// check left indice ( x + 1 )
		{
			printf("[(%d-%d)[%c]][(%d-%d)%c]+1\n" , pos.y_ver, pos.x_hor, map[pos.y_ver][pos.x_hor] , pos.y_ver, pos.x_hor+1,map[pos.y_ver][pos.x_hor + 1 ] );
			return 1;
		}
	else if (pos.x_hor + 1 == (int)ft_strlen(map[pos.y_ver]))
		return 1;
	return 0;
}

int valid_map(char **map)
{
	t_pos first;
	int one_time;

	one_time = 1 ;	
	first.x_hor= 0;
	first.y_ver= 0;
	first = first_corner(map);
	// now we have start point 
	// loop over the map inside
	
	while(map[first.y_ver])
	{	
		if(one_time)
			one_time = !one_time ;
		else
			first.x_hor= 0;	
		while(map[first.y_ver][first.x_hor])
		{
			if((first.y_ver == 0 || first.x_hor == 0) && map[first.y_ver][first.x_hor ] == '0')
				return 1;
			if( map[first.y_ver][first.x_hor] == '1' || map[first.y_ver][first.x_hor ] == ' ')
				first.x_hor++;
			else
			{
				if(check_directions_hor(map, first))
					return 1;
				else if (check_directions_ver(map, first))
					return 1;
				else
					first.x_hor++;
			}
		}
		first.y_ver++;
	}
	return 0;
}

