# include "../includes/ps.h"






int get_color(t_main_s *var, int x, int y)
{
    t_text *img;

    int color;
    double x_off;
    double y_off;
    double x_img, y_img;

    // if (!var->bonus)
    //     panic("bonus is null \n");

    // if (!var->bonus->gun_in_hand)
    //     panic("gun is null \n");
    img = get_image(var->bonus->gun_in_hand);
    x_off = x / var->window_width;
    y_off = y / var->window_height;
    
    // printf("aloo\n");
    // printf("gun hieght : %d\n",var->bonus->gun_in_hand->height);
    // printf("gun width : %d\n", var->bonus->gun_in_hand->width);
    x_img = x_off  * (var->bonus->gun_in_hand->width);
    y_img = y_off * (var->bonus->gun_in_hand->height); 
    color = img->pixels[(int)floor(x_img)][(int)floor(y_img)];
    // color = gettt_rgba(&var->bonus->gun_in_hand->pixels[((int)y_img * var->bonus->gun_in_hand->width + (int)x_img) * 4]);
    color = 0;   
    (void)img;
    return color;
}



void fps_hands_rendring(t_main_s *var)
{
    int x , y;
    int color;
    x = 0;
    y = 0;

    
    printf("H :%d ,W %d\n", var->window_height, var->window_width);
    while (x < var->window_width)
    {
        y = 0;
        while (y < var->window_height)
        {
            color = get_color(var, x, y);
            // mlx_put_pixel(var->img2, x, y, color);
            y ++;
        }
        x++;
    }
    printf("done whiling \n");


    // (void)x;
    
}
