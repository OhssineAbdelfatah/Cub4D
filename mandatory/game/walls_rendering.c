/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   walls_rendering.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:56:14 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/18 21:56:15 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

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

void	wall_rendering_core(t_main_s *var, t_wall_rendering *func)
{
	while (func->i >= 0)
	{
		func->texture = which_texture(var->p_infos->rays + func->i, var->text);
		func->adjusted_distance = adjust_distance(var, func->i);
		if (func->adjusted_distance == 0)
			func->adjusted_distance = 0.5;
		var->walls->wall_hight = (SQ_LEN / func->adjusted_distance)
			* var->walls->distance_prj_plane;
		func->top = (((var->window_height) / 2) - (var->walls->wall_hight / 2));
		func->buttom = func->top + var->walls->wall_hight;
		func->x_img = calc_x_img(var->p_infos->rays[func->i].horzt_or_vert,
				var->p_infos->rays + func->i, SQ_LEN, func->texture->width);
		draw_rectangle(var, func->texture, *func);
		func->i--;
		func->j++;
	}
}

void	wall_rendering(t_main_s *var)
{
	t_wall_rendering	func;

	func.color = 0;
	func.i = var->p_infos->nbr_rays - 1;
	func.j = 0;
	var->walls = init_walls(var);
	wall_rendering_core(var, &func);
	free(var->walls);
}
