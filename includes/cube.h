#ifndef CUBE_H
#define CUBE_H

// #include "mlx.h"
// #include <mlx.h>
#include "parsing.h"
#include "macros.h"

#define square_len 64


// typedef struct s_player_cord t_player_cord;

// struct s_player_cord
// {
//     int x;
//     int y;
//     int radius;
//     int turn_direction;
//     int walk_direction;
//     int rotation_angle;
//     int move_speed;
//     int rotation_speed;
// };


void draw_circle(void *mlx, void *mlx_win,int x, int y, int radius);
void  draw_empty_square(void *mlx, void *mlx_win,int  y, int x);
/*-------------DIRECTIONS-----------*/
int         turn_left(void *ptr);
int        turn_right(void *ptr);
int        go_back(void *ptr);
int        go_forward(void *ptr);
#endif