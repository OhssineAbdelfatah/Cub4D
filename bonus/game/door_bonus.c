#include"../includes/ps.h"


int is_there_door(t_rays_bonus* ray, t_main_s *var, int ray_nbr)
{
    return ((ray->hit_a_door
        && ray->door->distance
        && ray->door->distance < var->p_infos->rays[ray_nbr].distance)
    );
}

int calc_x_door(int hor_or_ver, t_ray_hit_door *ray, double door_hiegt, double img_door_w)
{
    double x_img;
    double a;

    x_img = 0;
    if(hor_or_ver == 'h')
    {
        a = ray->x_intersection / (double)door_hiegt;
        // printf("---------Xinter [%f]\n", a);
        x_img = (a) - floor(a);
    }
    else if(hor_or_ver == 'v')
    {
        a = ray->y_intersection / (double)door_hiegt;
        x_img = (a) - floor(a);
        // printf("---------Yinter [%f]\n", x_img);
    }
    return (int)(x_img * img_door_w);
}

int calc_y_door(int y_proj ,int door_hiegt , int img_door_h)
{
    double y_img;
    double y_prc;
    y_prc = (double)y_proj / (double)door_hiegt;
    y_img = y_prc * img_door_h;
    return (int)y_img;
}

double adjust_distance_door(t_main_s *var, int i)
{
    double teta_angle;
    double adjusted_distance ;

    teta_angle = var->p_infos->rays[i].angle - var->p_infos->rays[var->p_infos->nbr_rays / 2].angle;
    if (teta_angle < 0)
        teta_angle *= -1;
    adjusted_distance = cos(teta_angle) * var->p_infos->rays[i].bonus_rays->door->distance;
    return adjusted_distance; 
}

void    draw_door(t_main_s *var,t_walls *walls, int i, int j)
{
    int top;
    int buttom;
    int c;
    double door_h;
    int x_door;
    int y_door;
    int adjusted_distance;

    adjusted_distance = adjust_distance_door(var, i);
    if (adjusted_distance == 0)
        adjusted_distance = 0.5;
    door_h =((double)square_len / adjusted_distance) * walls->distance_prj_plane; 
    top = ((var->window_height) / 2) - (door_h / 2);
    buttom = ((var->window_height) / 2) + (door_h / 2);
    x_door = calc_x_door(var->p_infos->rays[i].horzt_or_vert, var->p_infos->rays[i].bonus_rays->door, door_h, var->bonus->door->width);
    c= top;
    printf("top %d buttom %d door_h %.5f\n", top , buttom, door_h);
    while(c < buttom)
    {
        // if (c >= 0 && c < var->window_height) // window hieght
        // {
            y_door = calc_y_door(c - top, door_h, var->bonus->door->hieght);
            // color = gettt_rgba( &var->text[0].pixels[(y_door * var->text->width + x_img) * 4]);
            // if(x_img < var->text[0].hieght && y_door < var->text[0].width )

            int color = 0xf11111;
            if(y_door >= 0 && x_door >=0 && y_door < var->bonus->door->hieght && x_door < var->bonus->door->width)
                color = var->bonus->door->pixels[y_door][x_door];
            // printf("x_door %d y_door %d xdraw %d ydraw %d\n", x_door, y_door, j, c);
            puts("alohh");
            mlx_put_pixel(var->img2, j , c, color);
        // }
        c++;
    }
    (void)top;
}


