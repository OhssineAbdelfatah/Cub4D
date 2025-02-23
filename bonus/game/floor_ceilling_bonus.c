/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   floor_ceilling_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:54:35 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/18 21:54:38 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

int	get_sky_color(t_main_s *var, int y, int nbr_ray)
{
	int	color;
	int	x_sky;
	int	y_sky;

	y_sky = (int)floor((double)var->bonus->sky_text->hieght * ((double)y
				/ (double)(var->window_height)));
	x_sky = (int)floor(var->p_infos->rays[nbr_ray].angle
			* ((double)var->bonus->sky_text->width / (2 * M_PI)));
	color = var->bonus->sky_text->pixels[y_sky][x_sky];
	return (color);
}

void	render_sky(t_main_s *var, int x, int y_end, int nbr_ray)
{
	int	color;
	int	y;

	y = 0;
	while (y < y_end)
	{
		color = get_sky_color(var, y, nbr_ray);
		if (color)
			mlx_put_pixel(var->img2, x, y, color);
		y++;
	}
}

int	get_color_of_floor(t_main_s *var, double x, double y)
{
	int		color;
	double	x_offset;
	double	y_offset;
	int		new_x;
	int		new_y;

	x_offset = (double)x / SQ_LEN;
	y_offset = (double)y / SQ_LEN;
	x_offset = x_offset - floor(x_offset);
	y_offset = y_offset - floor(y_offset);
	new_x = (double)var->bonus->floor_text->width * x_offset;
	new_y = (double)var->bonus->floor_text->hieght * y_offset;
	color = 0;
	if ((new_x >= 0 && new_x < var->bonus->floor_text->width) && (new_y >= 0
			&& new_y < var->bonus->floor_text->hieght))
		color = var->bonus->floor_text->pixels[new_y][new_x];
	return (color);
}

int	get_color_for_floor(t_main_s *var, int y, int nbr_ray)
{
	t_get_color_for_floor	func;

	func.beta = var->p_infos->rays[nbr_ray].angle
		- var->p_infos->rotation_angle;
	func.beta = adjust_angle(func.beta);
	func.r = y - ((var->window_height / 2) + var->p_infos->up_down_offset);
	func.straight_line_dis = ((SQ_LEN / 2) / func.r)
		* var->p_infos->walls->distance_prj_plane;
	func.origin_line_distance = func.straight_line_dis / cos(func.beta);
	func.floor_x = var->p_infos->y + (cos(var->p_infos->rays[nbr_ray].angle
				- (M_PI / 2)) * func.origin_line_distance);
	func.floor_y = var->p_infos->x - (sin(var->p_infos->rays[nbr_ray].angle
				- (M_PI / 2)) * func.origin_line_distance);
	func.color = get_color_of_floor(var, func.floor_x, func.floor_y);
	return (func.color);
}

void	draw_floor(t_main_s *var, int x, int y, int nbr_ray)
{
	int	color;

	while (y < var->window_height)
	{
		color = get_color_for_floor(var, y, nbr_ray);
		if (color)
			mlx_put_pixel(var->img2, x, y, color);
		y++;
	}
}
