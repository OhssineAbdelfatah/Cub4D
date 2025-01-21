#ifndef TEXTURES_h
#define TEXTURES_h

#include "game_structs.h"
// 

typedef struct s_img t_img;

struct s_img {
    double x_img;
    double y_img;
};

typedef struct s_text {
    int **pixels;
    int width;
    int hieght;
} t_text;

int	create_trgb(int t, int r, int g, int b);
int calc_x_img(int hor_or_ver, t_ray_info *ray, double wall_hiegt, double img_w);
int calc_y_img(int y_proj ,int wall_hiegt , int img_h);
t_text *get_images(t_main_s *var);

#endif