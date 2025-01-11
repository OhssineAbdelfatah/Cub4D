#include "../includes/ps.h"

t_player_infos *init_player_struct(char c, int x, int y)
{
    t_player_infos *var;
    var = malloc(sizeof(*var));
    if (!var)
        panic("malloc failed !\n");
    var->y =   y;
    var->x =   x;
    var->move_up_down = 0;
    var->move_left_right = 0;
    var->turn_arround = 0; 
    var->speed = 6;
    var->rotation_speed = (M_PI / 180) * 2;
    var->rays = NULL;
    var->nbr_rays = 0;
    var->fov = (M_PI / 180) * 60;
    if (c == 'N')
        var->rotation_angle = M_PI / 2; 
    if (c == 'S')
        var->rotation_angle = M_PI + (M_PI / 2);
    if (c == 'E')
        var->rotation_angle = M_PI ;
    if (c == 'W')
        var->rotation_angle = 0;
    return (var);
}

t_main_s *init_main_var(char **av)
{
    t_main_s *var;
    var = malloc(sizeof(*var));
    if (!var)
        panic("malloc failed !\n");
    var->p_infos = NULL;
    fill_map(av, var);
    var->mlx = mlx_init();
    var->mlx_win = mlx_new_window(var->mlx, (var->map_width  * square_len), (var->map_hight * square_len) , "cub3D");
    var->img.img = mlx_new_image(var->mlx, (var->map_width  * square_len * scale_of_minimap), (var->map_hight * scale_of_minimap * square_len));
    var->img.addr = mlx_get_data_addr(var->img.img, &var->img.bits_per_pixel, &var->img.line_length, &var->img.endian);
    var->img2.img = mlx_new_image(var->mlx, (var->map_width  * square_len), (var->map_hight * square_len));
    var->img2.addr = mlx_get_data_addr(var->img2.img, &var->img2.bits_per_pixel, &var->img2.line_length, &var->img2.endian);
    return var;
}

t_ray_info *init_rays(t_main_s *ptr, double ray_angle, double angle_incremet)
{
    int i = 0;
    t_ray_info *var;
    var = malloc(sizeof(*var) * ptr->p_infos->nbr_rays);
    if (!var)
        panic("malloc failed !\n");
    while (i <  ptr->p_infos->nbr_rays)
    {
        var[i].angle = 0;
        var[i].distance = 0;
        var[i].horzt_or_vert = 0;
        var[i].facing_left = false;
        var[i].facing_right = false;
        i++;
        ray_angle += angle_incremet; 
    }
    return var;
}

t_walls *init_walls(t_main_s *ptr)
{
    t_walls *var;

    var = malloc(sizeof(*var));
    if (!var)
        panic("malloc failed !\n");
    var->distance_prj_plane = ((ptr->map_width * square_len) / 2) / tan(ptr->p_infos->fov / 2);
    var->wall_hight = 0;
    return var;
}