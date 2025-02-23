/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rays.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 16:21:34 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/16 16:21:36 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	cast_ray(t_main_s *var, int i)
{
	t_cast_rays	func;

	init_cast_ray_s(&func);
	if (is_straight_ray(var, &func, i))
		return ;
	func.distance1 = cast_horizontally(var, i, &func.h_xy);
	func.distance2 = cast_vertically(var, i, &func.v_xy);
	if (func.distance1 < func.distance2 || func.distance1 == func.distance2)
		set_ray_infos(&var->p_infos->rays[i], 'h', func.h_xy, func.distance1);
	else if (func.distance1 > func.distance2)
		set_ray_infos(&var->p_infos->rays[i], 'v', func.v_xy, func.distance2);
}

void	shoot_the_rays(t_main_s *var)
{
	t_shoot_rays	func;

	func.i = 0;
	var->p_infos->nbr_rays = var->window_width;
	func.fov = (M_PI / 180) * 60;
	func.ray_angle_increment = func.fov / var->p_infos->nbr_rays;
	var->p_infos->nbr_rays = var->p_infos->nbr_rays;
	func.angle_to_start = var->p_infos->rotation_angle - (func.fov / 2);
	func.ray_angle = func.angle_to_start;
	func.ray_angle = adjust_angle(func.ray_angle);
	var->p_infos->rays = init_rays(var, func.ray_angle,
			func.ray_angle_increment);
	while (func.i < var->p_infos->nbr_rays)
	{
		set_ray_direction(&var->p_infos->rays[func.i], func.ray_angle);
		cast_ray(var, func.i);
		func.ray_angle += func.ray_angle_increment;
		func.ray_angle = adjust_angle(func.ray_angle);
		func.i++;
	}
}
