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

// int key_hook(int key, t_main_s *ptr)
// {
//     printf(">>>>%d \n", key);
//     if (key == ESC)
//         exit(1);
//     if (key == left_arrow)
//         ptr->p_infos->turn_arround = 1;
//     if (key == right_arrow)
//         ptr->p_infos->turn_arround = -1;
//     if (key == W)
//         ptr->p_infos->move_up_down = 1;
//     if (key == S)
//         ptr->p_infos->move_up_down = -1;
//     if (key == A)
//         ptr->p_infos->move_left_right = 1;
//     if (key == D)
//         ptr->p_infos->move_left_right = -1;
//     return 0;
// }

void key_hook(mlx_key_data_t key, void *var)
{
    t_main_s *ptr;

    ptr = (t_main_s *)var;
    if (key.key == MLX_KEY_ESCAPE)
        exit(1);
    if (key.key == left_arrow)
        ptr->p_infos->turn_arround = 1;
    if (key.key == right_arrow)
        ptr->p_infos->turn_arround = -1;
    if (key.key == W)
        ptr->p_infos->move_up_down = 1;
    if (key.key == S)
        ptr->p_infos->move_up_down = -1;
    if (key.key == A)
        ptr->p_infos->move_left_right = 1;
    if (key.key == D)
        ptr->p_infos->move_left_right = -1;
}

void loop_hook(void *ptr)
{
    t_main_s *var;

    var = (t_main_s *)ptr;
    if (need_update(var->p_infos, var->map))
    {
        mlx_delete_image(var->mlx,var->img);
        mlx_delete_image(var->mlx,var->img2);
        mlx_delete_image(var->mlx,var->mini_map->img3);
       
        var->img = mlx_new_image(var->mlx, (var->map_width *scale_of_minimap * square_len), (var->map_hight *scale_of_minimap * square_len));
        
        var->img2 = mlx_new_image(var->mlx, var->window_width, var->window_height);
        
        var->mini_map->img3 = mlx_new_image(var->mlx, var->mini_map->minimap_width, var->mini_map->minimap_height);
        work_of_art(var);
        var->p_infos->move_up_down  = 0;
        var->p_infos->move_left_right  = 0;
        var->p_infos->turn_arround  = 0;
    }
}
void mlx_loops_and_hooks(t_main_s *var)
{
    mlx_key_hook(var->mlx, key_hook, var);
    // mlx_hook(var->mlx_win, 2, 1L<<0, key_hook, var);
    mlx_loop_hook(var->mlx, loop_hook, var);
    mlx_loop(var->mlx); 
}