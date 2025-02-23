/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 00:51:06 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/16 00:51:08 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

int	get_color_obj(t_main_s *var, t_render_obj func)
{
	int		color;
	double	x_offset;
	double	y_offset;
	int		new_x;
	int		new_y;

	x_offset = (double)func.x_increment / (double)func.obj_width;
	y_offset = (double)func.y_increment / (double)func.obj_height;
	new_x = (double)var->bonus->obj_img->width * x_offset;
	new_y = (double)var->bonus->obj_img->hieght * y_offset;
	color = var->bonus->obj_img->pixels[(int)floor(new_y)][(int)floor(new_x)];
	return (color);
}

void	init_render_obj(t_player_bonus *ptr, t_walls *walls, t_render_obj *func,
		int i)
{
	func->x_increment = 0;
	func->y_increment = 0;
	func->obj_height = (SQ_LEN / ptr->obj[i].distance)
		* walls->distance_prj_plane;
	func->obj_width = func->obj_height;
	func->x_start = ptr->obj[i].x_screen - (func->obj_width / 2);
	func->y_start = ptr->obj[i].y_screen - (func->obj_height / 2);
	func->y_end = func->y_start + func->obj_height;
	func->x_end = func->x_start + func->obj_width;
	func->i = i;
}

void	sec_while(t_main_s *var, t_player_bonus *ptr, t_render_obj *func)
{
	double	obj_dis;

	while (func->x_start + func->x_increment < func->x_end)
	{
		func->ray_to_inspect = var->p_infos->nbr_rays - 1 - (func->x_increment
				+ func->x_start);
		func->color = get_color_obj(var, *func);
		obj_dis = ptr->obj[func->i].distance;
		if (func->ray_to_inspect >= 0
			&& func->ray_to_inspect < var->p_infos->nbr_rays
			&& var->p_infos->rays[func->ray_to_inspect].distance > obj_dis
			&& check_doors_for_obj_rendering(var, ptr, func->i,
				func->ray_to_inspect))
		{
			if (func->x_start + func->x_increment >= 0 && func->x_start
				+ func->x_increment < var->window_width && func->color)
				mlx_put_pixel(var->img2, func->x_start + func->x_increment,
					func->y_start, func->color);
		}
		func->x_increment++;
	}
}

void	render_obj(t_main_s *var, t_player_bonus *ptr, t_walls *walls, int i)
{
	t_render_obj	func;

	init_render_obj(ptr, walls, &func, i);
	while (func.y_start < func.y_end)
	{
		if (func.y_start >= 0 && func.y_start < var->window_height)
		{
			func.x_increment = 0;
			sec_while(var, ptr, &func);
		}
		func.y_increment++;
		func.y_start++;
	}
}

void	render_objects(t_main_s *var, t_player_bonus *p_ptr)
{
	t_walls	*walls;
	int		i;

	walls = init_walls(var);
	i = 0;
	while (i < var->bonus->nbr_obj)
	{
		render_obj(var, p_ptr, walls, i);
		i++;
	}
	free(walls);
}
