/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door_bonus_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:38:06 by aohssine          #+#    #+#             */
/*   Updated: 2025/02/19 00:26:25 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

int	calc_x_door(int hor_or_ver, t_ray_hit_door *ray, double door_hiegt,
		double img_door_w)
{
	double	x_img;
	double	a;

	x_img = 0;
	if (hor_or_ver == 'h')
	{
		a = ray->x_intersection / (double)door_hiegt;
		x_img = a - floor(a);
	}
	else if (hor_or_ver == 'v')
	{
		a = ray->y_intersection / (double)door_hiegt;
		x_img = a - floor(a);
	}
	(void)ray;
	return ((int)(x_img * img_door_w));
}

int	calc_y_door(int y_proj, int door_hiegt, int img_door_h)
{
	double	y_img;
	double	y_prc;

	y_prc = (double)y_proj / (double)door_hiegt;
	y_img = y_prc * (double)img_door_h;
	return ((int)y_img);
}

double	adjust_distance_door(t_main_s *var, int i)
{
	double	teta_angle;
	double	adjusted_distance;

	teta_angle = var->p_infos->rays[i].angle
		- var->p_infos->rays[var->p_infos->nbr_rays / 2].angle;
	if (teta_angle < 0)
		teta_angle *= -1;
	adjusted_distance = cos(teta_angle)
		* var->p_infos->rays[i].bonus_rays->door->distance;
	return (adjusted_distance);
}

void	draw_door_pix(t_main_s *var, t_calc_img tmp)
{
	int	c;
	int	y_door;
	int	color;

	c = 0;
	while (c + (tmp.door_h - (tmp.door_h * tmp.offset)) < tmp.door_h)
	{
		if (c + tmp.top >= 0 && c + tmp.top + (tmp.door_h - (tmp.door_h
					* tmp.offset)) < var->window_height)
		{
			y_door = calc_y_door(c, tmp.door_h, var->bonus->door->hieght);
			if (y_door >= 0 && tmp.x_door >= 0
				&& y_door < var->bonus->door->hieght
				&& tmp.x_door < var->bonus->door->width)
				color = var->bonus->door->pixels[y_door][tmp.x_door];
			mlx_put_pixel(var->img2, tmp.j, c + tmp.top + (tmp.door_h
					- (tmp.door_h * tmp.offset)), color);
		}
		c++;
	}
}

void	draw_door(t_main_s *var, int i, int j, double offset)
{
	t_calc_img	tmp;
	double		adjusted_distance;

	tmp.j = j;
	tmp.offset = offset;
	adjusted_distance = adjust_distance_door(var, i);
	if (adjusted_distance == 0)
		adjusted_distance = 0.5;
	tmp.door_h = ((double)SQ_LEN / adjusted_distance)
		* var->walls->distance_prj_plane;
	tmp.top = ((var->window_height) / 2) - (tmp.door_h / 2)
		+ var->p_infos->up_down_offset;
	tmp.x_door = calc_x_door(var->p_infos->rays[i].bonus_rays->door->from,
			var->p_infos->rays[i].bonus_rays->door, SQ_LEN,
			var->bonus->door->width);
	draw_door_pix(var, tmp);
}
