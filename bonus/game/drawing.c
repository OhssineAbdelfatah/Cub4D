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
            mlx_put_pixel(var->img2, x + i, y + j, 0x000000FF);
            // my_mlx_pixel_put(&var->img, x + i, y + j, 0x000000FF);
            j++;
        }
        mlx_put_pixel(var->img2, x + i, y + j, 0x000000FF);
        // my_mlx_pixel_put(&var->img, x + i, y + j, 0x000000FF);
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
        mlx_put_pixel(var->img2, y  + i, x , 0x000000FF);
        i++;
    }
    i = 0;
    while (i < square_len  * scale_of_minimap )
    {
        mlx_put_pixel(var->img2, y ,x + i, 0x000000FF);
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
        // if (var->map_hight * square_len <= s_y || var->map_width * square_len <=  s_x)
        //     break; 
        if (var->window_height <= s_y || var->window_width <=  s_x)
            break;
        // my_mlx_pixel_put(&var->img, s_x, s_y, color);
        mlx_put_pixel(var->img2, s_x, s_y, color);
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
                mlx_put_pixel(var->img2, x_c + x, y_c + y, 0x000000FF);
                // my_mlx_pixel_put(&var->img, x_c + x, y_c + y, 0x000000FF);
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
                mlx_put_pixel(var->mini_map->img3, x_c + x, y_c + y, 0x000000FF);
                // my_mlx_pixel_put(&var->mini_map->img3, x_c + x, y_c + y, 0x000000FF);
            }
            x++;
        }
        y++;
    }
}


void draw_disk11(mlx_image_t *img, int x_c, int y_c, int radius, int color)
{
    int x, y;

    y = -radius;
    while (y <= radius) {
        x = -radius;
        while (x <= radius) {
            if (x * x + y * y <= radius * radius) {
                if ((x_c + x >= 0 && x_c+ x < img->width) &&( y_c + y < img->height && y_c + y >= 0))
                    mlx_put_pixel(img, x_c + x, y_c + y, color);
            }
            x++;
        }
        y++;
    }
}

// void draw_disk2(t_test *var, int x_c, int y_c, int radius)
// {
//     int x, y;

//     y = -radius;
//     while (y <= radius) {
//         x = -radius;
//         while (x <= radius) {
//             if (x * x + y * y <= radius * radius) {
//                 // my_mlx_pixel_put(&var->img1, x_c + x, y_c + y, 0x000000FF);
//                 // mlx_put_pixel(var->img, x_c + x, y_c + y, 0x000000FF);
//             }
//             x++;
//         }
//         y++;
//     }
// }
// void draw_disk3(t_test *var, int x_c, int y_c, int radius)
// {
//     int x, y;

//     y = -radius;
//     while (y <= radius) {
//         x = -radius;
//         while (x <= radius) {
//             if (x * x + y * y <= radius * radius) {
//                 // my_mlx_pixel_put(&var->img1, x_c + x, y_c + y, 0x000000FF);
//             }
//             x++;
//         }
//         y++;
//     }
// }



void draw_square_for_mini(mlx_image_t *img, int x, int y, int color)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (i < 32)
    {
        while (j < 32 - 1)
        {
            // my_mlx_pixel_put(img, x + i, y + j, color);
            mlx_put_pixel(img, x + i, y + j, color);
            j++;
        }
        mlx_put_pixel(img, x + i, y + j, color);
        // my_mlx_pixel_put(img, x + i, y + j, color);
        j = 0;
        i++;
    }
}


void  draw_empty_square_for_mini(mlx_image_t *img,  int  y, int x)
{
    int i;

    i = 0;
    while (i < 32 )
    {
        mlx_put_pixel(img, y  + i, x , 0x000000FF);
        // my_mlx_pixel_put(img, y  + i, x , 0x000000FF);
        i++;
    }
    i = 0;
    while (i < 32 )
    {
        mlx_put_pixel(img, y ,x + i, 0x000000FF);
        // my_mlx_pixel_put(img, y ,x + i, 0x000000FF);
        i++;
    }
}



void draw_a_line2(t_main_s *var, int s_x, int s_y, int f_x, int f_y, int color, mlx_image_t *img)
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
        // if (var->map_hight * square_len <= s_y || var->map_width * square_len <=  s_x)
        //     break; 
        if (var->window_height <= s_y || var->window_width <=  s_x)
            break;
        // my_mlx_pixel_put(img, s_x, s_y, color);
        mlx_put_pixel(img, s_x, s_y, color);
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