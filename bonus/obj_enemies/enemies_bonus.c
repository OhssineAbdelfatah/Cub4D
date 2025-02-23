/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:57:04 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/19 23:57:06 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

void	init_render_enemy(t_player_bonus *ptr, t_walls *walls,
		t_render_enemy *func, int i)
{
	func->i = i;
	func->x_increment = 0;
	func->y_increment = 0;
	ptr->enemy[i].enemy_height = (SQ_LEN / ptr->enemy[i].distance)
		* walls->distance_prj_plane;
	ptr->enemy[i].enemy_width = ptr->enemy[i].enemy_height;
	func->x_start = ptr->enemy[i].x_screen - (ptr->enemy[i].enemy_width / 2);
	func->y_start = ptr->enemy[i].y_screen - (ptr->enemy[i].enemy_height / 2);
	func->y_end = func->y_start + ptr->enemy[i].enemy_height;
	func->x_end = func->x_start + ptr->enemy[i].enemy_width;
}

void	time_to_draw_enemy(t_main_s *var, t_player_bonus *ptr,
		t_render_enemy *func)
{
	int	i;
	int	ray_nbr;

	i = func->i;
	ray_nbr = func->ray_to_inspect;
	func->x_increment = 0;
	while (func->x_start + func->x_increment < func->x_end)
	{
		ray_nbr = var->p_infos->nbr_rays - 1 - (func->x_increment
				+ func->x_start);
		func->color = get_color_enemy(var, func, ptr->enemy[i].enemy_height,
				ptr->enemy[i].enemy_width);
		if (ray_nbr >= 0 && ray_nbr < 1400
			&& var->p_infos->rays[ray_nbr].distance > ptr->enemy[i].distance
			&& check_for_doors(var, ptr, i, ray_nbr))
		{
			if (func->x_start + func->x_increment >= 0 && func->x_start
				+ func->x_increment < var->window_width && func->color)
				mlx_put_pixel(var->img2, func->x_start + func->x_increment,
					func->y_start, func->color);
		}
		func->x_increment++;
	}
}

void	render_enemy(t_main_s *var, t_player_bonus *ptr, t_walls *walls, int i)
{
	t_render_enemy	func;

	init_render_enemy(ptr, walls, &func, i);
	while (func.y_start < func.y_end)
	{
		if (func.y_start >= 0 && func.y_start < var->window_height)
			time_to_draw_enemy(var, ptr, &func);
		func.y_increment++;
		func.y_start++;
	}
}

void	render_enemies(t_main_s *var, t_player_bonus *p_ptr)
{
	t_walls	*walls;
	int		i;

	walls = init_walls(var);
	i = 0;
	while (i < var->bonus->nbr_enemies)
	{
		render_enemy(var, p_ptr, walls, i);
		i++;
	}
	free(walls);
}

void	update_enemy_data(t_main_s *var, t_player_infos *p_var, t_enemy *enemy,
		int nbr_enemy)
{
	int	i;

	i = 0;
	if (enemy)
	{
		while (i < nbr_enemy)
		{
			enemy[i].distance = get_distance(p_var, enemy[i].x, enemy[i].y);
			enemy[i].vector_x = p_var->y - enemy[i].x;
			enemy[i].vector_y = p_var->x - enemy[i].y;
			if (enemy[i].alive)
				chase_player(var, p_var, enemy, i);
			enemy[i].vector_teta = atan2(-enemy[i].vector_y, enemy[i].vector_x);
			enemy[i].vector_teta = adjust_angle(enemy[i].vector_teta - (M_PI
						/ 2));
			enemy[i].enemy_teta = calculate_obj_or_enemy_teta(p_var, NULL,
					&enemy[i]);
			enemy[i].x_screen = enemy[i].enemy_teta * (1400 / p_var->fov);
			enemy[i].y_screen = (var->window_height / 2)
				+ var->p_infos->up_down_offset;
			i++;
		}
		adjust_rank_enemies(enemy, nbr_enemy);
	}
}
