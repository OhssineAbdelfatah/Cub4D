# include "../includes/ps.h"


int need_update(t_player_infos * var, char **map)
{
    double move_steps, new_y, new_x, tmp_angle;
    int check;

    move_steps  = var->move_up_down * var->speed;
    if (var->move_up_down != 0 || var->turn_arround != 0 || var->move_left_right != 0)
    {
        var->rotation_angle += var->turn_arround * var->rotation_speed;
        var->rotation_angle = adjust_angle(var->rotation_angle);
        tmp_angle = var->rotation_angle;
        if (var->move_left_right)
        {
            move_steps  = var->move_left_right * var->speed;
            tmp_angle = adjust_angle(var->rotation_angle + (M_PI / 2));
        }
        new_x = var->x + cos(tmp_angle) * move_steps ;
        new_y = var->y + sin(tmp_angle) * move_steps ;
        if (var->move_left_right || var->move_up_down)
        {
            check = is_there_a_wall(new_x, new_y, map);
            if (!check)
            {
                check =  check_teleportation(var, map);
                if (check == 0)
                {
                    var->x = new_x;
                    var->y = new_y;
                }
            }
        }
        return 1;
    }
    return 0;
}

int key_hook(int key, t_main_s *ptr)
{
    if (key == ESC)
        exit(1);
    if (key == left_arrow)
        ptr->p_infos->turn_arround = 1;
    if (key == right_arrow)
        ptr->p_infos->turn_arround = -1;
    if (key == W)
        ptr->p_infos->move_up_down = 1;
    if (key == S)
        ptr->p_infos->move_up_down = -1;
    if (key == A)
        ptr->p_infos->move_left_right = 1;
    if (key == D)
        ptr->p_infos->move_left_right = -1;
    return 0;
}

void loop_hook(void *ptr)
{
    t_main_s *var;

    var = (t_main_s *)ptr;
    if (need_update(var->p_infos, var->map))
    {
        // mlx_destroy_image(var->mlx, var->mini_map->img3.img);
        // mlx_destroy_image(var->mlx, var->img.img);
        // mlx_destroy_image(var->mlx, var->img2.img);
        // mlx_clear_window(var->mlx, var->mlx_win);
        mlx_delete_image(var->mlx,var->img);
        mlx_delete_image(var->mlx,var->img2);
        mlx_delete_image(var->mlx,var->mini_map->img3);
        var->img = mlx_new_image(var->mlx, (var->map_width *scale_of_minimap * square_len), (var->map_hight *scale_of_minimap * square_len));
        // var->img.img = mlx_new_image(var->mlx, (var->map_width *scale_of_minimap * square_len), (var->map_hight *scale_of_minimap * square_len));
        // var->img.addr = mlx_get_data_addr(var->img.img, &var->img.bits_per_pixel, &var->img.line_length, &var->img.endian);
        
        var->img2 = mlx_new_image(var->mlx, var->window_width, var->window_height);
        // var->img2.img = mlx_new_image(var->mlx, var->window_width, var->window_height);
        // var->img2.addr = mlx_get_data_addr(var->img2.img, &var->img2.bits_per_pixel, &var->img2.line_length, &var->img2.endian);
        
        // var->mini_map->img3.img = mlx_new_image(var->mlx, 280, 200);
        var->mini_map->img3 = mlx_new_image(var->mlx, var->mini_map->minimap_width, var->mini_map->minimap_height);
        // var->mini_map->img3.img = mlx_new_image(var->mlx, var->mini_map->minimap_width, var->mini_map->minimap_height);
        // var->mini_map->img3.addr = mlx_get_data_addr(var->mini_map->img3.img, &var->mini_map->img3.bits_per_pixel, &var->mini_map->img3.line_length, &var->mini_map->img3.endian);
        
        work_of_art(var);
        var->p_infos->move_up_down  = 0;
        var->p_infos->move_left_right  = 0;
        var->p_infos->turn_arround  = 0;
    }
    // return NULL;
}
void mlx_loops_and_hooks(t_main_s *var)
{
    // mlx_hook(var->mlx_win, 2, 1L<<0, key_hook, var);
    mlx_loop_hook(var->mlx, loop_hook, var);
    mlx_loop(var->mlx); 
}