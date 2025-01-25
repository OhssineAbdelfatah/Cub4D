#ifndef PS_H
#define PS_H

#include <stdio.h>
// #include <mlx.h>
#include <math.h>
#include "parsing.h"
#include "macros.h"
#include "game_structs.h"







void shoot_the_rays(t_main_s * var);
int need_update(t_player_infos * var, char **map);

int is_there_a_wall(double new_y, double new_x, char **map);
int check_teleportation(t_player_infos *var, char **map);

/*************************************************/
//            >>    DRAWING.C     <<
/*************************************************/

void draw_square(t_main_s *var, int x, int y);
void draw_a_line(t_main_s *var, int s_x, int s_y, int f_x, int f_y, int color);
void  draw_empty_square(t_main_s *var,int  y, int x);
void draw_disk(t_main_s *var, int x_c, int y_c, int radius);
void draw_disk1(t_main_s *var, int x_c, int y_c, int radius);
void draw_disk11(mlx_image_t *img ,int x_c, int y_c, int radius, int color);
void draw_disk2(t_test *var, int x_c, int y_c, int radius);
void draw_disk3(t_test *var, int x_c, int y_c, int radius);
void draw_square_for_mini(mlx_image_t *img, int x, int y, int color);
void  draw_empty_square_for_mini(mlx_image_t *img,  int  y, int x);
void draw_a_line2(t_main_s *var, int s_x, int s_y, int f_x, int f_y, int color, mlx_image_t *img);

/*************************************************/
//            >>    DRAW_MINI_MAP.C     <<
/*************************************************/

int draw_the_mini_map(t_main_s *var);

/*************************************************/
//            >>    CONSTRUCTORS.C     <<
/*************************************************/

t_main_s *init_main_var(t_parse_data *parse);
t_player_infos *init_player_struct(char c, int x, int y);
t_ray_info *init_rays(t_main_s *ptr, double ray_angle, double ray_increment);
t_walls *init_walls(t_main_s *ptr);


t_text *get_image(mlx_texture_t *text);
int **gat_pixles(mlx_texture_t* img, int w, int h);
/*************************************************/
//            >>    TOOLS.C     <<
/*************************************************/

int ft_dstr_len(char **av);
void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
double adjust_angle(double angle);
void panic(char *s);
int is_it_the_player(char c);



/*************************************************/
//            >>   CASTING.C     <<
/*************************************************/
void init_cst_vert(t_casting *cst, t_main_s *var, int i);
void init_cst_horiz(t_casting *cst, t_main_s *var, int i);
// int hit_a_wall(t_casting *cst, t_main_s *var, int i, int ref);
double cast_vertically(t_main_s *var, int i, t_x_and_y_d *xy);
double cast_horizontally(t_main_s *var, int i, t_x_and_y_d *xy);
int hit_a_wall(t_main_s *var, double xintersection, double yintersection, int i);


/*************************************************/
//            >>   HOOKS_ND_LOOPS.C     <<
/*************************************************/
// int key_hook(int key, t_main_s *ptr);
void key_hook(mlx_key_data_t key, void *var);
// int loop_hook(t_main_s *var);
void loop_hook(void *ptr);
void mlx_loops_and_hooks(t_main_s *var);

/*-------------DIRECTIONS-----------*/
int         turn_left(t_main_s *ptr);
int        turn_right(t_main_s *ptr);
int        go_back(t_main_s *ptr);
int        go_forward(t_main_s *ptr);


/****************************************************/
//          >> DRAW_MINI_MAP  <<
/****************************************************/
int draw_mini_map_42(t_main_s *var);

/****************************TMP************ */
void fill_map(char **av,t_main_s *var);
void work_of_art(t_main_s *var);
void wall_rendering(t_main_s *var);
// void paintit(mlx_image_t *img, int color, int hight, int width);
void paintit(mlx_image_t *img, int color, t_xy_i *start, t_xy_i *till);


/************************************************************/
//                      >> BONUS.C <<
/************************************************************/


void fps_hands_rendring(t_main_s *var);
void draw_crosshairs(t_main_s *var, int len ,int width, int color);


#endif