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


void fill_map(char **av,t_main_s *var)
{
    int fd;
    int maplen;
    char *line;
    int i = 0;

    maplen = 0;
    fd = open(av[1], O_RDONLY);
    if (fd < 0)
    {
        perror("path of the file is invalid !");
       return;
    }
    line  = get_next_line(fd);
    while (line)
    {
        if (maplen == 0)
            maplen++;
        free(line);
        line = get_next_line(fd);
        maplen ++;
    }
    close (fd);
    var->map = (char **)malloc(sizeof (char *) * (maplen + 1));
    if (!var->map)
        perror ("malloc failed !\n");
    fd = open(av[1], O_RDONLY);
    while (i < maplen)
    {
        var->map[i] = get_next_line(fd);
        i++;
    }
    var->map[i] = NULL;
    var->map_hight = ft_dstr_len(var->map);
    var->map_width = ft_strlen(var->map[0]) - 1;
}

int loop_hook(t_main_s *var)
{
    if (need_update(var->p_infos, var->map))
    {
        mlx_clear_window(var->mlx, var->mlx_win);
        var->img.img = mlx_new_image(var->mlx, (var->map_width *scale_of_minimap * square_len), (var->map_hight *scale_of_minimap * square_len));
        var->img.addr = mlx_get_data_addr(var->img.img, &var->img.bits_per_pixel, &var->img.line_length, &var->img.endian);
        var->img2.img = mlx_new_image(var->mlx, (var->map_width  * square_len), (var->map_hight * square_len));
        var->img2.addr = mlx_get_data_addr(var->img2.img, &var->img2.bits_per_pixel, &var->img2.line_length, &var->img2.endian);
        work_of_art(var);
        var->p_infos->move_up_down  = 0;
        var->p_infos->move_left_right  = 0;
        var->p_infos->turn_arround  = 0;
    }
    return 0;
}

int main(int ac, char **av)
{
    t_main_s *var;

    if (ac != 2)
        return (perror("need path of valid map\n"),1);
    var = init_main_var(av);
    work_of_art(var);
    mlx_hook(var->mlx_win, 2, 1L<<0, key_hook, var);
    mlx_loop_hook(var->mlx, loop_hook, var);
    mlx_loop(var->mlx); 
}