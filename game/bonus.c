# include "../includes/ps.h"





void fps_hands_rendring(t_main_s *var)
{
    int x , y;
    int color;
    x = 0;
    y = 0;
    while (x < var->window_width)
    {
        while (y < var->window_height)
        {
            color = get_color();
            mlx_put_pixel(var->img2, x, y, color);
            y ++;
        }
        y = 0;
        x++;
    }
}
