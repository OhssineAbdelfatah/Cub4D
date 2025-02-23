/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors_tools3_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:33:14 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/19 22:33:16 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

void	resizing_img_bonus(t_main_s *main, t_bonus *var)
{
	mlx_resize_image(var->crosshair_img, main->window_width / 14,
		main->window_height / 8);
	mlx_resize_image(var->gun_img[0], main->window_width - (main->window_width
			/ 3), main->window_height - (main->window_height / 3));
	mlx_resize_image(var->gun_img[1], main->window_width - (main->window_width
			/ 3), main->window_height - (main->window_height / 3));
	mlx_resize_image(var->gun_img[2], main->window_width - (main->window_width
			/ 3), main->window_height - (main->window_height / 3));
	mlx_resize_image(var->gun_img[3], main->window_width - (main->window_width
			/ 3), main->window_height - (main->window_height / 3));
}

void	swap_obj(t_obj *one, t_obj *two)
{
	t_obj	tmp;

	tmp = *one;
	*one = *two;
	*two = tmp;
}

void	adjust_rank(t_obj *obj, int max)
{
	int	i;

	i = 0;
	while (is_sorted(obj, NULL, max))
	{
		i = 0;
		while (i < max)
		{
			if (i + 1 < max)
			{
				if (obj[i].distance < obj[i + 1].distance)
					swap_obj(&obj[i], &obj[i + 1]);
			}
			i++;
		}
	}
}

double	calculate_obj_or_enemy_teta(t_player_infos *p_var, t_obj *obj,
		t_enemy *enemy)
{
	double	teta;

	if (!enemy)
	{
		teta = p_var->rotation_angle + (p_var->fov / 2) - obj->vector_teta;
		if (p_var->rotation_angle < (M_PI / 2) && obj->vector_teta > (M_PI
				+ (M_PI / 2)))
			teta += (2 * M_PI);
		if (p_var->rotation_angle > (M_PI + (M_PI / 2))
			&& obj->vector_teta < (M_PI / 2))
			teta -= (2 * M_PI);
		return (teta);
	}
	teta = p_var->rotation_angle + (p_var->fov / 2) - enemy->vector_teta;
	if (p_var->rotation_angle < (M_PI / 2) && enemy->vector_teta > (M_PI + (M_PI
				/ 2)))
		teta += (2 * M_PI);
	if (p_var->rotation_angle > (M_PI + (M_PI / 2))
		&& enemy->vector_teta < (M_PI / 2))
		teta -= (2 * M_PI);
	return (teta);
}

void	update_obj_data(t_main_s *var, t_player_infos *p_var, t_obj *obj,
		int nbr_obj)
{
	int	i;

	i = 0;
	if (obj)
	{
		while (i < nbr_obj)
		{
			obj[i].distance = get_distance(p_var, obj[i].x, obj[i].y);
			obj[i].vector_x = p_var->y - obj[i].x;
			obj[i].vector_y = p_var->x - obj[i].y;
			obj[i].vector_teta = atan2(-obj[i].vector_y, obj[i].vector_x);
			obj[i].vector_teta = adjust_angle(obj[i].vector_teta - (M_PI / 2));
			obj[i].obj_teta = calculate_obj_or_enemy_teta(p_var, &obj[i], NULL);
			obj[i].x_screen = obj[i].obj_teta * (1400 / p_var->fov);
			obj[i].y_screen = (var->window_height / 2)
				+ var->p_infos->up_down_offset;
			i++;
		}
		adjust_rank(obj, nbr_obj);
	}
}
