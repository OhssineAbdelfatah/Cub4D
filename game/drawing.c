# include "../includes/ps.h"

void draw_square(t_main_s *var, int x, int y)
{
    int i,j;

    i = 0;
    j = 0;
    while (i < square_len  * scale_of_minimap )
    {
        while (j < (square_len * scale_of_minimap  ) -1)
        {
            my_mlx_pixel_put(&var->img, x + i, y + j, 0x000000FF);
            j++;
        }
        my_mlx_pixel_put(&var->img, x + i, y + j, 0x000000FF);
        j = 0;
        i++;
    }
}

void  draw_empty_square(t_main_s *var,  int  y, int x)
{
    int i;

    i = 0;
    while (i < square_len  * scale_of_minimap )
    {
        my_mlx_pixel_put(&var->img, y  + i, x , 0x000000FF);
        i++;
    }
    i = 0;
    while (i < square_len  * scale_of_minimap )
    {
        my_mlx_pixel_put(&var->img, y ,x + i, 0x000000FF);
        i++;
    }
}


void draw_a_line(t_main_s *var, int s_x, int s_y, int f_x, int f_y, int color)
{
    int dx = abs(f_x - s_x);
    int dy = abs(f_y - s_y);
    int sx = (s_x < f_x) ? 1 : -1;
    int sy = (s_y < f_y) ? 1 : -1;
    int err = dx - dy;
    while (1)
    {
        if (s_x == f_x && s_y == f_y)
            break;
        if (s_x < 0 || s_y < 0)
            break;
        if (var->map_hight * square_len <= s_y || var->map_width * square_len <=  s_x)
            break;
        my_mlx_pixel_put(&var->img, s_x, s_y, color);
        int e2 = 2 * err;
        if (e2 > -dy)
        {
            err -= dy;
            s_x += sx;
        }
        if (e2 < dx)
        {
            err += dx;
            s_y += sy;
        }
    }
}

void 
draw_disk(t_main_s *var, int x_c, int y_c, int radius)
{
    int x, y;

    y = -radius;
    while (y <= radius) {
        x = -radius;
        while (x <= radius) {
            if (x * x + y * y <= radius * radius) {
                my_mlx_pixel_put(&var->img, x_c + x, y_c + y, 0x000000FF);
            }
            x++;
        }
        y++;
    }
}



void draw_disk1(t_main_s *var, int x_c, int y_c, int radius)
{
    int x, y;

    y = -radius;
    while (y <= radius) {
        x = -radius;
        while (x <= radius) {
            if (x * x + y * y <= radius * radius) {
                my_mlx_pixel_put(&var->img2, x_c + x, y_c + y, 0x000000FF);
            }
            x++;
        }
        y++;
    }
}

void draw_disk2(t_test *var, int x_c, int y_c, int radius)
{
    int x, y;

    y = -radius;
    while (y <= radius) {
        x = -radius;
        while (x <= radius) {
            if (x * x + y * y <= radius * radius) {
                my_mlx_pixel_put(&var->img, x_c + x, y_c + y, 0x000000FF);
            }
            x++;
        }
        y++;
    }
}
void draw_disk3(t_test *var, int x_c, int y_c, int radius)
{
    int x, y;

    y = -radius;
    while (y <= radius) {
        x = -radius;
        while (x <= radius) {
            if (x * x + y * y <= radius * radius) {
                my_mlx_pixel_put(&var->img1, x_c + x, y_c + y, 0x000000FF);
            }
            x++;
        }
        y++;
    }
}