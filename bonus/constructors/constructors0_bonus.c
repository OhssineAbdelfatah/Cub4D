/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 23:58:45 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/15 23:58:47 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

void	set_player_direction(t_player_infos *var, char c)
{
	if (c == 'E')
		var->rotation_angle = M_PI / 2;
	if (c == 'W')
		var->rotation_angle = M_PI + (M_PI / 2);
	if (c == 'N')
		var->rotation_angle = M_PI;
	if (c == 'S')
		var->rotation_angle = 0;
}

t_player_infos	*init_player_struct(t_main_s *ptr, char c, int x, int y)
{
	t_player_infos	*var;

	var = malloc(sizeof(*var));
	if (!var)
		panic("malloc failed !\n");
	var->y = y;
	var->x = x;
	var->move_up_down = 0;
	var->move_left_right = 0;
	var->turn_arround = 0;
	var->speed = 10;
	var->rotation_speed = (M_PI / 180) * 3;
	var->rays = NULL;
	var->nbr_rays = 0;
	var->fov = (M_PI / 180) * 60;
	set_player_direction(var, c);
	var->walls = init_walls(ptr);
	var->p_bonus = init_player_bonus(ptr, var);
	return (var);
}

t_text	**init_textures(t_main_s *var)
{
	t_text	**text;

	text = malloc(sizeof(t_text *) * 4);
	if (!text)
		panic("malloc failed !\n");
	text[0] = safe_img_cnv(var->parse->tex_no);
	text[1] = safe_img_cnv(var->parse->tex_ea);
	text[2] = safe_img_cnv(var->parse->tex_so);
	text[3] = safe_img_cnv(var->parse->tex_we);
	return (text);
}

t_main_s	*init_main_var(t_parse_data *parse)
{
	t_main_s	*var;

	var = malloc(sizeof(*var));
	if (!var)
		panic("malloc failed !\n");
	var->window_height = 800;
	var->window_width = 1400;
	var->p_infos = NULL;
	var->parse = parse;
	var->map = parse->map;
	var->map_hight = ft_dstr_len(var->map);
	var->map_width = ft_strlen(var->map[0]);
	mlx_set_setting(0, 1);
	var->mlx = mlx_init(var->window_width, var->window_height, "cub3D", true);
	var->img2 = mlx_new_image(var->mlx, var->window_width, var->window_height);
	var->mini_map = init_mini_map(var->mlx, var->window_width,
			var->window_height);
	var->text = init_textures(var);
	var->bonus = init_bonus(var);
	var->start_frame = get_time_mil();
	return (var);
}

t_ray_info	*init_rays(t_main_s *ptr, double ray_angle, double angle_incremet)
{
	int			i;
	t_ray_info	*var;

	i = 0;
	var = malloc(sizeof(*var) * ptr->p_infos->nbr_rays);
	if (!var)
		panic("malloc failed !\n");
	while (i < ptr->p_infos->nbr_rays)
	{
		var[i].angle = 0;
		var[i].distance = 0;
		var[i].horzt_or_vert = 0;
		var[i].facing_left = false;
		var[i].facing_right = false;
		var[i].x_last_intersection = 0;
		var[i].y_last_intersection = 0;
		var[i].wall_dir = 0;
		var[i].bonus_rays = init_bonus_rays();
		i++;
		ray_angle += angle_incremet;
	}
	return (var);
}
