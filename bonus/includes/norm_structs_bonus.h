/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_structs_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:49:18 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/14 22:49:20 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORM_STRUCTS_BONUS_H
# define NORM_STRUCTS_BONUS_H

# include "game_structs_bonus.h"

typedef struct s_need_update			t_need_update;
typedef struct s_render_obj				t_render_obj;
typedef struct s_cast_rays				t_cast_rays;
typedef struct s_shoot_the_rays			t_shoot_rays;
typedef struct s_fill_obj				t_fill_obj;
typedef struct s_fill_enemy				t_fill_enemy;
typedef struct s_check_pixel			t_check_pixel;
typedef struct s_draw_mini_map			t_draw_mini_map;
typedef struct s_draw_line				t_draw_line;
typedef struct s_render_enemy			t_render_enemy;
typedef struct s_work_of_art_part1		t_work_of_art_part1;
typedef struct s_get_color_for_floor	t_get_color_for_floor;
typedef struct s_wall_rendering			t_wall_rendering;

struct									s_need_update
{
	int									check;
	double								move_steps;
	double								new_y;
	double								new_x;
	double								tmp_angle;
};

struct									s_render_obj
{
	int									i;
	int									obj_height;
	int									obj_width;
	int									x_start;
	int									x_end;
	int									y_start;
	int									y_end;
	int									color;
	int									x_increment;
	int									y_increment;
	int									ray_to_inspect;
};

struct									s_cast_rays
{
	t_x_and_y_d							v_xy_door;
	t_x_and_y_d							h_xy_door;
	t_x_and_y_d							v_xy;
	t_x_and_y_d							h_xy;
	double								distance1;
	double								distance2;
};

struct									s_shoot_the_rays
{
	double								ray_angle;
	int									i;
	double								fov;
	double								angle_to_start;
	double								ray_angle_increment;
};

struct									s_fill_obj
{
	int									x;
	int									y;
	int									i;
};

struct									s_fill_enemy
{
	int									x;
	int									y;
	int									i;
};

struct									s_check_pixel
{
	int									enemy_there;
	int									diff_x;
	int									diff_y;
	int									square;
};

struct									s_draw_mini_map
{
	int									x;
	int									y;
	int									new_x;
	int									new_y;
};

struct									s_draw_line
{
	int									f_x;
	int									f_y;
	int									s_x;
	int									s_y;
	int									dx;
	int									dy;
	int									sx;
	int									sy;
	int									err;
	int									e2;
};

struct									s_render_enemy
{
	int									i;
	int									x_start;
	int									x_end;
	int									y_start;
	int									y_end;
	int									color;
	int									x_increment;
	int									y_increment;
	int									ray_to_inspect;
};

struct									s_work_of_art_part1
{
	int									x;
	int									y;
	int									i;
	int									p_x;
	int									p_y;
	int									c_x;
	int									c_y;
};

struct									s_get_color_for_floor
{
	int									color;
	double								beta;
	double								r;
	double								straight_line_dis;
	double								origin_line_distance;
	double								floor_x;
	double								floor_y;
};

struct									s_wall_rendering
{
	t_walls								*walls;
	t_text								*texture;
	double								adjusted_distance;
	int									color;
	int									top;
	int									buttom;
	int									x_img;
	int									i;
	int									j;
};

#endif
