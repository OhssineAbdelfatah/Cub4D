# include "../includes/ps.h"


int need_update(t_main_s *main, t_player_infos * var, char **map)
{
    int check;
    double move_steps;
    double new_y;
    double new_x;
    double tmp_angle;

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
            check = is_there_a_wall(new_x + ( 4 * (new_x - var->x)) , new_y + ( 4 * (new_y - var->y)), map);
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
    if ( var->look_up_down|| var->jump_kneel )
    {
        // printf("look_up_down :: %d \n", var->look_up_down);
        if (var->look_up_down == 1)
            if (var->up_down_offset < (main->window_height / 3))
                var->up_down_offset += var->speed * var->look_up_down * 2;
        if (var->look_up_down == -1)
            if (var->up_down_offset > ( main->window_height / 3) * -1)
                var->up_down_offset += var->speed  * var->look_up_down * 2 ;

        var->jump_kneel = 0;
        
        return 1;
    }
    return 0;
}

void smooth_exit(t_main_s *var)
{
    // int i = 0;
    // if (var->p_infos->rays->bonus_rays)
    //     free_rays_bonus()
    free(var->p_infos);
    free(var->mlx);
    free(var->parse);
    free(var->bonus);
    // (void)var;
}


void key_hook(mlx_key_data_t key, void *var)
{
    t_main_s *ptr;

    ptr = (t_main_s *)var;
    if (key.key == MLX_KEY_ESCAPE)
    {
        // smooth_exit(var);
        exit(0);
    }
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
    // if (key.key == MLX_KEY_SPACE)
    //     ptr->p_infos->jump_kneel = 1;
    // if (key.key == MLX_KEY_LEFT_CONTROL)
    //     ptr->p_infos->jump_kneel = -1;
    if (key.key == MLX_KEY_UP)
        ptr->p_infos->look_up_down = 1;
    if (key.key == MLX_KEY_DOWN)
        ptr->p_infos->look_up_down = -1;
}
long long	get_time_mil(void)
{
	long long	res;
	t_time		tp;

	gettimeofday(&tp, NULL);
	res = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	return (res);
}


int check_player_health(t_main_s *var)
{
    if (var->p_infos->health <= 0)
    {
        var->p_infos->alive = false;
        mlx_put_string(var->mlx, "GAME OVER", var->window_width / 2, var->window_height / 2);
        return 1;
    }
    return 0;
}

void loop_hook(void *ptr)
{
    t_main_s *var;
    // static t_time tv;
    long long now;

    var = (t_main_s *)ptr;
    now = get_time_mil();
    if (check_player_health(var))
        return;
    if (need_update(var,  var->p_infos, var->map))
    {
        // mlx_delete_image(var->mlx,var->img);
        // // var->img = mlx_new_image(var->mlx, (var->map_width *scale_of_minimap * square_len), (var->map_hight *scale_of_minimap * square_len));
        
        // mlx_delete_image(var->mlx,var->img2);
        // mlx_delete_image(var->mlx,var->mini_map->img3);
        // var->img2 = mlx_new_image(var->mlx, var->window_width, var->window_height);
        // var->mini_map->img3 = mlx_new_image(var->mlx, var->mini_map->minimap_width, var->mini_map->minimap_height);
        work_of_art(var, 1);
        var->p_infos->move_up_down  = 0;
        var->p_infos->move_left_right  = 0;
        var->p_infos->turn_arround  = 0;
        var->p_infos->look_up_down  = 0;
    }                           
    else if (now - var->start_frame > 40)
    {
        var->start_frame = now;
        work_of_art (var, 0);
    }
    
    (void)var;
    (void)now;
    (void)ptr;
}

void display_shooting(t_main_s *var)
{
    
    (void)var;
}

void shoot_them_mfs(t_main_s *var)
{

    int max_range, min_range;
    int i = var->bonus->nbr_enemies - 1;
    display_shooting(var);
    max_range =(var->window_width / 2) + 20;
    min_range =(var->window_width / 2) - 20;
    while (i >= 0)
    {
        if (var->p_infos->p_bonus->enemy[i].x_screen > min_range && var->p_infos->p_bonus->enemy[i].x_screen < max_range)
        {
            if (abs(var->p_infos->up_down_offset) <= 10)
            {
                var->p_infos->p_bonus->enemy[i].alive = false;
                    return;
            }
        }
        i--;
    }
}

void mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods, void *param)
{
    t_main_s *var;
    // int new_x, new_y;

    var = (t_main_s *)param;

    if (button == 0)
        shoot_them_mfs(var);   
    (void)button;
    (void)action;
    (void)mods;
    (void)var;
    // printf()
}


void cursor_func(double xpos, double ypos, void* param)
{
    t_main_s *var;
    int the_origin_x, the_origin_y;
   
    var = (t_main_s *)param;
    the_origin_x = var->bonus->mouse_x;
    the_origin_y = var->bonus->mouse_y;
    if (xpos < the_origin_x - 5)
        var->p_infos->turn_arround = 1;
    else if (xpos > the_origin_x + 5)
        var->p_infos->turn_arround = -1;
    var->bonus->mouse_x = xpos;
    if (xpos < 0 || xpos > var->window_width)
        var->bonus->mouse_x = var->window_width /2;
   
   
   
    if (ypos < the_origin_y - 5)
        var->p_infos->look_up_down = 1;
    else if (ypos > the_origin_y + 5)
        var->p_infos->look_up_down = -1;
    var->bonus->mouse_y = ypos;
    if (ypos < 0 || ypos > var->window_height)
        var->bonus->mouse_y = var->window_height /2;
    (void)ypos;
}

void mlx_loops_and_hooks(t_main_s *var)
{
    mlx_key_hook(var->mlx, key_hook, var);
    // mlx_hook(var->mlx_win, 2, 1L<<0, key_hook, var);

    mlx_mouse_hook(var->mlx, mouse_hook, var);

    // mlx_cursor_hook(var->mlx, cursor_func, var);
    mlx_loop_hook(var->mlx, loop_hook, var);
    mlx_loop(var->mlx); 
}