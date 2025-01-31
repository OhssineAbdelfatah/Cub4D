# include "../includes/ps.h"

int get_sky_color (t_main_s *var, int y, int nbr_ray)
{
    int color;
    int x_sky, y_sky;

    y_sky =  (int)floor( (double)var->bonus->sky_text->hieght *  ((double)y /  (double)(var->window_height)));

    x_sky = (int)floor(var->p_infos->rays[nbr_ray].angle * ((double)var->bonus->sky_text->width / (2 * M_PI))); 

    color = var->bonus->sky_text->pixels[y_sky][x_sky];
    return color;
}

void render_sky(t_main_s *var, int x, int y_end, int nbr_ray)
{
    int color;
    int y;

    y = 0;
    while (y < y_end)
    {
        color = get_sky_color(var, y, nbr_ray);
        if (color)
            mlx_put_pixel(var->img2, x, y, color);
        y++;
    }
}



int get_color_of_floor(t_main_s *var, double x, double y)
{
    int color;
    double x_offset;
    double y_offset;

    int new_x;
    int new_y;

    x_offset = (double)x /square_len;
    y_offset = (double)y /square_len;

    x_offset = x_offset - floor(x_offset);
    y_offset = y_offset - floor(y_offset);

    new_x = (double)var->bonus->floor_text->width * x_offset;
    new_y = (double)var->bonus->floor_text->hieght * y_offset;

    color = var->bonus->floor_text->pixels[(int)floor(new_y)][(int)floor(new_x)];
    return color;
}

int get_color_for_floor(t_main_s *var, int y, int nbr_ray)
{
    int color;
    double beta,r,  straight_line_dis, origin_line_distance, floor_x, floor_y;

    beta = var->p_infos->rays[nbr_ray].angle - var->p_infos->rotation_angle;
    beta = adjust_angle(beta);
    r = y -  ((var->window_height / 2) + var->p_infos->up_down_offset);
    straight_line_dis = ((square_len / 2) / r) * var->p_infos->walls->distance_prj_plane;
    origin_line_distance = straight_line_dis / cos(beta);
    floor_x = var->p_infos->y + (cos(var->p_infos->rays[nbr_ray].angle - (M_PI / 2)) * origin_line_distance);
    floor_y = var->p_infos->x - (sin(var->p_infos->rays[nbr_ray].angle - (M_PI / 2)) * origin_line_distance) ;

    color = get_color_of_floor(var, floor_x, floor_y);
    return color;
}

void draw_floor(t_main_s *var, int x, int y, int nbr_ray)
{
    int color;

    while (y < var->window_height)
    {
        color = get_color_for_floor(var, y, nbr_ray);
        if (color)
            mlx_put_pixel(var->img2, x, y, color);
        y++;
    }
}