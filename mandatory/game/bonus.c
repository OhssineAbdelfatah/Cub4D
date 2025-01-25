# include "../includes/ps.h"


int get_color(t_main_s *var, int x, int y)
{
    int color;
    double x_off;
    double y_off;
    double x_img, y_img;

    x_off = (double)x / ((double)(var->window_width) / 2);
    y_off = (double)y / ((double)(var->window_height) / 2);
    x_img = x_off  * (double)(var->bonus->gun_in_hand->width);
    y_img = y_off * (double)(var->bonus->gun_in_hand->height); 
    color = var->bonus->gun_in_hand_img->pixels[(int)floor(y_img)][(int)floor(x_img)];
    return color;
}

void draw_crosshairs(t_main_s *var, int len ,int width, int color)
{
    int start_x;
    int start_y;
    int i;
    int j;

    j  = 0;
    i  = 0;
    start_x = (var->window_width / 2) - (len / 2);
    start_y = (var->window_height * 0.55) - (width / 2);
    while (i < len)
    {
        j =  0;
        while (j < width)
        {
            mlx_put_pixel(var->img2, start_x + i, start_y +  j, color);
            j++;
        }
        i++;
    }
    start_x = (var->window_width / 2) - (width / 2);
    start_y = (var->window_height * 0.55) - (len / 2);
    i = 0;
    j = 0;
    while (i < width)
    {
        j = 0;
        while (j < len)
        {
            mlx_put_pixel(var->img2, start_x + i, start_y +  j, color);
            j++;
        }
        i++;
    }
}

void fps_hands_rendring(t_main_s *var)
{
    int x
    ;
    int y;
    int color;
    x = 0;
    y = 0;

    
    while (x < var->window_width / 2)
    {
        y = 0;
        while (y < var->window_height / 2)
        {
            color = get_color(var, x, y);
            if (color)
                mlx_put_pixel(var->img2, x + (var->window_width / 2)  , y + (var->window_height / 2) , color);
            y ++;
        }
        x++;
    }
}
