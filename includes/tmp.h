#ifndef PS_H
#define PS_H

#include <stdio.h>
// #include <mlx.h>
#include"../lib/mlx/include/MLX42/MLX42.h"
#include <math.h>
#include "parsing.h"
#include "macros.h"
#include "game_structs.h"


#define square_len 30
#define player_radius 5
// #define FOV 1.5



void shoot_the_rays(t_main_s * var);
int need_update(t_player_infos * var, char **map);



/*************************************************/
//            >>    DRAWING.C     <<
/*************************************************/
void draw_square(t_main_s *var, int x, int y);
void draw_a_line(t_main_s *var, int s_x, int s_y, int f_x, int f_y);
void  draw_empty_square(t_main_s *var,int  y, int x);
void draw_disk(t_main_s *var, int x_c, int y_c, int radius);
void draw_disk1(t_test *var, int x_c, int y_c, int radius);

/*************************************************/
//            >>    DRAW_MINI_MAP.C     <<
/*************************************************/

int draw_the_map(t_main_s *var);

/*************************************************/
//            >>    CONSTRUCTORS.C     <<
/*************************************************/

t_main_s *init_main_var(void);
t_player_infos *init_player_struct(char c, int x, int y);
t_ray_info *init_rays(t_main_s *ptr, double ray_angle, double ray_increment);


/*************************************************/
//            >>    TOOLS.C     <<
/*************************************************/


void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
double adjust_angle(double angle);
void panic(char *s);



/*************************************************/
//            >>   CASTING.C     <<
/*************************************************/
void init_cst_vert(t_casting *cst, t_main_s *var, int i);
void init_cst_horiz(t_casting *cst, t_main_s *var, int i);
int hit_a_wall(t_casting *cst, t_main_s *var, int i, int ref);
int cast_vertically(t_main_s *var, int i);
int cast_horizontally(t_main_s *var, int i);


/*-------------DIRECTIONS-----------*/
int         turn_left(t_main_s *ptr);
int        turn_right(t_main_s *ptr);
int        go_back(t_main_s *ptr);
int        go_forward(t_main_s *ptr);
#endif