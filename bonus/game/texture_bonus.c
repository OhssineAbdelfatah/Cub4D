/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:38:09 by aohssine          #+#    #+#             */
/*   Updated: 2025/02/19 00:26:45 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

t_text	*which_texture(t_ray_info *ray, t_text **texture)
{
	if (ray->wall_dir == 'N')
		return (texture[0]);
	if (ray->wall_dir == 'E')
		return (texture[1]);
	if (ray->wall_dir == 'S')
		return (texture[2]);
	if (ray->wall_dir == 'W')
		return (texture[3]);
	return (NULL);
}

int	calc_x_img(int hor_or_ver, t_ray_info *ray, double wall_hiegt, double img_w)
{
	double	x_img;
	double	a;

	x_img = 0;
	if (hor_or_ver == 'h')
	{
		a = ray->x_last_intersection / (double)wall_hiegt;
		x_img = a - floor(a);
	}
	else if (hor_or_ver == 'v')
	{
		a = ray->y_last_intersection / (double)wall_hiegt;
		x_img = a - floor(a);
	}
	return ((int)(x_img * img_w));
}

int	calc_y_img(int y_proj, int wall_hiegt, int img_h)
{
	double	y_img;
	double	y_prc;

	y_prc = (double)y_proj / (double)wall_hiegt;
	y_img = y_prc * img_h;
	return ((int)y_img);
}

int	is_there_door(t_rays_bonus *ray, t_main_s *var, int ray_nbr)
{
	return ((ray->hit_a_door && ray->door->distance
			&& ray->door->distance < var->p_infos->rays[ray_nbr].distance));
}
