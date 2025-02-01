
# include "../includes/ps.h"


void render_obj(t_main_s *var, t_player_bonus *ptr, t_walls *walls,int i)
{
    int obj_height, obj_width;
    int x_start, x_end, y_start, y_end;
    int color;
    int x_increment = 0;
    int y_increment = 0;
    int ray_to_inspect;

    obj_height = (square_len /  ptr->obj[i].distance) * walls->distance_prj_plane;
    obj_width = obj_height;

    x_start = ptr->obj[i].x_screen - (obj_width / 2);
    y_start = ptr->obj[i].y_screen - (obj_height / 2);

    y_end = y_start + obj_height;
    x_end = x_start + obj_width;
    while (y_start < y_end)
    {
        if (y_start >= 0 && y_start < var->window_height)
        {
            x_increment = 0;
            while (x_start + x_increment < x_end)
            {
                ray_to_inspect = var->p_infos->nbr_rays - 1 - (x_increment + x_start);
                color = get_color_obj(var, obj_height, obj_width, x_increment, y_increment);
                if (ray_to_inspect >=0 && ray_to_inspect < 1400 && var->p_infos->rays[ray_to_inspect].distance > ptr->obj[i].distance)
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
void render_objects(t_main_s *var, t_player_bonus *p_ptr)
{
    t_walls *walls;

    walls = init_walls(var);
    int i = 0;
    while (i < var->bonus->nbr_obj)
    {
        render_obj(var, p_ptr, walls,i);
        i++;
    }
    free(walls);
}