# include "../includes/ps.h"


double get_ideal_distance(t_main_s  *var, int i)
{
    double new_y, new_x;
    new_y = var->p_infos->rays[i].bonus_rays->obj->x_intersection / square_len;
    (void)new_x;
    (void)new_y;
    return 0.0;
}

void rays_check_for_obj(t_main_s *var)
{
    int i = 0;
    double inc_to_adj_dstc;
    int first, last, moy;
    first = -1;
    last = -1;

    while (i < var->p_infos->nbr_rays)
    {
        if (var->p_infos->rays[i].bonus_rays->hit_an_obj)
            first = i;
        if (!var->p_infos->rays[i].bonus_rays->hit_an_obj && first != -1)
            last = i;
        if (last != -1)
            break;
        i++;
    }
    if (last == -1)
    {
        moy = (last - first) / 2;
        inc_to_adj_dstc = get_ideal_distance(var, first) - var->p_infos->rays[moy].bonus_rays->obj->distance;
    }
    (void)inc_to_adj_dstc;
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





int hit_some(t_main_s *var, double xintersection, double yintersection)
{
    int x;
    int y;

    x = (int)floor(xintersection / square_len);
    y = (int)floor(yintersection / square_len);
    if (y < 0 || x < 0 || x >= var->map_hight || y > (int)ft_strlen(var->map[x]))
        return 1;
    if (var->map[x][y] == '1')
        return 1;
    if (var->map[x][y] == 'O')
        return 'O';
    if (var->map[x][y] == 'e')
        return 'e';
    return 0;
}


int get_color(t_main_s *var, t_text *img, int x, int y)
{
    int color;
    double x_off;
    double y_off;
    double x_img, y_img;

    x_off = (double)x / ((double)(var->window_width) * 0.5);
    y_off = (double)y / ((double)(var->window_height) * 0.6);
    x_img = x_off  * (double)(var->bonus->gun_in_hand[0]->width);
    y_img = y_off * (double)(var->bonus->gun_in_hand[0]->height); 
    color = img->pixels[(int)floor(y_img)][(int)floor(x_img)];
    return color;
}

void draw_crosshairs(t_main_s *var, int len ,int width, int color)
{
    int start_x;
    int start_y;
    int i;
    int j;

    j  = 0;
    i  = 0;
    start_x = (var->window_width / 2) - (len / 2);
    start_y = (var->window_height * 0.5) - (width / 2);
    while (i < len)
    {
        j =  0;
        while (j < width)
        {
            mlx_put_pixel(var->img2, start_x + i, start_y +  j, color);
            j++;
        }
        i++;
    }
    start_x = (var->window_width / 2) - (width / 2);
    start_y = (var->window_height * 0.5
    ) - (len / 2);
    i = 0;
    j = 0;
    while (i < width)
    {
        j = 0;
        while (j < len)
        {
            mlx_put_pixel(var->img2, start_x + i, start_y +  j, color);
            j++;
        }
        i++;
    }
}

void fps_hands_rendring(t_main_s *var)
{
    // int x;
    // int y;
    // int color;
    // x = 0;
    // y = 0;

    
    // while (x < (var->window_width * 0.5 ))
    // {
    //     y = 0;
    //     while (y < (var->window_height * 0.6))
    //     {
    //         color = get_color(var, var->bonus->gun_in_hand_text, x, y);
    //         if (color)
    //             mlx_put_pixel(var->img2, x + (var->window_width * 0.5)  , y + (var->window_height - (var->window_height * 0.6)) , color);
    //         y ++;
    //     }
    //     x++; 
    // }
    // mlx_image_to_window(var->mlx, var->bonus->gun_in_hands_img, var->window_width / 2, var->window_height / 2);
    // var->bonus->gun_in_hands_img->enabled = true;
    (void)var;
    }



void count_obj_enemi(t_main_s *var)
{
    int nbr_obj, nbr_enemies;
    int x, y;

    x = 0;
    y =0;
    nbr_enemies = 0;
    nbr_obj = 0;
    while (var->map[y])
    {
        x = 0;
        while (var->map[y][x])
        {
            if (var->map[y][x] == 'O')
                nbr_obj ++;
            if (var->map[y][x] == 'e')
                nbr_enemies ++;
            x++;
        }
        y++;
    }
    var->bonus->nbr_enemies = nbr_enemies;
    var->bonus->nbr_obj = nbr_obj;
}

