/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_tools_2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:53:40 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/18 21:53:41 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

void	set_ray_direction(t_ray_info *var, double ray_angle)
{
	var->angle = ray_angle;
	if (ray_angle < M_PI)
	{
		var->facing_left = false;
		var->facing_right = true;
	}
	else
	{
		var->facing_left = true;
		var->facing_right = false;
	}
	if (ray_angle < (M_PI / 2) || ray_angle > M_PI + (M_PI / 2))
	{
		var->facing_up = false;
		var->facing_down = true;
	}
	else
	{
		var->facing_up = true;
		var->facing_down = false;
	}
}

void	set_ray_infos(t_ray_info *ray, char which_one, t_x_and_y_d x_y,
		double distance)
{
	ray->distance = distance;
	ray->horzt_or_vert = which_one;
	ray->x_last_intersection = x_y.x;
	ray->y_last_intersection = x_y.y;
	if (which_one == 'h')
	{
		ray->wall_dir = 'S';
		if (ray->facing_up)
			ray->wall_dir = 'N';
	}
	if (which_one == 'v')
	{
		ray->wall_dir = 'W';
		if (ray->facing_right)
			ray->wall_dir = 'E';
	}
}

void	init_cast_ray_s(t_cast_rays *func)
{
	func->distance1 = 0;
	func->distance2 = 0;
	func->v_xy_door.distance = 0;
	func->v_xy_door.x = 0;
	func->v_xy_door.y = 0;
	func->v_xy_door.hit_a_door = false;
	func->h_xy_door.distance = 0;
	func->h_xy_door.x = 0;
	func->h_xy_door.y = 0;
	func->h_xy_door.hit_a_door = false;
}

void	set_doors_infos(t_main_s *var, t_x_and_y_d xy_door, int i, int from)
{
	var->p_infos->rays[i].bonus_rays->door->from = from;
	var->p_infos->rays[i].bonus_rays->door->distance = xy_door.distance;
	var->p_infos->rays[i].bonus_rays->door->x_intersection = xy_door.x;
	var->p_infos->rays[i].bonus_rays->door->y_intersection = xy_door.y;
}

int	is_straight_ray(t_main_s *var, t_cast_rays *func, int i)
{
	if (fabs(var->p_infos->rays[i].angle - M_PI) < EPSILON
		|| fabs(var->p_infos->rays[i].angle) < -EPSILON)
	{
		func->distance1 = cast_horizontally(var, i, &func->h_xy,
				&func->h_xy_door);
		set_ray_infos(&var->p_infos->rays[i], 'h', func->h_xy, func->distance1);
		if (func->h_xy_door.distance)
			var->p_infos->rays[i].bonus_rays->hit_a_door = true;
		set_doors_infos(var, func->h_xy_door, i, 'h');
		return (1);
	}
	if (fabs(var->p_infos->rays[i].angle - M_PI / 2) < EPSILON
		|| fabs(var->p_infos->rays[i].angle - (M_PI + M_PI / 2)) < EPSILON)
	{
		func->distance1 = cast_vertically(var, i, &func->v_xy,
				&func->v_xy_door);
		set_ray_infos(&var->p_infos->rays[i], 'v', func->v_xy, func->distance1);
		if (func->v_xy_door.distance)
			var->p_infos->rays[i].bonus_rays->hit_a_door = true;
		set_doors_infos(var, func->v_xy_door, i, 'v');
		return (1);
	}
	return (0);
}
