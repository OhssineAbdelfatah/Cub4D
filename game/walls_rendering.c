#include "../includes/ps.h"

void draw_rectangle(t_main_s *var, int x, int y, int len, int width, int color)
{
    int j,i;
    
    i = 0;
    j = 0;
    while (i < width)
    {
        while (j < len)
        {
            my_mlx_pixel_put(&var->img2, x + i , y + j, color);
            j++;
        }
        j = 0;
        i ++;
    }
    (void)y;
    (void)x;
    (void)len;
    (void)var;
    (void)width;
}

double adjust_distance(t_main_s *var, int i)
{
    double teta_angle;
    double adjusted_distance ;


    teta_angle = var->p_infos->rays[i].angle - var->p_infos->rays[var->p_infos->nbr_rays / 2].angle;
    if (teta_angle < 0)
        teta_angle *= -1;
    adjusted_distance = cos(teta_angle) * var->p_infos->rays[i].distance;
    return adjusted_distance; 
}

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

int get_transparency(double distance)
{
    static int ss;
    int i, distance2;
    i = 0;
    distance2 = (int)floor(distance);
    while (i < distance2)
        i++;
    if (ss == 0)
    {
        printf("I >> %d\n", i);
        printf("%d dstance2 , distance %f\n", distance2, distance);
        ss++;
    }
    i /= 5;
    if (i > 255)
        i = 255;
    return (i);
}

void wall_rendering(t_main_s *var)
{
    t_walls *walls;
    double adjusted_distance;
    int color;
    int transparency;
    int y;
    int i;
    int j;
    int b;
    i = var->p_infos->nbr_rays-1;
    j = 0;
    walls = init_walls(var);
    while (i >= 0)
    {
        adjusted_distance = adjust_distance(var, i);
        walls->wall_hight = (square_len / adjusted_distance) * walls->distance_prj_plane;
        if (walls->wall_hight > var->map_hight * square_len)
            walls->wall_hight = var->map_hight * square_len;
        y = (var->map_hight * square_len) / 2 - (walls->wall_hight / 2);
        transparency = get_transparency(adjusted_distance);
        b = 255;
        if (var->p_infos->rays[i].horzt_or_vert == 'v')
            b =150;
        color = create_trgb(transparency, 51, 255, b);
        draw_rectangle(var, j, y, walls->wall_hight, 1,color);
        i--;
        j++;
    }
}

