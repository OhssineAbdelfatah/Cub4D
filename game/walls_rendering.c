#include "../includes/ps.h"

// y is top 
// j
int	gettt_rgba(uint8_t *color)
{
	return (color[0] << 24 | color[1] << 16 | color[2] << 8 | color[3]);
}


// void draw_rectangle(t_main_s *var, int x, int top, int buttom, int width, int color, int x_img, t_ray_info *ray, double wall_h, double img_h, t_text *imgs)
void draw_rectangle(t_main_s *var,int x, int top , int buttom, int x_img, int color)
{
    int j; 
    // int i;
    int y_img;
    
    // i = 0;
    j = top;
    // while (i < width)
    // {
        while (j < buttom)
        {
            // get color(pixel) from image

            y_img = calc_y_img(j - top, buttom - top, var->text[0].hieght);
            // y_img = ((j - top) / (buttom - top)) * var->text->height;
            // printf("y_img : %d\n", y_img);
            // create rgba
            // my_mlx_pixel_put(&var->img2, x + i , y + j, color);
            // my_mlx_pixel_put(&var->img2, x + i , y + j, color);
            if (j >= 0 && j <= var->window_height) // window hieght
            {
                if ((y_img * var->text->width + x_img)  <= var->text->width * var->text[0].hieght)
                {
                    // color = gettt_rgba( &var->text[0].pixels[(y_img * var->text->width + x_img) * 4]);
                    color = var->text[0].pixels[x_img][y_img];
                    if(j >= 0 &&  j < var->window_height)
                        mlx_put_pixel(var->img2, x , j , color);

                        // continue;
                }
            }
            j++;
        }
        // j = 0;
        // i ++;
        // exit(0);
    // }
}

double adjust_distance(t_main_s *var, int i)
{
    double teta_angle;
    double adjusted_distance ;

    teta_angle = var->p_infos->rays[i].angle - var->p_infos->rays[var->p_infos->nbr_rays / 2].angle;
    if (teta_angle < 0)
        teta_angle *= -1;
    adjusted_distance = cos(teta_angle) * var->p_infos->rays[i].distance;
    return adjusted_distance; 
}



int get_transparency(double distance)
{
    // static int ss;
    int i, distance2;
    i = 0;
    distance2 = (int)floor(distance);
    while (i < distance2)
        i++;
    i /= 5;
    if (i > 255)
        i = 255;
    return (255 - i);
}


void    wall_rendering(t_main_s *var)
{
    t_walls *walls;
    // t_text *imgs;
    double adjusted_distance;
    int color = 0 ;
    int transparency;
    int y;
    int x;
    int x_img;
    int i;
    int j;
    int b;
    int moy;
    i = var->p_infos->nbr_rays-1;
    moy = i /2;
    j = 0;
    walls = init_walls(var);

    // imgs = get_images(var);
    while (i >= 0)
    {
        adjusted_distance = adjust_distance(var, i);
        walls->wall_hight = (square_len / adjusted_distance) * walls->distance_prj_plane;
        // if (walls->wall_hight > var->window_height)
        //     walls->wall_hight = var->window_height;
        y = (var->window_height) / 2 - (walls->wall_hight / 2);
        x = (var->window_height) / 2 + (walls->wall_hight / 2);
        // just coloring
        transparency = get_transparency(adjusted_distance);
        // transparency = 255;
        b = 255;
        if (var->p_infos->rays[i].horzt_or_vert == 'v')
        b =150;
        // color = create_trgb(transparency, 51, 255, b);
        // color = create_trgb(transparency, 51, 255, b);// rgba 
        // get img to be used here
        // x_img = calc_x_img(var->p_infos->rays[i].horzt_or_vert, var->p_infos->rays+i, walls->wall_hight, imgs[0].width); //  0 stands for img width
        x_img = calc_x_img(var->p_infos->rays[i].horzt_or_vert, var->p_infos->rays+i, square_len, var->text->width); //  test
        // printf("%d\n", x_img);
        // t_main_s *var,int x, int top , int buttom, int x_img, int color
        draw_rectangle(var, j, y, x, x_img, color);
        // exit(0);

        // if (j == moy)
        //     printf("x :: %f , y:: %f",var->p_infos->rays[j].x_last_intersection, var->p_infos->rays[j].y_last_intersection);
        // draw_rectangle(var, j, y, walls->wall_hight, 1,color);
        i--;
        j++;
    }
    (void)x_img;
    free(var->p_infos->rays);
    free(walls);
}

