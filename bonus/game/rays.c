# include "../includes/ps.h"

void set_ray_direction(t_ray_info *var, double ray_angle)
{
    var->angle = ray_angle;
    if (ray_angle < M_PI)
    {
        var->facing_left = false;
        var->facing_right = true;
    }
    else
    {
        var->facing_left = true;
        var->facing_right = false;
    }
    if (ray_angle < (M_PI / 2) || ray_angle > M_PI + (M_PI / 2))
    {
        var->facing_up = false;
        var->facing_down = true;
    }
    else
    {
        var->facing_up = true;
        var->facing_down = false;
    }
}


void set_ray_infos(t_ray_info *ray, char which_one, t_x_and_y_d x_y, double distance)
{
    // ray->bonus_rays->door
    ray->distance = distance;
    ray->horzt_or_vert = which_one;
    ray->x_last_intersection = x_y.x;
    ray->y_last_intersection = x_y.y;
    if (which_one == 'h')
    {
        ray->wall_dir = 'S';
        if (ray->facing_up && which_one == 'h')
            ray->wall_dir = 'N';
    }
    if (which_one == 'v')
    {
        ray->wall_dir = 'W';
        if (ray->facing_right && which_one == 'v')
            ray->wall_dir = 'E';
    }
}


void cast_ray(t_main_s *var, int i)
{
    t_x_and_y_d v_xy_door;
    t_x_and_y_d h_xy_door;
 
    t_x_and_y_d v_xy;
    t_x_and_y_d h_xy;
    double distance1, distance2;
    distance1 = 0;
    distance2 = 0;

    v_xy_door.distance = 0;
    v_xy_door.x = 0;
    v_xy_door.y = 0;
    h_xy_door.distance = 0;
    h_xy_door.x = 0;
    h_xy_door.y = 0;
    if (fabs(var->p_infos->rays[i].angle - M_PI) < EPSILON || fabs(var->p_infos->rays[i].angle) < -EPSILON)
    {
        distance1 = cast_horizontally(var, i, &h_xy, &h_xy_door);
        set_ray_infos(&var->p_infos->rays[i],'h', h_xy, distance1 );
        var->p_infos->rays[i].bonus_rays->door->distance = h_xy_door.distance;
        var->p_infos->rays[i].bonus_rays->door->x_intersection = h_xy_door.y;
        var->p_infos->rays[i].bonus_rays->door->y_intersection = h_xy_door.x;
        return;
    }
    if (fabs(var->p_infos->rays[i].angle - M_PI / 2) < EPSILON || fabs(var->p_infos->rays[i].angle - (M_PI + M_PI / 2)) < EPSILON)
    {
        distance1 = cast_vertically(var, i, &v_xy, &v_xy_door);
        set_ray_infos(&var->p_infos->rays[i],'v', v_xy, distance1 );
        var->p_infos->rays[i].bonus_rays->door->distance = v_xy_door.distance;
        var->p_infos->rays[i].bonus_rays->door->x_intersection = v_xy_door.y;
        var->p_infos->rays[i].bonus_rays->door->y_intersection = v_xy_door.x;
        return;
    }
    distance1 = cast_horizontally(var, i, &h_xy,&h_xy_door);
    distance2 = cast_vertically(var, i, &v_xy, &v_xy_door);
    if (distance1 < distance2  || distance1 == distance2)
        set_ray_infos(&var->p_infos->rays[i],'h', h_xy, distance1 );
    else if (distance1 > distance2 )
        set_ray_infos(&var->p_infos->rays[i],'v', v_xy, distance2 );
        
    if (((h_xy_door.distance < v_xy_door.distance  || v_xy_door.distance == h_xy_door.distance) && h_xy_door.distance )){
        var->p_infos->rays[i].bonus_rays->door->from = 'p';
        var->p_infos->rays[i].bonus_rays->door->distance = h_xy_door.distance;
        var->p_infos->rays[i].bonus_rays->door->x_intersection = h_xy_door.y;
        var->p_infos->rays[i].bonus_rays->door->y_intersection = h_xy_door.x;
    }
    else if (h_xy_door.distance > v_xy_door.distance && v_xy_door.distance) {
        var->p_infos->rays[i].bonus_rays->door->from = 'v';
        var->p_infos->rays[i].bonus_rays->door->distance = v_xy_door.distance;
        var->p_infos->rays[i].bonus_rays->door->x_intersection = v_xy_door.y;
        var->p_infos->rays[i].bonus_rays->door->y_intersection = v_xy_door.x;
    }
    // compaire dis of door that is setted in the struct 
    /****/
}
void shoot_the_rays(t_main_s * var)
{
    double fov, angle_to_start, ray_angle_increment;
    double ray_angle;
    int i;

    i = 0;
    var->p_infos->nbr_rays  = var->window_width;
    fov = ( M_PI / 180) * 60;
    ray_angle_increment = fov / var->p_infos->nbr_rays;
    var->p_infos->nbr_rays = var->p_infos->nbr_rays;
    angle_to_start = var->p_infos->rotation_angle - (fov / 2);
    ray_angle = angle_to_start;
    ray_angle = adjust_angle(ray_angle);
    var->p_infos->rays =  init_rays(var, ray_angle, ray_angle_increment);
    while (i < var->p_infos->nbr_rays)
    {
        set_ray_direction(&var->p_infos->rays[i], ray_angle);
        cast_ray(var,  i);
        ray_angle += ray_angle_increment;
        ray_angle = adjust_angle(ray_angle);
        i++;
    }
}