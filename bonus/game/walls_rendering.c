#include "../includes/ps.h"

int	gettt_rgba(uint8_t *color)
{
	return (color[0] << 24 | color[1] << 16 | color[2] << 8 | color[3]);
}
t_text *which_texture(t_ray_info* ray, t_text** texture)
{
    if(ray->wall_dir ==  'W')
        return texture[0];
    if(ray->wall_dir ==  'E')
        return texture[1];
    if(ray->wall_dir ==  'S')
        return texture[2];
    if(ray->wall_dir ==  'N')
        return texture[3];
    return NULL;
}

int	gettt_rgba2(uint8_t *color, int trans)
{
	return (color[0] << 24 | color[1] << 16 | color[2] << 8 | trans);
}

int is_there_door(t_rays_bonus* ray, t_main_s *var, int ray_nbr)
{
    return ((ray->hit_a_door
        && ray->door->distance
        && ray->door->distance < var->p_infos->rays[ray_nbr].distance)
    );
}

void draw_rect_door(t_main_s *var, t_text* text,int x, int top , int buttom, int x_door, int color, int transparency,int ray_nbr)
{
    int j; 
    int y_door;
    
    j = top;
    while (j < buttom)
    {
        if (j >= 0 && j < var->window_height) // window hieght
        {
            if( is_there_door(var->p_infos->rays[ray_nbr].bonus_rays, var ,ray_nbr))
             {
                // int calc_y_img(int y_proj ,int wall_hiegt , int img_h, int door_h, int img_door_h, char type)
                // 
                y_door = calc_y_img(j - top , 0, 0, buttom - top, var->bonus->door->hieght,'D');
                color = var->bonus->door->pixels[y_door][x_door];
                mlx_put_pixel(var->img3, x , j , color);
                // color = 
            }
        }
        j++;
    }
    (void)text;
    (void)transparency;
}

void draw_rectangle(t_main_s *var, t_text* text,int x, int top , int buttom, int x_img, int color, int transparency,int ray_nbr)
{
    int j; 
    int y_img;
    
    j = top;
    while (j < buttom)
    {
        if (j >= 0 && j < var->window_height) // window hieght
        {
            y_img = calc_y_img(j - top, buttom - top, text->hieght, 0,0 , 'W');
            color = text->pixels[y_img][x_img];
            mlx_put_pixel(var->img2, x , j , color);
        }
        j++;
    }
    (void)transparency;
    (void)ray_nbr;
    return ;
}

double adjust_distance(t_main_s *var, int i, char type)
{
    double which_distance ;
    double teta_angle;
    double adjusted_distance ;

    which_distance = var->p_infos->rays[i].distance;
    if(type =='D')
        which_distance = var->p_infos->rays[i].bonus_rays->door->distance;
    
    teta_angle = var->p_infos->rays[i].angle - var->p_infos->rays[var->p_infos->nbr_rays / 2].angle;
    if (teta_angle < 0)
        teta_angle *= -1;
    adjusted_distance = cos(teta_angle) * which_distance;
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


int get_color_of_floor(t_main_s *var, double x, double y)
{
    int color;
    double x_offset;
    double y_offset;

    int new_x, new_y;

    x_offset = (double)x /square_len;
    y_offset = (double)y / square_len;

    x_offset = x_offset - floor(x_offset);
    y_offset = y_offset - floor(y_offset);

    new_x = (double)var->bonus->floor_text->width * x_offset;
    new_y = (double)var->bonus->floor_text->hieght * y_offset;

    color = var->bonus->floor_text->pixels[(int)floor(new_y)][(int)floor(new_x)];
    return color;
}

int get_color_for_floor(t_main_s *var, int x, int y, int nbr_ray)
{
    int color;
    double beta,r,  straight_line_dis, origin_line_distance, floor_x, floor_y;

    beta = var->p_infos->rays[nbr_ray].angle - var->p_infos->rotation_angle;
    beta = adjust_angle(beta);
    r = y -  (var->window_height / 2);
    straight_line_dis = ((square_len / 2) / r) * var->p_infos->walls->distance_prj_plane;
    origin_line_distance = straight_line_dis / cos(beta);
    floor_x = var->p_infos->x + (cos(var->p_infos->rays[nbr_ray].angle) * origin_line_distance);
    floor_y = var->p_infos->y - (sin(var->p_infos->rays[nbr_ray].angle) * origin_line_distance) ;

    color = get_color_of_floor(var, floor_x, floor_y);
    (void)x;
    // (void)i;
    return color;
}

void draw_floor(t_main_s *var, int x, int y, int nbr_ray)
{
    int color;

    while (y < var->window_height)
    {
        color = get_color_for_floor(var, x, y, nbr_ray);
        if (color)
            mlx_put_pixel(var->img2, x, y, color);
        y++;
    }
}



int get_sky_color (t_main_s *var, int y, int nbr_ray)
{
    int color;
    int x_sky, y_sky;

    y_sky =  (int)floor( (double)var->bonus->sky_text->hieght *  ((double)y /  (double)(var->window_height / 2)));

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

void init_calc(t_calc_img* calc,double door_h, double img_w, double img_door_w )
{
    calc->door_h = door_h;
    calc->img_door_w = img_door_w;
    calc->img_w = img_w;
    return ;
}

void    wall_rendering(t_main_s *var)
{
    // t_walls *walls;
    t_calc_img calc;
    t_text *texture;
    double adjusted_distance;
    int color = 0 ;
    int transparency;
    int y;
    int x;
    int x_img;
    int i;
    int j;
    int x_door;
    double door_hieght;


    i = var->p_infos->nbr_rays-1;
    j = 0;
    init_calc(&calc, 0,0,0);
    var->p_infos->walls = init_walls(var);
    while (i >= 0)
    {
        calc.ray_nbr = i;
        texture = which_texture(var->p_infos->rays+i, var->text);
        adjusted_distance = adjust_distance(var, i, 0);
        if (adjusted_distance == 0)
            adjusted_distance = 0.5;
        var->p_infos->rays[i].wall_hight = (square_len / adjusted_distance) * var->p_infos->walls->distance_prj_plane;
        y = ((var->window_height) / 2) - (var->p_infos->rays[i].wall_hight / 2);
        x = ((var->window_height) / 2) + (var->p_infos->rays[i].wall_hight / 2);
        init_calc(&calc, door_hieght, texture->width, var->bonus->door->width);
        x_img = calc_x_img(var, &calc, 'W');
        transparency = get_transparency(adjusted_distance);
        // render_sky(var, j, y, i);
        // printf("top %d buttom %d wall_h %d\n",y,x, var->p_infos->walls->wall_hight);
        draw_rectangle(var,texture, j, y, x, x_img, color, transparency, i);
        adjusted_distance = adjust_distance(var, i, 'D');
        door_hieght = (square_len / adjusted_distance) * var->p_infos->walls->distance_prj_plane;
        init_calc(&calc, door_hieght, texture->width, var->bonus->door->width);
       if(is_there_door(var->p_infos->rays[i].bonus_rays, var, i)){
            x_door = calc_x_img(var, &calc, 'D'); // door hieght to be calculated
       }
        // void draw_rect_door(t_main_s *var, t_text* text,int x, int top , int buttom, int x_door, int color, int transparency,int ray_nbr)
        y = ((var->window_height) / 2) - (door_hieght / 2);
        x = ((var->window_height) / 2) + (door_hieght / 2);
        draw_rect_door(var,texture, j, y, x, x_door, color, transparency, i);
        // draw_floor(var, j, x, i);

        i--;
        j++;
    }
    (void)x_img;
    free(var->p_infos->walls);
}