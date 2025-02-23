/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:02:54 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/19 22:02:55 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

mlx_image_t	*get_mlximg(t_main_s *var, char *path)
{
	mlx_texture_t	*tmp;
	mlx_image_t		*ret;

	tmp = safe_load(path);
	ret = mlx_texture_to_image(var->mlx, tmp);
	mlx_delete_texture(tmp);
	if (!ret)
		panic("mlx_texture_to_image failed !\n");
	return (ret);
}

void	init_bonus_part2(t_main_s *main, t_bonus *var)
{
	var->gun_img[1]->enabled = false;
	var->gun_img[2]->enabled = false;
	var->gun_img[3]->enabled = false;
	var->mouse_x = (main->window_width) / 2;
	var->mouse_y = (main->window_height) / 2;
	var->mouse_move = 0;
	var->nbr_enemies = 0;
	var->nbr_obj = 0;
}

t_bonus	*init_bonus(t_main_s *main)
{
	t_bonus	*var;

	var = (t_bonus *)malloc(sizeof(t_bonus));
	if (!var)
		panic("malloc faild! \n");
	var->enemy_text = safe_img_cnv("./assets/textures/AGAHA1.png");
	var->dead_enemy_text = safe_img_cnv("./assets/textures/AGAHL0.png");
	var->door = safe_img_cnv("./assets/textures/doortile.png");
	var->floor_text = safe_img_cnv("./assets/floor/Brick/brick1.png");
	var->sky_text = safe_img_cnv("./assets/sky/FuzzySky/Sunset.png");
	var->obj_img = safe_img_cnv("./assets/textures/EHEDC0.png");
	var->gun_img[0] = get_mlximg(main, "./assets/textures/RGLGD0.png");
	var->gun_img[1] = get_mlximg(main, "./assets/textures/RGLFA0.png");
	var->gun_img[2] = get_mlximg(main, "./assets/textures/RGLFB0.png");
	var->gun_img[3] = get_mlximg(main, "./assets/textures/RGLFC0.png");
	var->crosshair_img = get_mlximg(main, "./assets/textures/techno1.png");
	resizing_img_bonus(main, var);
	init_bonus_part2(main, var);
	return (var);
}

t_health_bar	*init_h_bar(t_player_infos *p_var)
{
	t_health_bar	*res;

	res = (t_health_bar *)malloc(sizeof(*res));
	if (!res)
		panic("malloc failed !\n");
	res->x = 0;
	res->y = 0;
	res->width = 300;
	res->end = (int)floor((double)res->width * ((double)p_var->health
				/ (double)p_var->max_health));
	res->height = 30;
	res->health_str = NULL;
	res->health_img = NULL;
	return (res);
}

t_player_bonus	*init_player_bonus(t_main_s *var, t_player_infos *p_var)
{
	t_player_bonus	*res;

	res = (t_player_bonus *)malloc(sizeof(t_player_bonus));
	if (!res)
		panic("malloc failed!\n");
	p_var->jump_kneel = 0;
	p_var->look_up_down = 0;
	p_var->up_down_offset = 0;
	p_var->alive = true;
	p_var->health = 100;
	p_var->max_health = p_var->health;
	count_obj_enemi(var);
	res->enemy = init_enemies_p(var, p_var);
	res->obj = init_obj_p(var, p_var);
	res->h_bar = init_h_bar(p_var);
	return (res);
}
