# include "../includes/ps.h"

int key_hook(int key, t_main_s *ptr)
{
    (void)ptr;
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

int loop_hook(t_main_s *var)
{
    if (need_update(var->p_infos, var->map))
    {
        mlx_clear_window(var->mlx, var->mlx_win);
        var->img.img = mlx_new_image(var->mlx, (var->map_width *scale_of_minimap * square_len), (var->map_hight *scale_of_minimap * square_len));
        // var->img.img = mlx_new_image(var->mlx, (var->window_width * scale_of_minimap ), (var->window_height *scale_of_minimap));
        var->img.addr = mlx_get_data_addr(var->img.img, &var->img.bits_per_pixel, &var->img.line_length, &var->img.endian);
        
        var->img2.img = mlx_new_image(var->mlx, var->window_width, var->window_height);
        var->img2.addr = mlx_get_data_addr(var->img2.img, &var->img2.bits_per_pixel, &var->img2.line_length, &var->img2.endian);
        
        
        // var->img3.img = mlx_new_image(var->mlx, (var->window_width * scale_of_minimap), var->window_height * scale_of_minimap);
        // var->img3.addr = mlx_get_data_addr(var->img3.img, &var->img3.bits_per_pixel, &var->img3.line_length, &var->img3.endian);
        
        work_of_art(var);
        var->p_infos->move_up_down  = 0;
        var->p_infos->move_left_right  = 0;
        var->p_infos->turn_arround  = 0;
    }
    return 0;
}
void mlx_loops_and_hooks(t_main_s *var)
{
    mlx_hook(var->mlx_win, 2, 1L<<0, key_hook, var);
    mlx_loop_hook(var->mlx, loop_hook, var);
    mlx_loop(var->mlx); 
}