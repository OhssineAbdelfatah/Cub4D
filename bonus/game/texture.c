#include"../includes/ps.h"
#include"math.h"


// inter[0] => x_inter
// inter[1] => y_inter
int calc_x_img( t_main_s *var,t_calc_img* calc,char type)
{
    double x_img;
    double a;

    x_img = 0;
    if(var->p_infos->rays->horzt_or_vert == 'h')
    {
        if(type == 'D')
            a = var->p_infos->rays[calc->ray_nbr].bonus_rays->door->x_intersection / (double)square_len;
        else if(type == 'W')
            a = var->p_infos->rays[calc->ray_nbr].x_last_intersection / (double)square_len;
    }else if(var->p_infos->rays->horzt_or_vert == 'v'){
        if(type == 'D')
            a = var->p_infos->rays[calc->ray_nbr].bonus_rays->door->y_intersection / (double)square_len;
        else if(type == 'W')
            a = var->p_infos->rays[calc->ray_nbr].y_last_intersection / (double)square_len;
    }
    x_img = (a) - floor(a);
    if(type == 'D')
        x_img *= calc->img_door_w;
    else if(type == 'W')
        x_img *= calc->img_w;
    return (int)(x_img);
}

// int calc_y_img(int y_proj ,int wall_hiegt , int img_h)
int calc_y_img(int y_proj ,int wall_hiegt , int img_h, int door_h, int img_door_h, char type)
{

    double y_img;
    double y_prc;
    if(type == 'D')
    {
        y_prc = (double)y_proj / (double)door_h;
        y_img = y_prc * img_door_h;
    }else if(type == 'W'){

        y_prc = (double)y_proj / (double)wall_hiegt;
        y_img = y_prc * img_h;
    } 
    return (int)y_img;
}


int	create_trgb(int r, int g, int b, int a)
{
	return (r << 24 | g << 16 | b << 8 | a);
}

/***
 * images stored in array in a strict order 
 * following real direction N -> E -> S -> W 
*/

// int	gettt_rgba(uint8_t *color)
// {
// 	return (color[0] << 24 | color[1] << 16 | color[2] << 8 | color[3]);
// }

