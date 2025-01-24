#include"../includes/ps.h"
#include"math.h"


// inter[0] => x_inter
// inter[1] => y_inter
int calc_x_img(int hor_or_ver, t_ray_info *ray, double wall_hiegt, double img_w)
{
    double x_img;
    double a;

    x_img = 0;
    if(hor_or_ver == 'h')
    {
        a = ray->x_last_intersection / (double)wall_hiegt;
        // printf("---------Xinter [%f]\n", a);
        x_img = (a) - floor(a);
    }
    else if(hor_or_ver == 'v')
    {
        a = ray->y_last_intersection / (double)wall_hiegt;
        x_img = (a) - floor(a);
        // printf("---------Yinter [%f]\n", x_img);
    }
    return (int)(x_img * img_w);
}

int calc_y_img(int y_proj ,int wall_hiegt , int img_h)
{
    double y_img;
    double y_prc;
    y_prc = (double)y_proj / (double)wall_hiegt;
    y_img = y_prc * img_h;
    return (int)y_img;
}


int	create_trgb(int t, int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | t);
}

/***
 * images stored in array in a strict order 
 * following real direction N -> E -> S -> W 
*/

// int	gettt_rgba(uint8_t *color)
// {
// 	return (color[0] << 24 | color[1] << 16 | color[2] << 8 | color[3]);
// }

