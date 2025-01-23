#include"../includes/ps.h"
#include"math.h"


// inter[0] => x_inter
// inter[1] => y_inter
int calc_x_img(int hor_or_ver, t_ray_info *ray, double wall_hiegt, double img_w)
{
    double x_img;
    double a;

    x_img = 0;
    if(hor_or_ver == 'h')
    {
        a = ray->x_last_intersection / (double)wall_hiegt;
        // printf("---------Xinter [%f]\n", a);
        x_img = (a) - floor(a);
    }
    else if(hor_or_ver == 'v')
    {
        a = ray->y_last_intersection / (double)wall_hiegt;
        x_img = (a) - floor(a);
        // printf("---------Yinter [%f]\n", x_img);
    }
    return (int)(x_img * img_w);
}

int calc_y_img(int y_proj ,int wall_hiegt , int img_h)
{
    double y_img;
    double y_prc;
    y_prc = (double)y_proj / (double)wall_hiegt;
    y_img = y_prc * img_h;
    return (int)y_img;
}


int	create_trgb(int t, int r, int g, int b)
{
	return (r << 24 | g << 16 | b << 8 | t);
}

/***
 * images stored in array in a strict order 
 * following real direction N -> E -> S -> W 
*/

// int	gettt_rgba(uint8_t *color)
// {
// 	return (color[0] << 24 | color[1] << 16 | color[2] << 8 | color[3]);
// }

int **gat_pixles(mlx_texture_t* img, int w, int h)
{
    (void)img;
    int **pixs;
    int i;
    int j;

    i = 0 ;
    pixs = malloc(sizeof(int *) * h);
    if(pixs)
        return NULL ;
    while(i < h)
    {
        j = 0 ;
        while(j < w)
        {
            pixs[i] = (int *)malloc(sizeof(int) * w);
            if(pixs)
                return NULL ;
            // pixs[i][j] = gettt_rgba( &img->pixels[(i * w + j) * 4] );
            j++;
        }
        i++;
    }
    return pixs;
}
t_text *get_images( t_main_s *var)
{
    int i = 0 ;
    i = 0 ;
    t_text *text;


    // mlx_image_t* img;

    text = malloc(sizeof(t_text));
    if(!text )
        return NULL;
    // exit(0);
    // img = mlx_texture_to_image(mlx, tmp);
    // while(i < 4)
    // {
        // mlx_delete_texture(tmp);
        text[i].pixels = gat_pixles(var->text, var->text->width, var->text->height);
        text[i].hieght = var->text->height;
        text[i].width = var->text->width;
        // mlx_delete_image(mlx, img);
        // i++;
    // }
    return text;
}