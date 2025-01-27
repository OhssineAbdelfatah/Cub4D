# include "../includes/ps.h"

int ft_dstr_len(char **av)
{
    int i = 0;

    if (!av)
        return 0;
    while (av[i])
        i++;
    return (i);
}


double calcul_obj_height(t_main_s *var, int i)
{
    double height;
    
    height = 0;
    height = (square_len / var->p_infos->rays[i].bonus_rays->obj->distance) * var->p_infos->walls->distance_prj_plane;
   
    (void)i;
    (void)var;
    return height;
}


double calc_obj_width(t_main_s *var)
{
    int i,first, last;
    double width;

    width = 0;
    i = var->p_infos->nbr_rays - 1;
    first = -1;
    last = -1;
    while (i >= 0)
    {
        if (var->p_infos->rays[i].bonus_rays->hit_an_obj == true)
        {
            if (first == -1)
                first = i;
            if ( i - 1 >= 0 && var->p_infos->rays[i - 1].bonus_rays->hit_an_obj == false)
                last = i ;

        }
        i--;
    }
    if (first != -1 && last == -1)
        last = 0;
    if (last != -1 && first != -1)
        width = first - last;
    return width;
}


int get_color_obj(t_main_s *var, int obj_height, int obj_width, int x, int y)
{
    int color;
    double x_offset;
    double y_offset;

    int new_x, new_y;

    x_offset = (double)x / (double)obj_width;
    y_offset = (double)y / (double)obj_height;

    new_x = (double)var->bonus->pillar_img->width * x_offset;
    new_y = (double)var->bonus->pillar_img->hieght * y_offset;

    color = var->bonus->pillar_img->pixels[(int)floor(new_y)][(int)floor(new_x)];
    return color;
}

void draw_rec_obj(t_main_s * var, int obj_height, int obj_width, int x, int x_to_cal_off)
{

    int start,i, bottom;
    // t_text *pillar_img;
    int color;

    i = 0;
    start = (var->window_height /2) - (obj_height /2);
    bottom = start + obj_height;
    if (x > var->window_width || x < 0)
        return;
    while (i < obj_height && i < var->window_height)
    {
        color = get_color_obj(var, obj_height, obj_width, x_to_cal_off, i);
        if (start + i > 0 && start + i < var->window_height)
        {
            if (color != 0)
            {
                mlx_put_pixel(var->img2,var->window_width - x, start + i, color);
                // if (x == 0)
                //     printf(">>>>>%d\n", color);
            }
        }
        i++;
    }
    // printf("\n");

    (void)bottom;
    (void)obj_height;
    (void)obj_width;
    (void)i;
}


void obj_rebdering(t_main_s *var)
{
    int  i ;
    int obj_hieght;
    int obj_width;
    int x_to_cal_off = 0;

    i  = var->p_infos->nbr_rays - 1;
    // i  = 0;
    obj_width = floor(calc_obj_width(var));
    // obj_width = floor(calc_obj_width(var));
    while (i >= 0)
    // while (i < var->p_infos->nbr_rays)
    {
        if (var->p_infos->rays[i].bonus_rays->hit_an_obj)
        {
            obj_hieght = floor(calcul_obj_height(var, i));
            // printf("%d  , ", obj_hieght);
            draw_rec_obj(var, obj_hieght, obj_width, i, x_to_cal_off);
            x_to_cal_off ++;
        }

        // i++;
        i--;
    }
    // printf("\n");

    (void) obj_hieght;
    (void) obj_width;
    (void) var;
}


void paint_floor_celling(t_main_s *var)
{
     int color;
    t_xy_i start, till;
     color = create_trgb(var->parse->clr_c[0],var->parse->clr_c[1], var->parse->clr_c[2], 255); 
    till.x = (var->window_width);
    till.y = (var->window_height) /2;
    start.x = 0;
    start.y = 0;
    paintit(var->img2,color,  &start, &till );
    start.y = var->window_height / 2;
    color = create_trgb(var->parse->clr_f[0],var->parse->clr_c[1], var->parse->clr_c[2], 255); 
    paintit(var->img2, color, &start, &till);
}


void work_of_art(t_main_s *var)
{    
    paint_floor_celling(var);
    if (var->p_infos == NULL)
        var->p_infos=  init_player_struct(var , var->parse->dir, ((var->parse->pos->y_ver * square_len) + (square_len / 2)), ((var->parse->pos->x_hor * square_len) + (square_len / 2)));
    shoot_the_rays(var);
    draw_mini_map_42(var);
    wall_rendering(var);
    obj_rebdering(var);

    //here  i call the function so i can get only the width of the img:
   
   
    // calc_obj_width(var);
    fps_hands_rendring(var);
    
    draw_crosshairs(var, 30, 2, 0x66FF33FF);
    free_rays(var);
    mlx_image_to_window(var->mlx, var->img2, 0, 0);
    mlx_image_to_window(var->mlx, var->mini_map->img3, 10, 10);


    // mlx_put_image_to_window(var->mlx, var->mlx_win, alo.img, 0, 0);
    // mlx_put_image_to_window(var->mlx, var->mlx_win, var->mini_map->img3.img, 0, 0);
    // mlx_put_image_to_window(var->mlx, var->mlx_win, var->img3.img, var->window_width * scale_of_minimap, 0);
}






// void	ff(void)
// {
// 	system("leaks -q cub3D ");
// }

    /*
        replace  with parse

            if (ac != 2)
                return (perror("need path of valid map\n"),1);
                
        t_parse_data *data;
        data = parse(ac, av)
    */

// int main(int ac, char **av)
// {
//     t_main_s *var;
//     // atexit(ff);
//     if (ac != 2)
//         return (perror("need path of valid map\n"),1);
//     var = init_main_var(av);
//     work_of_art(var);
//     mlx_loops_and_hooks(var);
// }