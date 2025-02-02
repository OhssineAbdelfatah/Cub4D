#include "../includes/ps.h"

void draw_v_sides(t_main_s *var, int width, int height,int frame_width)
{
    t_xy_i xy;

    xy.x = 0;
    xy.y = 0;

    while (xy.y < height)
    { 
        xy.x = 0;
        if ((xy.y >= 0 && xy.y < 0 + frame_width) || (xy.y > height - (frame_width + 1) && xy.y <= height -1))
        {
            while(xy.x < width)
            {
                mlx_put_pixel(var->img2, xy.x + 20, xy.y + var->window_height - 60, 0xFFFFFFFF);
                xy.x++;
            }

        } 
        xy.y++;
    }

}

void draw_h_sides(t_main_s *var, int width , int height, int frame_width)
{
    t_xy_i xy;

    xy.x = 0;
    xy.y = 0;
    while (xy.x < width)
    {
        xy.y = 0;
        while (xy.y < height)
        {
            if ((xy.x >= 0 && xy.x < 0 + frame_width) || (xy.x < width && xy.x >= width - frame_width))
                mlx_put_pixel(var->img2, xy.x + 20, xy.y + var->window_height - 60, 0xFFFFFFFF);
            xy.y++;
        }
        xy.x++;
    }
}

void draw_health_frame(t_main_s *var,int width,int height)
{
    int frame_width;

    frame_width = 4;
    draw_v_sides(var, width, height, frame_width);
    draw_h_sides(var, width, height, frame_width);

}

void draw_health_bar(t_main_s *var)
{
    int x, y,  height, end, width;

    x = 0;
    y = 0;
    width = 300;
    end = (int)floor ((double)width * ((double)var->p_infos->health / (double)var->p_infos->max_health )) ;
    height = 30;
    while (y < height)
    {
        x = 0;
        while (x < end)
        {
            mlx_put_pixel(var->img2, x + 20 , y + var->window_height - 60, 0xFF3333FF);
            x ++;
        }
        y++;
    }

    draw_health_frame(var, width, height);

    // char *health_state;
    // health_state = ft_itoa(var->p_infos->health);
    // mlx_put_string(var->mlx, health_state,100,  var->window_height - 30);
    // free(health_state);
}
