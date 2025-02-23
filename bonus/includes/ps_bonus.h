/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bonus.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 22:38:05 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/19 22:38:07 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PS_BONUS_H
# define PS_BONUS_H

# include "game_structs_bonus.h"
# include "macros_bonus.h"
# include "norm_structs_bonus.h"
# include "parsing_bonus.h"
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
//            >>    DRAWING.C     <<
/*************************************************/

void			draw_disk(mlx_image_t *img, int x_c, int y_c, int color);
void			draw_a_line2(t_main_s *var, t_draw_mini_map func, int color,
					mlx_image_t *img);

/*************************************************/
//            >>    DRAW_MINI_MAP.C     <<
/*************************************************/

int				draw_the_mini_map(t_main_s *var);

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
int				**get_pixles(mlx_texture_t *img, int w, int h);
t_text			*get_image(mlx_texture_t *text);
mlx_texture_t	*safe_load(char *path);
t_walls			*init_walls(t_main_s *ptr);
t_text			*safe_img_cnv(char *path_to_img);

/*************************************************/
//            >>    CONSTRUCTORS_BONUS.C     <<
/*************************************************/
t_rays_bonus	*init_bonus_rays(void);
t_ray_hit_door	*init_door(void);
t_bonus			*init_bonus(t_main_s *main);
t_mini_map		*init_mini_map(void *mlx, int width, int height);
/*************************************************/
//        >>    CONSTRUCTORS_TOOLS_BONUS.C    <<
/*************************************************/
double			get_distance(t_player_infos *p_var, double x, double y);
void			fill_obj(t_main_s *var, t_obj *obj, t_player_infos *p_var);
void			fill_enemy(t_main_s *var, t_enemy *enemy,
					t_player_infos *p_var);

/*************************************************/
//        >>    CONSTRUCTORS_TOOLS2_BONUS.C    <<
/*************************************************/
t_ray_hit_door	*init_door(void);
t_rays_bonus	*init_bonus_rays(void);
t_mini_map		*init_mini_map(void *mlx, int width, int height);
t_obj			*init_obj_p(t_main_s *var, t_player_infos *p_var);
t_obj			*init_obj_p(t_main_s *var, t_player_infos *p_var);
t_enemy			*init_enemies_p(t_main_s *var, t_player_infos *p_var);

/*************************************************/
//        >>    CONSTRUCTORS_TOOLS2_BONUS.C    <<
/*************************************************/

void			resizing_img_bonus(t_main_s *main, t_bonus *var);
void			swap_obj(t_obj *one, t_obj *two);
void			adjust_rank(t_obj *obj, int max);
double			calculate_obj_or_enemy_teta(t_player_infos *p_var, t_obj *obj,
					t_enemy *enemy);
void			update_obj_data(t_main_s *var, t_player_infos *p_var,
					t_obj *obj, int nbr_obj);

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
long long		get_time_mil(void);
void			func(void *param);
/*************************************************/
//            >>   CASTING_TOOLS_2.C     <<
/*************************************************/

void			set_ray_direction(t_ray_info *var, double ray_angle);
void			set_ray_infos(t_ray_info *ray, char which_one, t_x_and_y_d x_y,
					double distance);
void			init_cast_ray_s(t_cast_rays *func);
int				is_straight_ray(t_main_s *var, t_cast_rays *func, int i);
void			set_doors_infos(t_main_s *var, t_x_and_y_d xy_door, int i,
					int from);

/*************************************************/
//            >>   CASTING.C     <<
/*************************************************/
void			init_cst_vert(t_casting *cst, t_main_s *var, int i);
void			init_cst_horiz(t_casting *cst, t_main_s *var, int i);
double			cast_vertically(t_main_s *var, int i, t_x_and_y_d *xy,
					t_x_and_y_d *door_xy);
double			cast_horizontally(t_main_s *var, int i, t_x_and_y_d *xy,
					t_x_and_y_d *door_xy);
int				hit_a_wall(t_main_s *var, double xintersection,
					double yintersection, int i);
int				hit_a_door(t_main_s *var, double xintersection,
					double yintersection, int i);

/*************************************************/
//            >>   PLAYER_MOVE_HOOKS.C     <<
/*************************************************/
void			turnning_around(mlx_key_data_t key, t_main_s *ptr);
void			moving_around(mlx_key_data_t key, t_main_s *ptr);
void			looking_up_nd_down(mlx_key_data_t key, t_main_s *ptr);
void			key_hook(mlx_key_data_t key, void *var);
void			cursor_func(double xpos, double ypos, void *param);

/*************************************************/
//       >>   SHOOTING_ANIMATION_BONUS.C     <<
/*************************************************/

void			display_shooting(t_main_s *var);
void			redisplay_the_gun(t_main_s *var);
void			shoot_them_mfs(t_main_s *var);
void			mouse_hook(mouse_key_t button, action_t action,
					modifier_key_t mods, void *param);

/*************************************************/
//            >>   HOOKS_ND_LOOPS.C     <<
/*************************************************/

void			loop_hook(void *ptr);
void			mlx_loops_and_hooks(t_main_s *var);

/****************************************************/
//          >> DRAW_MINI_MAP  <<
/****************************************************/
int				draw_mini_map_42(t_main_s *var);

/****************************TMP************ */
void			work_of_art(t_main_s *var, int shoot);
void			wall_rendering(t_main_s *var);
void			paintit(mlx_image_t *img, int color, t_xy_i *start,
					t_xy_i *till);

/************************************************************/
//                      >> BONUS.C <<
/************************************************************/

void			count_obj_enemi(t_main_s *var);
t_player_bonus	*init_player_bonus(t_main_s *var, t_player_infos *ptr);

int				get_color_obj(t_main_s *var, t_render_obj func);
void			update_obj_data(t_main_s *var, t_player_infos *p_var,
					t_obj *obj, int nbr_obj);
void			render_objects(t_main_s *var, t_player_bonus *p_ptr);

double			calculate_obj_or_enemy_teta(t_player_infos *p_var, t_obj *obj,
					t_enemy *enemy);
double			get_distance(t_player_infos *p_var, double x, double y);
void			update_enemy_data(t_main_s *var, t_player_infos *p_var,
					t_enemy *enemy, int nbr_enemy);
void			render_enemies(t_main_s *var, t_player_bonus *p_ptr);
void			adjust_rank_enemies(t_enemy *enemy, int max);

long long		get_time_mil(void);
void			draw_health_bar(t_main_s *var, t_health_bar *bar);
void			shoot_them_mfs(t_main_s *var);
void			redisplay_the_gun(t_main_s *var);

/************************************************************/
//                      >> FLOOR_CEILING-BONUS.C <<
/************************************************************/

void			draw_floor(t_main_s *var, int x, int y, int nbr_ray);
void			render_sky(t_main_s *var, int x, int y_end, int nbr_ray);

/************************************************************/
//                      >> FREEDOM.C <<
/************************************************************/

void			free_rays_bonus(t_ray_info *var);
void			free_rays(t_main_s *var);

/************************************************************/
//                      >> DOOR_BONUS.C <<
/************************************************************/

int				is_there_door(t_rays_bonus *ray, t_main_s *var, int ray_nbr);
void			draw_door(t_main_s *var, int i, int j, double offset);
void			free_p_info(t_player_infos *player, t_main_s *var);
void			free_p_bonus(t_main_s *var, t_player_bonus *player_b);
void			free_minimap(t_main_s *var, t_mini_map *mini_map);
void			free_text(t_text *text);
void			free_texts(t_text **text);
void			free_d_arr(char **av);
void			free_main_bonus(t_bonus *var, t_main_s *main);
void			reset_them_all(t_main_s *var);
void			free_all(t_main_s *var);

/************************************************************/
//                      >> OBJ_TOOLS_BONUS.C <<
/************************************************************/

bool			check_doors_for_obj_rendering(t_main_s *var,
					t_player_bonus *ptr, int i, int ray_to_inspect);

/************************************************************/
//                      >> ENEMIES_TOOLS_BONUS.C <<
/************************************************************/

int				get_color_enemy(t_main_s *var, t_render_enemy *func,
					int enemy_height, int enemy_width);

bool			check_for_doors(t_main_s *var, t_player_bonus *ptr, int i,
					int ray_to_inspect);
void			chase_player(t_main_s *var, t_player_infos *p_player,
					t_enemy *enemy, int i);
void			damage_player(t_player_infos *player, t_enemy *enemy, int i);

int				check_for_walls(t_main_s *var, t_player_infos *p_player,
					t_enemy *enemy, int i);
/************************************************************/
//                      >> ENEMIES_TOOLS_PART2_BONUS.C <<
/************************************************************/
int				is_sorted(t_obj *obj, t_enemy *enemy, int max);
void			swap_enemy(t_enemy *one, t_enemy *two);
void			adjust_rank_enemies(t_enemy *enemy, int max);

#endif
