# include "../includes/ps.h"


double get_distance(t_player_infos *p_var, int x, int y)
{
    double distance;
    double new_x;
    double new_y;

    printf("calculating ..\n");

    new_x = (double)((x * square_len ) + (square_len / 2));
    new_y = (double)((y * square_len ) + (square_len / 2));
    distance = sqrt(pow((p_var->y - new_y), 2) +  pow((p_var->x - new_x), 2));
    // distance = 0;
    (void)new_x;
    (void)new_y;
    // printf("x >>> %f\n", var->p_infos->x);
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
                obj[i].x = x;
                obj[i].y = y;
                obj[i].x_screen = 0;
                obj[i].y_screen = 0;
                obj[i].obj_height = 0;
                obj[i].obj_width = 0;
                obj[i].obj_teta = 0;
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
    // res->distance = 
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

void print_obj(t_obj *obj, int max)
{
    int i= 0;
    while (i < max)
    {
        printf("dis : %f , i : %d\n", obj[i].distance, i);
        i++;
    }
}



void update_obj_data(t_player_infos *p_var, t_obj *obj,int nbr_obj)
{
    int i =0;
   if (obj)
    {
        while (i < nbr_obj)
        {
            obj[i].distance = get_distance(p_var,obj[i].x, obj[i].y);
            i++;
        }
        adjust_rank(obj, nbr_obj);
        // adjust_visibility();
        printf(">>%f\n", obj->distance);
        print_obj(obj, nbr_obj);
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
    return (res);
}



