/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 00:02:27 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/16 00:02:28 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

int	one_of_the_four(double angle)
{
	if (fabs(angle - M_PI) < EPSILON)
		return (UP);
	if (fabs(angle - (M_PI / 2)) < EPSILON)
		return (RIGHT);
	if (fabs(angle - ((M_PI / 2) + M_PI)) < EPSILON)
		return (LEFT);
	if (fabs(angle - (M_PI * 2)) < EPSILON)
		return (DOWN);
	return (NONE);
}

int	is_there_a_wall(double new_y, double new_x, char **map)
{
	int	x;
	int	y;

	x = (int)floor(new_x / (SQ_LEN));
	y = (int)floor(new_y / (SQ_LEN));
	if (map[y][x] == '1' || map[y][x] == 'O')
		return (1);
	return (0);
}

int	direction(double angle)
{
	if (angle > M_PI / 2 && angle < M_PI)
		return (UP_RIGHT);
	if (angle > M_PI && angle < M_PI + (M_PI / 2))
		return (UP_LEFT);
	if (angle > M_PI + (M_PI / 2) && angle < 2 * M_PI)
		return (DOWN_LEFT);
	if (angle > 0 && angle < M_PI / 2)
		return (DOWN_RIGHT);
	return (NONE);
}

int	check_teleportation(t_player_infos *var, char **map)
{
	int	dir;
	int	check;

	check = 0;
	dir = direction(var->rotation_angle);
	if (one_of_the_four(var->rotation_angle))
		return (0);
	if (dir == UP_RIGHT || dir == UP_LEFT)
		check = is_there_a_wall(var->x - floor(var->move_up_down * var->speed),
				var->y, map);
	else if (dir == DOWN_LEFT || dir == DOWN_RIGHT)
		check = is_there_a_wall(var->x + floor(var->move_up_down * var->speed),
				var->y, map);
	return (check);
}
