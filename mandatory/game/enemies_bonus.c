# include "../includes/ps.h"

int get_color_enemy(t_main_s *var, int enemy_height, int enemy_width, int x, int y)
{
    int color;
    double x_offset;
    double y_offset;

    int new_x, new_y;

    x_offset = (double)x / (double)enemy_width;
    y_offset = (double)y / (double)enemy_height;

    new_x = (double)var->bonus->enemy_text->width * x_offset;
    new_y = (double)var->bonus->enemy_text->hieght * y_offset;

    color = var->bonus->enemy_text->pixels[(int)floor(new_y)][(int)floor(new_x)];
    return color;
}

void render_enemy(t_main_s *var, t_player_bonus *ptr, t_walls *walls,int i)
{
    int enemy_height, enemy_width;
    int x_start, x_end, y_start, y_end;
    int color;
    int x_increment = 0;
    int y_increment = 0;
    int ray_to_inspect;

    enemy_height = (square_len /  ptr->enemy[i].distance) * walls->distance_prj_plane;
    enemy_width = enemy_height;
    x_start = ptr->enemy[i].x_screen - (enemy_width / 2);
    y_start = ptr->enemy[i].y_screen - (enemy_height / 2);

    y_end = y_start + enemy_height;
    x_end = x_start + enemy_width;
    while (y_start < y_end)
    {
        if (y_start >= 0 && y_start < var->window_height)
        {
            x_increment = 0;
            while (x_start + x_increment < x_end)
            {
                ray_to_inspect = var->p_infos->nbr_rays - 1 - (x_increment + x_start);
                color = get_color_enemy(var, enemy_height, enemy_width, x_increment, y_increment);
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
    // printf("vector x : %f ,vector Y: %f\n", p_ptr->enemy->vector_x, p_ptr->enemy->vector_y);
    free(walls);
}



void chase_player(t_main_s *var, t_player_infos *p_player, t_enemy *enemy, int i)
{ 
    if (abs((int)enemy[i].vector_x) > square_len)
    {
        if (enemy[i].vector_x > 0)
            enemy[i].vector_x -= (p_player->speed / 2);
        else
            enemy[i].vector_x += (p_player->speed / 2);
        enemy[i].x = p_player->y - enemy[i].vector_x;
    }
    if (abs((int)enemy[i].vector_y) > square_len)
    {
        if (enemy[i].vector_y > 0)
            enemy[i].vector_y -= (p_player->speed / 6);
        else
            enemy[i].vector_y += (p_player->speed / 6);
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
            // if (0 == alo)
            // {
            //     printf("/*****************************************/\n");
            //     printf("ex : %f , ey : %f\n", enemy[i].x, enemy[i].y );
            //     printf("px : %f , py : %f\n", p_var->x, p_var->y );
            //     printf("vx : %f , Vy : %f\n", enemy[i].vector_x, enemy[i].vector_y );
            //     alo ++;
            // }
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