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

t_obj *init_obj_p(t_main_s *var, t_player_infos *p_var)
{
    t_obj *res;
    printf("%d\n", var->bonus->nbr_obj);
    if (var->bonus->nbr_obj == 0)
        return NULL;
    res = (t_obj *)malloc(sizeof(t_obj) * var->bonus->nbr_obj);
    if (!res)
        panic("malloc failed!\n");
    // while (i < )
    fill_obj(var, res, p_var);
    return res;
}



int is_sorted(t_obj *obj, int max)
{
    int i = 0;
    while (i < max)
    {
        if (i + 1 < max)
            if (obj[i].distance < obj[i + 1].distance)
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

void adjust_rank(t_obj *obj, int max)
{
    int i = 0;
    while (is_sorted(obj, max))
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

void print_obj(t_player_infos *p_var,t_obj *obj, int max)
{
    int i= 0;
    while (i < max)
    {
        printf("OBJ TETA : %f , i : %d\n", obj[i].vector_teta, i);
        // printf("obj x : %d , obj y : %d\n", obj[i].y * square_len + (square_len / 2), obj[i].x * square_len + (square_len / 2));
        printf("PLAYER  teta : %f \n", p_var->rotation_angle);
        i++;
    }
    (void)p_var;
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
    (void)obj;
    (void)i;
}

double calculate_obj_teta(t_player_infos *p_var, t_obj *obj)
{
    double obj_teta;

    (void)p_var;
    (void)obj;
    (void)obj_teta;
    return (0);
}

void update_obj_data(t_player_infos *p_var, t_obj *obj,int nbr_obj)
{
    int i =0;
   if (obj)
    {
        printf("/********************/\n");
        while (i < nbr_obj)
        {
            obj[i].distance = get_distance(p_var,obj[i].x, obj[i].y);
            obj[i].vector_x = p_var->y - obj[i].x;
            obj[i].vector_y = p_var->x - obj[i].y;
            obj[i].vector_teta = atan2(-obj[i].vector_y, obj[i].vector_x);
            obj[i].vector_teta = adjust_angle(obj[i].vector_teta  - (M_PI / 2));
            obj[i].obj_teta = calculate_obj_teta(p_var, &obj[i]);
            check_visibility(p_var, obj, i);
            i++;
        }
        adjust_rank(obj, nbr_obj);
        if (obj->visible)
            printf("it's visible\n");

        print_obj(p_var,obj, nbr_obj);
    } 
}

t_player_bonus *init_player_bonus(t_main_s *var, t_player_infos *p_var)
{
    t_player_bonus *res;

    res = (t_player_bonus *)malloc(sizeof(t_player_bonus));
    if (!res)
        panic("malloc failed!\n");
    count_obj_enemi(var);
    res->enemi = NULL;
    res->obj = init_obj_p(var, p_var);
    update_obj_data(p_var,res->obj, var->bonus->nbr_obj);
    printf("p_dir :: %f\n", p_var->rotation_angle);
    printf("atan of 1 , 0 : %f\n", atan2(1, 0));
    return (res);
}



