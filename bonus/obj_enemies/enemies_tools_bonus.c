/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_tools_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:56:50 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/19 23:56:52 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

int	get_color_enemy(t_main_s *var, t_render_enemy *func, int enemy_height,
		int enemy_width)
{
	double	x_offset;
	double	y_offset;
	int		color;
	int		new_x;
	int		new_y;

	x_offset = (double)func->x_increment / (double)enemy_width;
	y_offset = (double)func->y_increment / (double)enemy_height;
	if (var->p_infos->p_bonus->enemy[func->i].alive)
	{
		new_x = (double)var->bonus->enemy_text->width * x_offset;
		new_y = (double)var->bonus->enemy_text->hieght * y_offset;
		color = var->bonus->enemy_text->pixels[new_y][new_x];
	}
	else
	{
		new_x = (double)var->bonus->dead_enemy_text->width * x_offset;
		new_y = (double)var->bonus->dead_enemy_text->hieght * y_offset;
		color = var->bonus->dead_enemy_text->pixels[new_y][new_x];
	}
	return (color);
}

bool	check_for_doors(t_main_s *var, t_player_bonus *ptr, int i,
		int ray_to_inspect)
{
	double	door_dis;
	double	enemy_dis;

	door_dis = var->p_infos->rays[ray_to_inspect].bonus_rays->door->distance;
	enemy_dis = ptr->enemy[i].distance;
	if (var->p_infos->rays[ray_to_inspect].bonus_rays->hit_a_door
		&& door_dis < enemy_dis)
		return (false);
	return (true);
}

int	check_for_walls(t_main_s *var, t_player_infos *p_player, t_enemy *enemy,
		int i)
{
	double	new_v_x;
	double	new_v_y;
	double	new_e_x;
	double	new_e_y;

	if (enemy[i].vector_x > 0)
		new_v_x = enemy[i].vector_x - (p_player->speed / 2);
	else
		new_v_x = enemy[i].vector_x + (p_player->speed / 2);
	new_e_x = p_player->y - new_v_x;
	if (enemy[i].vector_y > 0)
		new_v_y = enemy[i].vector_y - (p_player->speed / 2);
	else
		new_v_y = enemy[i].vector_y + (p_player->speed / 2);
	new_e_y = p_player->x - new_v_y;
	if (hit_a_wall(var, new_e_y, new_e_x, 0))
		return (1);
	if (hit_a_door(var, new_e_y, new_e_x, 0))
		return (1);
	return (0);
}

void	damage_player(t_player_infos *player, t_enemy *enemy, int i)
{
	static int	time_to_damage;
	int			diff_x;
	int			diff_y;

	diff_y = abs((int)floor(enemy[i].vector_y));
	diff_x = abs((int)floor(enemy[i].vector_x));
	if (diff_x <= SQ_LEN && diff_y <= SQ_LEN && time_to_damage > 10)
	{
		time_to_damage = 0;
		player->health -= 10;
	}
	time_to_damage++;
}

void	chase_player(t_main_s *var, t_player_infos *p_player, t_enemy *enemy,
		int i)
{
	int	diff_x;
	int	diff_y;

	diff_y = abs((int)floor(enemy[i].vector_y));
	diff_x = abs((int)floor(enemy[i].vector_x));
	damage_player(p_player, enemy, i);
	if (check_for_walls(var, p_player, enemy, i))
		return ;
	if (diff_x > SQ_LEN)
	{
		if (enemy[i].vector_x > 0)
			enemy[i].vector_x -= (p_player->speed / 2);
		else
			enemy[i].vector_x += (p_player->speed / 2);
		enemy[i].x = p_player->y - enemy[i].vector_x;
	}
	if (diff_y > SQ_LEN)
	{
		if (enemy[i].vector_y > 0)
			enemy[i].vector_y -= (p_player->speed / 2);
		else
			enemy[i].vector_y += (p_player->speed / 2);
		enemy[i].y = p_player->x - enemy[i].vector_y;
	}
	enemy[i].distance = get_distance(p_player, enemy[i].x, enemy[i].y);
}
