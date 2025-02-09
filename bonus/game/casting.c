# include "../includes/ps.h"
# include "stdio.h"


// double get_distance_obj(t_main_s *var, double x, double  y)
// {
//     double ret;
//     ret = sqrt(pow((x - var->p_infos->x), 2) + pow ((y - var->p_infos->y), 2));
//     return (ret);
// }

// int hit_an_obj(t_main_s *var, double xintersection, double yintersection, int i, int which)
// {
//     int x;
//     int y;

//     x = (int)floor(xintersection)/ square_len;
//     y = (int)floor(yintersection)/ square_len;
//     if (y < 0 || x < 0 || x >= var->map_hight || y > (int)ft_strlen(var->map[x]))
//         return 1;
//     if (var->map[x][y] == 'O')
//     {
//         // printf("alo its obj , ray : %d\n", i);
//         if(var->p_infos->rays[i].bonus_rays->obj->distance == 0)
//             var->p_infos->rays[i].bonus_rays->obj->distance = get_distance_obj(var, xintersection, yintersection);
//         var->p_infos->rays[i].bonus_rays->hit_an_obj = true;
//         var->p_infos->rays[i].bonus_rays->obj->from = which;
//         // if (i == 0)
//         //     printf("hited an obj hor\n");
//         // var->p_infos->rays[i].bonus_rays->obj->x_intersection = cst.xintersection;
//         // var->p_infos->rays[i].bonus_rays->obj->y_intersection = cst.yintersection;
//         return 1;
//     }
//     (void)i;
//     (void)which;
//     return 0;
// }

int hit_a_door(t_main_s *var, double xintersection, double yintersection, int i)
{
    int x;
    int y;

    x = (int)floor(xintersection / square_len);
    y = (int)floor(yintersection / square_len);
    if (y < 0 || x < 0 || x >= var->map_hight || y > (int)ft_strlen(var->map[x]))
        return 1;
    if (var->map[x][y] == 'D')
        return 1;
    (void)i;
    return 0;
}

int hit_a_wall(t_main_s *var, double xintersection, double yintersection, int i)
{
    int x;
    int y;

    x = (int)floor(xintersection / square_len);
    y = (int)floor(yintersection / square_len);
    if (y < 0 || x < 0 || x >= var->map_hight || y > (int)ft_strlen(var->map[x]))
        return 1;
    if (var->map[x][y] == '1')
        return 1;
    (void)i;
    return 0;
}

void init_cst_horiz(t_casting *cst, t_main_s *var, int i)
{
    double angle;

    angle =  var->p_infos->rays[i].angle + (M_PI /2.00);
    angle =  adjust_angle(angle);
    cst->tan_angle = tan(angle);
    cst->xintersection = floor(var->p_infos->x / floor(square_len)) * floor(square_len);
    if (var->p_infos->rays[i].facing_down)
        cst->xintersection += square_len;
    if (var->p_infos->rays[i].facing_right)
    {
        cst->yintersection = var->p_infos->y + ((var->p_infos->x - cst->xintersection)/cst->tan_angle);
    }
    else if (var->p_infos->rays[i].facing_left)
    {
        cst->yintersection = var->p_infos->y +  ((var->p_infos->x - cst->xintersection)  / cst->tan_angle);
    }
    cst->xsteps = square_len;
    cst->ysteps = cst->xsteps / cst->tan_angle;
    if (var->p_infos->rays[i].facing_down)
        cst->ysteps *= -1;
}

double cast_horizontally(t_main_s *var, int i, t_x_and_y_d *xy, t_x_and_y_d *h_xy_door)
{
    double up_down;
    t_casting cst;

    init_cst_horiz(&cst, var, i);
    if (0 == cst.tan_angle || cst.distance == -1)
        return (-1);
    up_down = 1;
    if (var->p_infos->rays[i].facing_up)
        up_down = -1;
    while (cst.xintersection >= 0 && cst.yintersection >= 0)
    {
        if (hit_a_door(var,cst.xintersection + up_down, cst.yintersection , i) && !var->p_infos->rays[i].bonus_rays->hit_a_door)
        {
            var->p_infos->rays[i].bonus_rays->hit_a_door = true;
            h_xy_door->y = cst.xintersection;
            h_xy_door->x = cst.yintersection;
            h_xy_door->distance = sqrt(pow((cst.xintersection - var->p_infos->x), 2) + pow ((cst.yintersection - var->p_infos->y), 2));
        }
        if (hit_a_wall(var,cst.xintersection + up_down, cst.yintersection , i))
        {
            xy->y = cst.xintersection;
            xy->x = cst.yintersection;
            break;
        }
        cst.xintersection += (cst.xsteps * up_down);
        cst.yintersection += cst.ysteps ;
    }
    cst.distance = sqrt(pow((cst.xintersection - var->p_infos->x), 2) + pow ((cst.yintersection - var->p_infos->y), 2));
    return cst.distance;    
}

void init_cst_vert(t_casting *cst, t_main_s *var, int i)
{
    double left_right;
    double angle;

    angle = var->p_infos->rays[i].angle - (M_PI / 2) ;
    angle  = adjust_angle(angle);
    cst->tan_angle = tan(angle);
    left_right = 1;
    if (var->p_infos->rays[i].facing_left)
        left_right = -1;
    cst->yintersection = floor(var->p_infos->y / square_len) * square_len;
    if (left_right == 1)
        cst->yintersection += square_len;
    if (var->p_infos->rays[i].facing_up)
            cst->xintersection =  var->p_infos->x - ((cst->yintersection - var->p_infos->y) * cst->tan_angle);
    else
        cst->xintersection = var->p_infos->x - (( cst->yintersection - var->p_infos->y ) * cst->tan_angle);
    cst->ysteps = square_len;
    cst->xsteps = cst->ysteps * cst->tan_angle;
    if (var->p_infos->rays[i].facing_left)
        cst->ysteps *= -1;
    else
        cst->xsteps *= -1;
}

double cast_vertically(t_main_s *var, int i, t_x_and_y_d *xy, t_x_and_y_d *v_xy_door)
{
    t_casting cst;
    double left_right;

    init_cst_vert(&cst, var, i);
    left_right = 1;
    if (var->p_infos->rays[i].facing_left)
        left_right = -1;
    while (cst.xintersection >= 0.00 && cst.yintersection >= 0.00)
    {
        if (hit_a_door(var,cst.xintersection , cst.yintersection + left_right , i) && !var->p_infos->rays[i].bonus_rays->hit_a_door)
        {
            var->p_infos->rays[i].bonus_rays->hit_a_door = true;
            v_xy_door->y = cst.xintersection;
            v_xy_door->x = cst.yintersection;
            v_xy_door->distance = sqrt(pow((cst.xintersection - var->p_infos->x), 2) + pow ((cst.yintersection - var->p_infos->y), 2));
        }
        if (hit_a_wall(var, cst.xintersection, cst.yintersection + left_right, i))
        {
            xy->y = cst.xintersection;
            xy->x = cst.yintersection;
            break;
        }
        cst.xintersection += cst.xsteps;
        cst.yintersection += cst.ysteps;

    }
    cst.distance = sqrt(pow((cst.xintersection - var->p_infos->x), 2) + pow(cst.yintersection  - var->p_infos->y , 2));
    return cst.distance;
}