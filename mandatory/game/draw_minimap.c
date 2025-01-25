#include "../includes/ps.h"

int mini_map_check_wall(t_main_s *var, int x, int y)
{
    t_pos  mini_player;
    t_pos  dif;
    t_pos   square_to_check;
    t_pos   acttual_player;

    mini_player.x_hor = 3;
    mini_player.y_ver = 2;
    acttual_player.x_hor = floor(var->p_infos->x) / square_len;
    acttual_player.y_ver = floor(var->p_infos->y) / square_len;

    dif.x_hor = x - mini_player.x_hor;
    dif.y_ver = y - mini_player.y_ver;

    square_to_check.x_hor = acttual_player.y_ver + dif.x_hor;
    square_to_check.y_ver = acttual_player.x_hor + dif.y_ver;

    if (square_to_check.x_hor < 0 || square_to_check.y_ver < 0 )
        return -1;
    if (square_to_check.y_ver >= var->map_hight)
        return -1;
    if (square_to_check.x_hor >= (int)ft_strlen(var->map[square_to_check.y_ver]))
        return -1;
    if (var->map[square_to_check.y_ver][square_to_check.x_hor] == '1')
        return 1;
    if (var->map[square_to_check.y_ver][square_to_check.x_hor] == 32)
        return 2;
    if (var->map[square_to_check.y_ver][square_to_check.x_hor] == '\n')
        return 2;
    // if (var->map[square_to_check.x_hor][square_to_check.y_ver] == '1')
    //     return 1;
    return 0;
}

int draw_mini_map2(t_main_s *var)
{
    int i, j,x, y, check, new_y, new_x;
    // printf("height of  minimap:%d ,width : %d \n", var->mini_map->minimap_height, var->mini_map->minimap_width);
    paintit(var->mini_map->img3, 0x00E0E0E0, var->mini_map->minimap_height , var->mini_map->minimap_width);
    // draw_disk11(&var->mini_map->img3, var->mini_map->p_x, var->mini_map->p_y , player_radius, 0x000000FF);
    x = 0;
    y = 0;
    printf("py >> %d ,px %d \n", var->mini_map->p_y,var->mini_map->p_x);
    printf("py >> %f ,px %f \n", var->p_infos->y,var->p_infos->x);
    new_x  = var->mini_map->p_x + sin(var->p_infos->rotation_angle) * 15;
    new_y  = var->mini_map->p_y + cos(var->p_infos->rotation_angle) * 15;
    // draw_a_line2(var, var->mini_map->p_x , var->mini_map->p_y, new_x, new_y, 0x00F0FF,&var->mini_map->img3);
    while (x < 7)
    {
        while (y < 5)
        {
            check = mini_map_check_wall(var, x, y);
            if (1 == check)
                draw_square_for_mini(var->mini_map->img3, x * var->mini_map->mini_square_len, y * var->mini_map->mini_square_len, 0x000000FF);
            if (check == 0)
            {
                draw_square_for_mini(var->mini_map->img3, x * var->mini_map->mini_square_len, y * var->mini_map->mini_square_len, 0x00C0C0C0);
                // draw_empty_square_for_mini(&var->mini_map->img3, x * 40, y * 40);
            }
            y++;
        }
        y = 0;
        x++;
    }
    draw_disk11(var->mini_map->img3, var->mini_map->p_x, var->mini_map->p_y , player_radius, 0x000000FF);
    draw_a_line2(var, var->mini_map->p_x , var->mini_map->p_y, new_x, new_y, 0x00F0FF,var->mini_map->img3);
    (void)i;
    (void)j;
    return 0;
}

int draw_the_mini_map(t_main_s *var)
{
    int new_x, new_y;
    int x,y;

    x = 0;
    y = 0;
    if (var->map == NULL)
        return 1;
    while (var->map[x])
    {
        
        while (var->map[x][y] && var->map[x][y] != '\n')
        {
            // if (var->map[x][y] != '1')
            //     draw_empty_square(var, y* square_len * scale_of_minimap , x* square_len * scale_of_minimap);
            // else if (var->map[x][y] == '1')
            //     draw_square(var, y * square_len  * scale_of_minimap , x   * scale_of_minimap * square_len);
            if (var->map[x][y] != '1' && var->map[x][y] != '0' && var->map[x][y] !=  32)
            {
                printf("\nx :: %d,y :: %d \n", x, y);
                if (var->p_infos == NULL)
                    var->p_infos = init_player_struct(var->map[x][y], ((x  * square_len) + (square_len / 2)), ((y * square_len) + (square_len / 2)));
            }
            y++;
        }
        x++;
        y = 0;
    }
    new_x = (var->p_infos->x  * scale_of_minimap ) + cos(var->p_infos->rotation_angle) * 20;
    new_y = (var->p_infos->y  * scale_of_minimap) + sin(var->p_infos->rotation_angle) * 20;
    // draw_disk(var, (int)var->p_infos->y  * scale_of_minimap  , (int)var->p_infos->x * scale_of_minimap  , player_radius);
    // draw_a_line(var, var->p_infos->y * scale_of_minimap , var->p_infos->x * scale_of_minimap , new_y, new_x, 0xF0F000);
    (void)new_x;
    (void)new_y;
    return (0);
}



int is_there_a_wall(double new_y, double new_x, char **map)
{
    int x, y;

    x = new_x / (square_len);
    y = new_y / (square_len);
    if (map[y][x] != '1')
        return 0;
    return 1;
}

int one_of_the_four(double angle)
{
    if (fabs(angle - M_PI) < EPSILON)
        return UP;
    if (fabs(angle - (M_PI / 2)) < EPSILON)
        return RIGHT;
    if (fabs(angle - ((M_PI / 2) + M_PI)) < EPSILON)
        return LEFT;
    if (fabs(angle - (M_PI * 2)) < EPSILON)
        return DOWN;
    return NONE;
}

int direction(double angle)
{
    if (angle > M_PI / 2 && angle < M_PI) 
        return  UP_RIGHT;
    if (angle  > M_PI && angle < M_PI + (M_PI / 2))
        return UP_LEFT;
    if (angle >  M_PI + (M_PI / 2) && angle < 2 * M_PI )
        return DOWN_LEFT;

    if (angle > 0 && angle < M_PI / 2)
        return DOWN_RIGHT;
    return NONE;
}

int check_teleportation(t_player_infos *var, char **map)
{
    int dir;
    int check;

    check =0;
    dir = direction(var->rotation_angle);
    if (one_of_the_four(var->rotation_angle))
        return 0;
    if (dir == UP_RIGHT || dir == UP_LEFT)
        check =  is_there_a_wall(var->x - floor(var->move_up_down * 4), var->y, map);
    else if (dir == DOWN_LEFT || dir == DOWN_RIGHT)
        check =  is_there_a_wall(var->x + floor(var->move_up_down * 4), var->y , map);
    return check; 
}




void work_of_art(t_main_s *var)
{
    int color;
    
    color = create_trgb(255, var->parse->clr_c[0],var->parse->clr_c[1], var->parse->clr_c[2]); 
    paintit(var->img2,color,  (var->window_height) /2,  (var->window_width) );

    if (var->p_infos == NULL)
    {
        // printf("path[0], %s\n path[1] : %s\n", var->parse->tex_no, var->parse->tex_we);
        // printf("dir : %c, x : %d, y: %d ", var->parse->dir, var->parse->pos->x_hor, var->parse->pos->y_ver);
        var->p_infos=  init_player_struct(var->parse->dir, ((var->parse->pos->y_ver * square_len) + (square_len / 2)), ((var->parse->pos->x_hor * square_len) + (square_len / 2)));
    }
    // paintit(&var->img3,0x0F0FF00F,  (var->window_height * scale_of_minimap) / 2,  (var->window_width * scale_of_minimap) );
    
    shoot_the_rays(var);

    // var->text = mlx_load_png("assets/textures/zalij1.png");
    // printf("BPP>>>%d\n", var->text->bytes_per_pixel);
    
    
    wall_rendering(var);
    
    // printf("ray  dir : %c\n", var->p_infos->rays[var->p_infos->nbr_rays / 2].wall_dir);
    draw_mini_map_42(var);
    mlx_image_to_window(var->mlx, var->img2, 0, 0);
    // mlx_put_image_to_window(var->mlx, var->mlx_win, var->img2.img, 0, 0);

    // mlx_put_image_to_window(var->mlx, var->mlx_win, var->img.img, 0, 0);
    // mlx_image_to_window(var->mlx, var->img, 0, 0);

    
    // mlx_put_image_to_window(var->mlx, var->mlx_win, var->mini_map->img3.img, 0, 0);
    mlx_image_to_window(var->mlx, var->mini_map->img3, 0, 0);


    // mlx_put_image_to_window(var->mlx, var->mlx_win, alo.img, 0, 0);
    // mlx_put_image_to_window(var->mlx, var->mlx_win, var->mini_map->img3.img, 0, 0);
    // mlx_put_image_to_window(var->mlx, var->mlx_win, var->img3.img, var->window_width * scale_of_minimap, 0);
}