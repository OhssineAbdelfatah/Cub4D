#ifndef POS_H
#define POS_H

#include <stdio.h>
#include <mlx.h>
#include <math.h>
#include "parsing.h"
#include "macros.h"
#include "game_structs.h"


#define square_len 24


int need_update(t_player_infos * var);
void draw_a_line(void *mlx, void *win, int s_x, int s_y, int f_x, int f_y);
void  draw_empty_square(void *mlx, void *mlx_win,int  y, int x);
int draw_the_map(t_main_s *var);
t_main_s *init_main_var(void);
t_player_infos *init_player_struct(char c, int x, int y);
void draw_disk(t_main_s *var,  int x_c, int y_c, int radius);
/*-------------DIRECTIONS-----------*/
int         turn_left(t_main_s *ptr);
int        turn_right(t_main_s *ptr);
int        go_back(t_main_s *ptr);
int        go_forward(t_main_s *ptr);
#endif