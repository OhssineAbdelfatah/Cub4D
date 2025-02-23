/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors_tools_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:03:07 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/19 22:03:09 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

double	get_distance(t_player_infos *p_var, double x, double y)
{
	double	distance;

	distance = sqrt(pow((p_var->y - x), 2) + pow((p_var->x - y), 2));
	return (distance);
}

void	asign_values_obj(t_main_s *var, t_obj *obj, t_player_infos *p_var,
		t_fill_obj *func)
{
	if (var->map[func->y][func->x] == 'O')
	{
		obj[func->i].visible = false;
		obj[func->i].x = (double)(func->x * SQ_LEN) + (SQ_LEN / 2);
		obj[func->i].y = (double)(func->y * SQ_LEN) + (SQ_LEN / 2);
		obj[func->i].x_screen = 0;
		obj[func->i].y_screen = 0;
		obj[func->i].obj_height = 0;
		obj[func->i].obj_width = 0;
		obj[func->i].obj_teta = 0;
		obj[func->i].vector_teta = 0;
		obj[func->i].vector_x = 0;
		obj[func->i].vector_y = 0;
		obj[func->i].distance = get_distance(p_var, func->x, func->y);
		func->i++;
	}
}

void	fill_obj(t_main_s *var, t_obj *obj, t_player_infos *p_var)
{
	t_fill_obj	func;

	func.x = 0;
	func.y = 0;
	func.i = 0;
	while (var->map[func.y])
	{
		func.x = 0;
		while (var->map[func.y][func.x])
		{
			asign_values_obj(var, obj, p_var, &func);
			func.x++;
		}
		func.y++;
	}
}

void	asign_values_enemy(t_main_s *var, t_enemy *enemy, t_player_infos *p_var,
		t_fill_enemy *func)
{
	if (var->map[func->y][func->x] == 'e')
	{
		enemy[func->i].alive = true;
		enemy[func->i].x = (double)(func->x * SQ_LEN) + (SQ_LEN / 2);
		enemy[func->i].y = (double)(func->y * SQ_LEN) + (SQ_LEN / 2);
		enemy[func->i].x_screen = 0;
		enemy[func->i].y_screen = 0;
		enemy[func->i].enemy_height = 0;
		enemy[func->i].enemy_width = 0;
		enemy[func->i].enemy_teta = 0;
		enemy[func->i].vector_teta = 0;
		enemy[func->i].vector_x = 0;
		enemy[func->i].vector_y = 0;
		enemy[func->i].distance = get_distance(p_var, func->x, func->y);
		func->i++;
	}
}

void	fill_enemy(t_main_s *var, t_enemy *enemy, t_player_infos *p_var)
{
	t_fill_enemy	func;

	func.x = 0;
	func.y = 0;
	func.i = 0;
	while (var->map[func.y])
	{
		func.x = 0;
		while (var->map[func.y][func.x])
		{
			asign_values_enemy(var, enemy, p_var, &func);
			func.x++;
		}
		func.y++;
	}
}
