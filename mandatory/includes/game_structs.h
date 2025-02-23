/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_structs.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:49:29 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/21 00:14:21 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_STRUCTS_H
# define GAME_STRUCTS_H

# include "../../lib/mlx/include/MLX42/MLX42.h"
# include "parsing.h"
# include "ps.h"
# include <stdbool.h>
# include <sys/time.h>

typedef struct s_main_struct		t_main_s;
typedef struct s_player_infos		t_player_infos;
typedef struct s_data				t_data;
typedef struct s_test				t_test;
typedef struct s_ray_info			t_ray_info;
typedef struct s_casting			t_casting;
typedef struct s_walls_rendering	t_walls;
typedef struct s_mini_map			t_mini_map;
typedef struct s_textures_imgs		t_textures_img;
typedef struct s_x_and_y_d			t_x_and_y_d;
typedef struct s_xy_i				t_xy_i;
typedef struct s_calc_img			t_calc_img;
typedef struct timeval				t_time;

/* TEXTURES */

typedef struct s_img				t_img;
typedef struct s_text				t_text;

struct								s_img
{
	double							x_img;
	double							y_img;
};

struct								s_xy_i
{
	int								x;
	int								y;
};

struct								s_text
{
	int								**pixels;
	int								width;
	int								hieght;
};

/***************************/

struct								s_x_and_y_d
{
	bool							hit_a_door;
	double							x;
	double							y;
	double							distance;
};

struct								s_data
{
	void							*img;
	char							*addr;
	int								bits_per_pixel;
	int								line_length;
	int								endian;
};

struct								s_ray_info
{
	bool							facing_up;
	bool							facing_left;
	bool							facing_right;
	bool							facing_down;
	double							x_last_intersection;
	double							y_last_intersection;
	int								x_hor;
	int								y_ver;
	double							wall_hight;
	int								horzt_or_vert;
	double							distance;
	double							angle;
	char							wall_dir;
};

struct								s_player_infos
{
	int								pov;
	int								move_up_down;
	int								move_left_right;
	int								turn_arround;
	int								nbr_rays;
	double							x;
	double							y;
	double							speed;
	double							rotation_speed;
	double							rotation_angle;
	double							fov;
	t_walls							*walls;
	t_ray_info						*rays;
};

struct								s_textures_imgs
{
	int								height;
	int								width;
	void							*img_ver;
	void							*img_hor;
};

struct								s_main_struct
{
	int								window_width;
	int								window_height;
	int								map_hight;
	int								map_width;
	long long						start_frame;
	char							**map;
	mlx_t							*mlx;
	mlx_image_t						*img2;
	t_text							**text;
	t_player_infos					*p_infos;
	t_parse_data					*parse;
	t_walls							*walls;
};

struct								s_casting
{
	double							distance;
	double							xsteps;
	double							ysteps;
	double							xintersection;
	double							yintersection;
	double							tan_angle;
};

struct								s_walls_rendering
{
	double							distance_prj_plane;
	double							prj_plane_height;
	double							wall_hight;
};

struct								s_calc_img
{
	double							door_h;
	double							offset;
	int								x_door;
	int								top;
	int								j;
};

#endif
