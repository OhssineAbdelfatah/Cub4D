#include "../includes/ps.h"

int draw_the_map(t_main_s *var)
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
            if (var->map[x][y] != '1')
                draw_empty_square(var, y* square_len * scale_of_minimap , x* square_len * scale_of_minimap);
            else if (var->map[x][y] == '1')
                draw_square(var, y * square_len  * scale_of_minimap , x   * scale_of_minimap * square_len);
            if (var->map[x][y] != '1' && var->map[x][y] != '0')
            {
                if (var->p_infos == NULL)
                    var->p_infos = init_player_struct(var->map[x][y], ((x  * square_len) + (square_len / 2)), ((y * square_len) + (square_len / 2)));
            }
            y++;
        }
        x++;
        y = 0;
    }
    new_x = (var->p_infos->x  * scale_of_minimap ) + cos(var->p_infos->rotation_angle) * 10;
    new_y = (var->p_infos->y  * scale_of_minimap) + sin(var->p_infos->rotation_angle) * 10;
    draw_disk(var, (int)var->p_infos->y  * scale_of_minimap  , (int)var->p_infos->x * scale_of_minimap  , player_radius);
    draw_a_line(var, var->p_infos->y * scale_of_minimap , var->p_infos->x * scale_of_minimap , new_y, new_x, 0xF0F000);
    (void)new_x;
    (void)new_y;
    return (0);
}



int is_there_a_wall(double new_y, double new_x, char **map)
{
    int x, y;

    x = new_x /( square_len   );
    y = new_y / (square_len   );
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
    
    dir = direction(var->rotation_angle);
    if (one_of_the_four(var->rotation_angle))
        return 0;
    if (dir == UP_RIGHT || dir == UP_LEFT)
        return is_there_a_wall(var->x - floor(var->move_up_down * 2), var->y, map);
    if (dir == DOWN_LEFT || dir == DOWN_RIGHT)
        return is_there_a_wall(var->x + floor(var->move_up_down * 2), var->y , map);
    return 0; 
}

int need_update(t_player_infos * var, char **map)
{
    double move_steps, new_y, new_x, tmp_angle;

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
        if (!is_there_a_wall(new_x, new_y, map) && !check_teleportation(var, map))
        {
            var->x = new_x;
            var->y = new_y;
        }
        return 1;
    }
    return 0;
}

void work_of_art(t_main_s *var)
{
    paintit(&var->img2,0x0F0FF00F,  (var->map_hight  * square_len) /2,  (var->map_width  * square_len) );
    // paintit(&var->img2,0x0F0FF00F,  (var->map_hight  * square_len),  (var->map_width  * square_len));
    draw_the_map(var);
    shoot_the_rays(var);
    wall_rendering(var);
    mlx_put_image_to_window(var->mlx, var->mlx_win, var->img2.img, 0, 0);
    mlx_put_image_to_window(var->mlx, var->mlx_win, var->img.img, 0, 0);
}