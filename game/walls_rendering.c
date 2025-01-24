#include "../includes/ps.h"

int	gettt_rgba(uint8_t *color)
{
	return (color[0] << 24 | color[1] << 16 | color[2] << 8 | color[3]);
}

int	gettt_rgba2(uint8_t *color, int trans)
{
	return (color[0] << 24 | color[1] << 16 | color[2] << 8 | trans);
}

void draw_rectangle(t_main_s *var,int x, int top , int buttom, int x_img, int color, int transparency)
{
    int j; 
    int y_img;
    
    j = top;
    while (j < buttom)
    {
        if (j >= 0 && j < var->window_height) // window hieght
        {
            y_img = calc_y_img(j - top, buttom - top, var->text[0].hieght);
            // color = gettt_rgba( &var->text[0].pixels[(y_img * var->text->width + x_img) * 4]);
            // if(x_img < var->text[0].hieght && y_img < var->text[0].width )
            color = var->text[0].pixels[y_img][x_img];
            // color = gettt_rgba2((unsigned char *)(var->text[0].pixels[y_img] + x_img+ 3), transparency );
            mlx_put_pixel(var->img2, x , j , color);
        }
        j++;
    }
    (void)transparency;
    return ;
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
    // int b;
    int moy;
    i = var->p_infos->nbr_rays-1;
    moy = i /2;
    j = 0;
    walls = init_walls(var);

    while (i >= 0)
    {
        adjusted_distance = adjust_distance(var, i);
        if (adjusted_distance == 0)
            adjusted_distance = 0.5;
        walls->wall_hight = (square_len / adjusted_distance) * walls->distance_prj_plane;
    
        y = (var->window_height) / 2 - (walls->wall_hight / 2);
        x = (var->window_height) / 2 + (walls->wall_hight / 2);

        transparency = get_transparency(adjusted_distance);
        // color = create_trgb(transparency, 51, 255, b);
        // get img to be used here
        // x_img = calc_x_img(var->p_infos->rays[i].horzt_or_vert, var->p_infos->rays+i, walls->wall_hight, imgs[0].width); //  0 stands for img width
        x_img = calc_x_img(var->p_infos->rays[i].horzt_or_vert, var->p_infos->rays+i, square_len, var->text->width); //  test
        // printf("%d\n", x_img);
        // t_main_s *var,int x, int top , int buttom, int x_img, int color
        draw_rectangle(var, j, y, x, x_img, color, transparency);
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

