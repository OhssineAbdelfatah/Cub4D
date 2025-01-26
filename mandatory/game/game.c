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


int calcul_obj_height(t_main_s *var, int i)
{
    int res;
    (void)i;
    (void)var;
    res = 0;
    

    // res = (square_len / var->p_infos->rays[i].bonus_rays->obj->distance) * walls->distance_prj_plane;
    return res;
}

void obj_rebdering(t_main_s *var)
{
    int  i ;
    int obj_hieght;

    i  = var->p_infos->nbr_rays - 1;
    while (i >= 0)
    {
        if (var->p_infos->rays[i].bonus_rays->hit_an_obj)
        {
            obj_hieght = calcul_obj_height(var, i);
            // render_obj(var, obj_hieght, i);
        }
        i++;
    }
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
        var->p_infos=  init_player_struct(var->parse->dir, ((var->parse->pos->y_ver * square_len) + (square_len / 2)), ((var->parse->pos->x_hor * square_len) + (square_len / 2)));
    shoot_the_rays(var);
    draw_mini_map_42(var);
    wall_rendering(var);
    fps_hands_rendring(var);
    
    draw_crosshairs(var, 30, 2, 0x66FF33FF);

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