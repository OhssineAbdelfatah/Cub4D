# include "../includes/ps.h"


double get_distance(t_player_infos *p_var, double x, double y)
{
    double distance;
    distance = sqrt(pow((p_var->y - x), 2) +  pow((p_var->x - y), 2));
    return (distance);
}

void fill_obj(t_main_s *var, t_obj *obj, t_player_infos *p_var)
{
    int x, y;
    int i;

    x = 0;
    y = 0;
    i = 0;
    while (var->map[y])
    {   
        x = 0;
        while (var->map[y][x])
        {
            if (var->map[y][x] == 'O')
            {
                obj[i].visible = false;
                obj[i].x = (double)(x * square_len) + (square_len / 2);
                obj[i].y = (double)(y * square_len) + (square_len / 2);
                obj[i].x_screen = 0;
                obj[i].y_screen = 0;
                obj[i].obj_height = 0;
                obj[i].obj_width = 0;
                obj[i].obj_teta = 0;
                obj[i].vector_teta = 0;
                obj[i].vector_x = 0;
                obj[i].vector_y = 0;
                obj[i].distance = get_distance(p_var,x, y);
                i++;
            }
            x ++;
        }
        y++;
    }
}

void fill_enemy(t_main_s *var, t_enemy *enemy, t_player_infos *p_var)
{
    int x, y;
    int i;

    x = 0;
    y = 0;
    i = 0;
    while (var->map[y])
    {   
        x = 0;
        while (var->map[y][x])
        {
            if (var->map[y][x] == 'e')
            {
                enemy[i].alive = true;
                enemy[i].x = (double)(x * square_len) + (square_len / 2);
                enemy[i].y = (double)(y * square_len) + (square_len / 2);
                enemy[i].x_screen = 0;
                enemy[i].y_screen = 0;
                enemy[i].enemy_height = 0;
                enemy[i].enemy_width = 0;
                enemy[i].enemy_teta = 0;
                enemy[i].vector_teta = 0;
                enemy[i].vector_x = 0;
                enemy[i].vector_y = 0;
                enemy[i].distance = get_distance(p_var,x, y);
                i++;
            }
            x ++;
        }
        y++;
    }
}

t_obj *init_obj_p(t_main_s *var, t_player_infos *p_var)
{
    t_obj *res;
    // printf("NBR _ OBJ : %d\n", var->bonus->nbr_obj);
    if (var->bonus->nbr_obj == 0)
        return NULL;
    res = (t_obj *)malloc(sizeof(t_obj) * var->bonus->nbr_obj);
    if (!res)
        panic("malloc failed!\n");
    fill_obj(var, res, p_var);
    return res;
}

t_enemy *init_enemies_p(t_main_s *var, t_player_infos *p_var)
{
    t_enemy *res;
    printf("NBR _ OBJ : %d\n", var->bonus->nbr_enemies);
    if (var->bonus->nbr_enemies == 0)
        return NULL;
    res = (t_enemy *)malloc(sizeof(t_enemy) * var->bonus->nbr_enemies);
    if (!res)
        panic("malloc failed!\n");
    fill_enemy(var, res, p_var);
    // (void)p_var;
    return res;
}



int is_sorted(t_obj *obj,t_enemy *enemy, int max)
{
    int i = 0;
    if (obj)
    {
        while (i < max)
        {
            if (i + 1 < max)
                if (obj[i].distance < obj[i + 1].distance)
                    return 1;
            i++;
        }
        return 0;
    }
    while (i < max)
    {
        if (i + 1 < max)
            if (enemy[i].distance < enemy[i + 1].distance)
                return 1;
        i++;
    }

    return 0;
}


void swap_obj(t_obj *one, t_obj *two)
{
    t_obj tmp;

    tmp = *one;
    *one = *two;
    *two  = tmp;
}
void swap_enemy(t_enemy *one, t_enemy *two)
{
    t_enemy tmp;

    tmp = *one;
    *one = *two;
    *two  = tmp;
}

void adjust_rank(t_obj *obj, int max)
{
    int i = 0;
    while (is_sorted(obj, NULL, max))
    {
        i = 0;
        while (i < max)
        {
            if (i + 1 < max)
            {
                if (obj[i].distance < obj[i + 1].distance)
                    swap_obj(&obj[i], &obj[i + 1]);
            }
            i++;
        }
    }
}


void adjust_rank_enemies(t_enemy *enemy, int max)
{
    int i = 0;
    while (is_sorted(NULL, enemy, max))
    {
        i = 0;
        while (i < max)
        {
            if (i + 1 < max)
            {
                if (enemy[i].distance < enemy[i + 1].distance)
                    swap_enemy(&enemy[i], &enemy[i + 1]);
            }
            i++;
        }
    }
}

void print_obj(t_player_infos *p_var,t_obj *obj, int max)
{
    int i= 0;
    while (i < max)
    {
        printf("VECTOR TETA : %f , OBJ TEAT : %f, i : %d\n", obj[i].vector_teta,obj[i].obj_teta, i);
        // printf("VECTOR TETA : %f , i : %d\n", obj[i].vector_teta, i);
        // printf("obj x : %d , obj y : %d\n", obj[i].y * square_len + (square_len / 2), obj[i].x * square_len + (square_len / 2));
        printf("PLAYER  teta : %f \n", p_var->rotation_angle);
        printf("OBJ SCREEN X : %d \n", obj->x_screen);
        i++;
    }
    (void)p_var;
    (void)obj;
}



void check_visibility(t_player_infos *p_var, t_obj *obj, int i)
{
    double max_fov, min_fov;

    min_fov = adjust_angle(p_var->rotation_angle  - (p_var->fov / 2));
    max_fov = adjust_angle(min_fov + p_var->fov);
    if (max_fov > min_fov)
        if (max_fov > obj[i].vector_teta &&  obj[i].vector_teta > min_fov)
            obj[i].visible = true;
        else
            obj[i].visible = false;
    else
        if (obj[i].vector_teta > min_fov || obj[i].vector_teta < max_fov)
            obj[i].visible = true;
        else
            obj[i].visible = false;
    // printf("MIN POV %f , MAX POV %f\n", min_fov, max_fov);
    (void)obj;
    (void)i;
}

double calculate_obj_or_enemy_teta(t_player_infos *p_var, t_obj *obj, t_enemy *enemy)
{
    double teta;

    if (!enemy)
    {
        teta = p_var->rotation_angle + (p_var->fov / 2) - obj->vector_teta;
        if (p_var->rotation_angle < (M_PI / 2) && obj->vector_teta > (M_PI + (M_PI /2)))
            teta += (2 * M_PI);
        if (p_var->rotation_angle > (M_PI + (M_PI /2)) && obj->vector_teta < (M_PI / 2))
            teta -= (2 * M_PI);
        return (teta);
    }
    teta = p_var->rotation_angle + (p_var->fov / 2) - enemy->vector_teta;
    if (p_var->rotation_angle < (M_PI / 2) && enemy->vector_teta > (M_PI + (M_PI /2)))
        teta += (2 * M_PI);
    if (p_var->rotation_angle > (M_PI + (M_PI /2)) && enemy->vector_teta < (M_PI / 2))
        teta -= (2 * M_PI);
    return (teta);

}

void update_obj_data(t_main_s *var, t_player_infos *p_var, t_obj *obj,int nbr_obj)
{
    int i;

    i = 0;
    if (obj)
    {
        // printf("/********************/\n");
        while (i < nbr_obj)
        {
            obj[i].distance = get_distance(p_var,obj[i].x, obj[i].y);
            obj[i].vector_x = p_var->y - obj[i].x;
            obj[i].vector_y = p_var->x - obj[i].y;
            obj[i].vector_teta = atan2(-obj[i].vector_y, obj[i].vector_x);
            obj[i].vector_teta = adjust_angle(obj[i].vector_teta  - (M_PI / 2));
            obj[i].obj_teta = calculate_obj_or_enemy_teta(p_var, &obj[i], NULL);
            check_visibility(p_var, obj, i);
            obj[i].x_screen = obj[i].obj_teta * (1400 / p_var->fov);
            obj[i].y_screen = (var->window_height / 2) + var->p_infos->up_down_offset ;
            // printf("Vector teta : %f,Obj teta : %f, obj x_screen : %d\n", obj[i].vector_teta , obj[i].obj_teta, obj[i].x_screen);
            i++;
        }
        adjust_rank(obj, nbr_obj);
        // print_obj(p_var,obj, nbr_obj);
    } 
}


t_player_bonus *init_player_bonus(t_main_s *var, t_player_infos *p_var)
{
    t_player_bonus *res;

    res = (t_player_bonus *)malloc(sizeof(t_player_bonus));
    if (!res)
        panic("malloc failed!\n");
    count_obj_enemi(var);
    res->enemy = init_enemies_p(var, p_var);
    res->obj = init_obj_p(var, p_var);
    // update_obj_data(var, p_var,res->obj, var->bonus->nbr_obj);
    return (res);
}



