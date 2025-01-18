#ifndef TEXTURES_h
#define TEXTURES_h


typedef struct s_img t_img;

struct s_img {
    double x_img;
    double y_img;
};


int calc_x_img(char hor_or_ver, t_ray_info *ray, int wall_hiegt, int img_w);
int calc_y_img(int *inter,int top, int y_proj ,int wall_hiegt , int img_h);

#endif