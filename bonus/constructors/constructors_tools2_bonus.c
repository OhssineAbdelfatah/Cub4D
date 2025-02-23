/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors_tools_bonus2.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:02:37 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/19 22:02:39 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

t_ray_hit_door	*init_door(void)
{
	t_ray_hit_door	*ret;

	ret = (t_ray_hit_door *)malloc(sizeof(t_ray_hit_door));
	if (!ret)
		panic("malloc failed !\n");
	ret->distance = 0;
	ret->from = 0;
	ret->x_intersection = 0;
	ret->y_intersection = 0;
	return (ret);
}

t_rays_bonus	*init_bonus_rays(void)
{
	t_rays_bonus	*ret;

	ret = (t_rays_bonus *)malloc(sizeof(t_rays_bonus));
	if (!ret)
		panic("malloc failed !\n");
	ret->hit_a_door = false;
	ret->door = init_door();
	return (ret);
}

t_mini_map	*init_mini_map(void *mlx, int width, int height)
{
	t_mini_map	*var;

	var = malloc(sizeof(t_mini_map));
	if (!var)
		panic("malloc faild !\n");
	var->mini_square_len = 32;
	var->minimap_height = 32 * 7;
	var->minimap_width = 32 * 9;
	var->p_y = var->minimap_height / 2;
	var->p_x = var->minimap_width / 2;
	var->img3 = mlx_new_image(mlx, var->minimap_width, var->minimap_height);
	(void)height;
	(void)width;
	return (var);
}

t_obj	*init_obj_p(t_main_s *var, t_player_infos *p_var)
{
	t_obj	*res;

	if (var->bonus->nbr_obj == 0)
		return (NULL);
	res = (t_obj *)malloc(sizeof(t_obj) * var->bonus->nbr_obj);
	if (!res)
		panic("malloc failed!\n");
	fill_obj(var, res, p_var);
	return (res);
}

t_enemy	*init_enemies_p(t_main_s *var, t_player_infos *p_var)
{
	t_enemy	*res;

	if (var->bonus->nbr_enemies == 0)
		return (NULL);
	res = (t_enemy *)malloc(sizeof(t_enemy) * var->bonus->nbr_enemies);
	if (!res)
		panic("malloc failed!\n");
	fill_enemy(var, res, p_var);
	return (res);
}
