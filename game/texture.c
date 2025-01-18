#include"../includes/cube.h"
#include"math.h"


// inter[0] => x_inter
// inter[1] => y_inter
int calc_x_img(char hor_or_ver, t_ray_info *ray, int wall_hiegt, int img_w)
{
    double x_img;
    double a;

    if(hor_or_ver == 'v')
    {
        a = ray->x_last_intersection / (double)wall_hiegt;
        printf("---------Xinter [%f]\n", a);
        x_img = (a) - floor(a);
    }else if(hor_or_ver == 'h')
    {
        a = ray->y_last_intersection / (double)wall_hiegt;
        x_img = (a) - floor(a);
        printf("---------Yinter [%f]\n", x_img);
    }
    return (int)(x_img * img_w);
}

int calc_y_img(int top, int y_proj ,int wall_hiegt , int img_h)
{
    double y_img;
    double y_prc;
    y_prc = (y_proj - top) / wall_hiegt;
    y_img = y_prc * img_h;
    return (int)y_img;
}