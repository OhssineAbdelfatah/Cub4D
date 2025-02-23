/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps.h                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:02:56 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/21 00:36:48 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_H
# define PS_H

# include "game_structs.h"
# include "macros.h"
# include "norm_structs.h"
# include "parsing.h"
# include <math.h>
# include <stdio.h>

void			shoot_the_rays(t_main_s *var);
int				need_update(t_main_s *main, t_player_infos *var);

/*************************************************/
//            >>    PLAYER_MOVE.C     <<
/*************************************************/

int				is_there_a_wall(double new_y, double new_x, char **map);
int				check_teleportation(t_player_infos *var, char **map);

/*************************************************/
//            >>    TEXTURES.C     <<
/*************************************************/

t_text			*which_texture(t_ray_info *ray, t_text **texture);
int				calc_x_img(int hor_or_ver, t_ray_info *ray, double wall_hiegt,
					double img_w);
int				calc_y_img(int y_proj, int wall_hiegt, int img_h);

/*************************************************/
//            >>    CONSTRUCTORS.C     <<
/*************************************************/

t_main_s		*init_main_var(t_parse_data *parse);
t_player_infos	*init_player_struct(t_main_s *ptr, char c, int x, int y);
t_ray_info		*init_rays(t_main_s *ptr, double ray_angle,
					double ray_increment);

t_text			*get_image(mlx_texture_t *text);
int				**get_pixles(mlx_texture_t *img, int w, int h);

/*************************************************/
//            >>    CONSTRUCTORS_2.C     <<
/*************************************************/
mlx_texture_t	*safe_load(char *path);
t_walls			*init_walls(t_main_s *ptr);
t_text			*safe_img_cnv(char *path_to_img);

/*************************************************/
//            >>    TOOLS.C     <<
/*************************************************/

int				ft_dstr_len(char **av);
double			adjust_angle(double angle);
void			panic(char *s);
int				is_it_the_player(char c);

/*************************************************/
//            >>    TOOLS_2.C     <<
/*************************************************/
int				gettt_rgba(uint8_t *color);
int				create_rgba(int r, int g, int b);

/*************************************************/
//            >>   CASTING_TOOLS_2.C     <<
/*************************************************/

void			set_ray_direction(t_ray_info *var, double ray_angle);
void			set_ray_infos(t_ray_info *ray, char which_one, t_x_and_y_d x_y,
					double distance);
void			init_cast_ray_s(t_cast_rays *func);
int				is_straight_ray(t_main_s *var, t_cast_rays *func, int i);

/*************************************************/
//            >>   CASTING.C     <<
/*************************************************/
void			init_cst_vert(t_casting *cst, t_main_s *var, int i);
void			init_cst_horiz(t_casting *cst, t_main_s *var, int i);
double			cast_vertically(t_main_s *var, int i, t_x_and_y_d *xy);
double			cast_horizontally(t_main_s *var, int i, t_x_and_y_d *xy);
int				hit_a_wall(t_main_s *var, double xintersection,
					double yintersection, int i);
int				hit_a_door(t_main_s *var, double xintersection,
					double yintersection, int i);

/*************************************************/
//            >>   PLAYER_MOVE_HOOKS.C     <<
/*************************************************/
void			turnning_around(mlx_key_data_t key, t_main_s *ptr);
void			moving_around(mlx_key_data_t key, t_main_s *ptr);
void			key_hook(mlx_key_data_t key, void *var);

/*************************************************/
//            >>   HOOKS_ND_LOOPS.C     <<
/*************************************************/
void			loop_hook(void *ptr);
void			mlx_loops_and_hooks(t_main_s *var);

/****************************TMP************ */
void			work_of_art(t_main_s *var, int shoot);
void			wall_rendering(t_main_s *var);
void			paintit(mlx_image_t *img, int color, t_xy_i *start,
					t_xy_i *till);
long long		get_time_mil(void);

/************************************************************/
//                      >> FREEDOM.C <<
/************************************************************/

void			free_rays_bonus(t_ray_info *var);
void			free_rays(t_main_s *var);

/************************************************************/
//                      >> DOOR_BONUS.C <<
/************************************************************/

void			free_p_info(t_player_infos *player, t_main_s *var);
void			free_text(t_text *text);
void			free_texts(t_text **text);
void			free_d_arr(char **av);
void			reset_them_all(t_main_s *var);
void			free_all(t_main_s *var);

#endif
