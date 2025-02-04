# include "../includes/ps.h"

int get_color_enemy(t_main_s *var, int enemy_height, int enemy_width, int x, int y, int i)
{
    int color;
    double x_offset;
    double y_offset;

    int new_x, new_y;

    x_offset = (double)x / (double)enemy_width;
    y_offset = (double)y / (double)enemy_height;

    if (var->p_infos->p_bonus->enemy[i].alive)
    {
        new_x = (double)var->bonus->enemy_text->width * x_offset;
        new_y = (double)var->bonus->enemy_text->hieght * y_offset;
        color = var->bonus->enemy_text->pixels[(int)floor(new_y)][(int)floor(new_x)];
    }
    else
    {
        new_x = (double)var->bonus->dead_enemy_text->width * x_offset;
        new_y = (double)var->bonus->dead_enemy_text->hieght * y_offset;
        color = var->bonus->dead_enemy_text->pixels[(int)floor(new_y)][(int)floor(new_x)];
    }
    return color;
}

void render_enemy(t_main_s *var, t_player_bonus *ptr, t_walls *walls,int i)
{
    int x_start, x_end, y_start, y_end;
    int color;
    int x_increment = 0;
    int y_increment = 0;
    int ray_to_inspect;


    ptr->enemy[i].enemy_height = (square_len /  ptr->enemy[i].distance) * walls->distance_prj_plane;
    ptr->enemy[i].enemy_width = ptr->enemy[i].enemy_height;
    x_start = ptr->enemy[i].x_screen - (ptr->enemy[i].enemy_width / 2);
    y_start = ptr->enemy[i].y_screen - (ptr->enemy[i].enemy_height / 2);
    y_end = y_start + ptr->enemy[i].enemy_height;
    x_end = x_start + ptr->enemy[i].enemy_width;
    while (y_start < y_end)
    {
        if (y_start >= 0 && y_start < var->window_height)
        {
            x_increment = 0;
            while (x_start + x_increment < x_end)
            {
                ray_to_inspect = var->p_infos->nbr_rays - 1 - (x_increment + x_start);
                color = get_color_enemy(var, ptr->enemy[i].enemy_height, ptr->enemy[i].enemy_width, x_increment, y_increment, i);
                if (ray_to_inspect >=0 && ray_to_inspect < 1400 && var->p_infos->rays[ray_to_inspect].distance > ptr->enemy[i].distance)
                {
                    if (x_start + x_increment >= 0 && x_start + x_increment <  var->window_width && color)
                        mlx_put_pixel(var->img2, x_start + x_increment, y_start, color);
                }  
                x_increment++;
            }
        }
        y_increment++;
        y_start++;
    }    
}

void render_enemies(t_main_s *var, t_player_bonus *p_ptr)
{
    t_walls *walls;

    walls = init_walls(var);
    int i = 0;
    while (i < var->bonus->nbr_enemies)
    {
        render_enemy(var, p_ptr, walls,i);
        i++;
    }
    free(walls);
}

void damage_player(t_main_s *var, t_player_infos *player, t_enemy *enemy, int i)
{
    static int time_to_damage;
    int diff_x, diff_y;

    diff_y = abs((int)floor(enemy[i].vector_y));
    diff_x = abs( (int)floor(enemy[i].vector_x));
    if (diff_x <= square_len  && diff_y <= square_len && time_to_damage > 10)
    {
        time_to_damage = 0;
        player->health -= 10;
    }
    time_to_damage++;
    (void)var;
}

int check_for_walls(t_main_s *var,  t_player_infos *p_player, t_enemy *enemy, int i)
{
    double new_V_x, new_V_y, new_E_x, new_E_y;

    if (enemy[i].vector_x > 0)
            new_V_x = enemy[i].vector_x - (p_player->speed / 2) - (int)(enemy[i].enemy_width / 2);
    else
        new_V_x = enemy[i].vector_x + (p_player->speed / 2) + (int)(enemy[i].enemy_width / 2);
    new_E_x = p_player->y - new_V_x;

    if (enemy[i].vector_y > 0)
        new_V_y =  enemy[i].vector_y - (p_player->speed / 2) - (int)(enemy[i].enemy_width / 2);
    else
        new_V_y =  enemy[i].vector_y + (p_player->speed / 2) + (int)(enemy[i].enemy_width / 2);
    
    new_E_y =  p_player->x - new_V_y;
    if (hit_a_wall(var, new_E_y, new_E_x, 0))
        return 1;
    return 0;
}

void chase_player(t_main_s *var, t_player_infos *p_player, t_enemy *enemy, int i)
{ 
    int diff_x, diff_y;

    diff_y = abs((int)floor(enemy[i].vector_y));
    diff_x = abs( (int)floor(enemy[i].vector_x));
    damage_player(var, p_player, enemy, i);
    if (check_for_walls(var, p_player, enemy, i))
        return;
    if (diff_x > square_len)
    {
        if (enemy[i].vector_x > 0)
            enemy[i].vector_x -= (p_player->speed / 2);
        else
            enemy[i].vector_x += (p_player->speed / 2);
        enemy[i].x = p_player->y - enemy[i].vector_x;
    }
    if (diff_y > square_len)
    {
        if (enemy[i].vector_y > 0)
            enemy[i].vector_y -= (p_player->speed / 2);
        else
            enemy[i].vector_y += (p_player->speed / 2);
        
        enemy[i].y = p_player->x - enemy[i].vector_y;
    }
    enemy[i].distance =  get_distance(p_player,enemy[i].x, enemy[i].y);
    (void)var;
}
void update_enemy_data(t_main_s *var, t_player_infos *p_var, t_enemy *enemy,int nbr_enemy)
{
    // static int alo;
    int i;

    i = 0;
    if (enemy)
    {
        // printf("/********************/\n");
        while (i < nbr_enemy)
        {
            enemy[i].distance = get_distance(p_var,enemy[i].x, enemy[i].y);
            enemy[i].vector_x = p_var->y - enemy[i].x;
            enemy[i].vector_y = p_var->x - enemy[i].y;
            if (enemy[i].alive)
                chase_player(var, p_var, enemy, i);
            enemy[i].vector_teta = atan2(-enemy[i].vector_y, enemy[i].vector_x);
            enemy[i].vector_teta = adjust_angle(enemy[i].vector_teta  - (M_PI / 2));
            enemy[i].enemy_teta = calculate_obj_or_enemy_teta(p_var,NULL, &enemy[i]);
            enemy[i].x_screen = enemy[i].enemy_teta * (1400 / p_var->fov);
            enemy[i].y_screen = (var->window_height / 2) + var->p_infos->up_down_offset ;
            // printf("Vector teta : %f,enemy teta : %f, enemy x_screen : %d\n", enemy[i].vector_teta , enemy[i].enemy_teta, enemy[i].x_screen);
            i++;
        }
        adjust_rank_enemies(enemy, nbr_enemy);
        // print_obj(p_var,obj, nbr_obj);
    } 
}