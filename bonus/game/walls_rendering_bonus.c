/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_rendering_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:56:14 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/18 21:56:15 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

void	draw_rectangle(t_main_s *var, t_text *text, t_wall_rendering func)
{
	int	j;
	int	y_img;

	j = func.top;
	while (j < func.buttom)
	{
		if (j >= 0 && j < var->window_height)
		{
			y_img = calc_y_img(j - func.top, func.buttom - func.top,
					text->hieght);
			func.color = text->pixels[y_img][func.x_img];
			mlx_put_pixel(var->img2, func.j, j, func.color);
		}
		j++;
	}
	return ;
}

double	adjust_distance(t_main_s *var, int i)
{
	double	teta_angle;
	double	adjusted_distance;

	teta_angle = var->p_infos->rays[i].angle
		- var->p_infos->rays[var->p_infos->nbr_rays / 2].angle;
	if (teta_angle < 0)
		teta_angle *= -1;
	adjusted_distance = cos(teta_angle) * var->p_infos->rays[i].distance;
	return (adjusted_distance);
}

void	door_slide_offset(t_main_s *var, double *offset)
{
	if (*offset >= 0 && var->p_infos->rays[699].bonus_rays->door->distance < 128
		&& var->p_infos->rays[699].bonus_rays->door->distance > 0)
		*offset -= 0.1;
	else if (*offset < 1
		&& var->p_infos->rays[699].bonus_rays->door->distance > 128
		&& var->p_infos->rays[699].bonus_rays->door->distance > 0)
		*offset += 0.1;
}

void	wall_rendering_core(t_main_s *var, t_wall_rendering *func,
		double offset)
{
	while (func->i >= 0)
	{
		func->texture = which_texture(var->p_infos->rays + func->i, var->text);
		func->adjusted_distance = adjust_distance(var, func->i);
		if (func->adjusted_distance == 0)
			func->adjusted_distance = 0.5;
		var->walls->wall_hight = (SQ_LEN / func->adjusted_distance)
			* var->walls->distance_prj_plane;
		func->top = (((var->window_height) / 2) - (var->walls->wall_hight / 2))
			+ var->p_infos->up_down_offset;
		func->buttom = func->top + var->walls->wall_hight;
		func->x_img = calc_x_img(var->p_infos->rays[func->i].horzt_or_vert,
				var->p_infos->rays + func->i, SQ_LEN, func->texture->width);
		render_sky(var, func->j, func->top, func->i);
		draw_rectangle(var, func->texture, *func);
		draw_floor(var, func->j, func->buttom, func->i);
		if (is_there_door(var->p_infos->rays[func->i].bonus_rays, var, func->i))
			draw_door(var, func->i, func->j, offset);
		func->i--;
		func->j++;
	}
}

void	wall_rendering(t_main_s *var)
{
	t_wall_rendering	func;
	static double		offset = 1;

	func.color = 0;
	func.i = var->p_infos->nbr_rays - 1;
	func.j = 0;
	var->walls = init_walls(var);
	door_slide_offset(var, &offset);
	wall_rendering_core(var, &func, offset);
	free(var->walls);
}
