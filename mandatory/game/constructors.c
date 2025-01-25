#include "../includes/ps.h"

int **gat_pixles(mlx_texture_t* img, int w, int h)
{
    (void)img;
    int **pixs;
    int i;
    int j;

    i = 0 ;
    pixs = malloc(sizeof(int *) * h );
    if(!pixs)
        return (printf("malooc in pix int** failed")), NULL ;
    while(i < h )
    {
        j = 0 ;
        pixs[i] = (int *)malloc(sizeof(int) * w);
        if(!pixs)
            return (printf("malooc in pix int* failed")), NULL ;
        while(j < w )
        {
            pixs[i][j] = gettt_rgba( &img->pixels[((i * w) + j) * 4] );
            j++;
        }
        i++;
    }
    return pixs;
}


t_text *get_image(mlx_texture_t *text)
{
    int i = 0 ;
    i = 0 ;
    t_text *img;


    // mlx_image_t* img;

    img = malloc(sizeof(t_text));
    if(!img )
        return NULL;
    
    img[i].pixels = gat_pixles(text, text->width, text->height);
    img[i].hieght = text->height;
    img[i].width = text->width;
    return img;
}

t_player_infos *init_player_struct(char c, int x, int y)
{
    t_player_infos *var;
    var = malloc(sizeof(*var));
    if (!var)
        panic("malloc failed !\n");
    var->y =   y;
    var->x =   x;
    var->move_up_down = 0;
    var->move_left_right = 0;
    var->turn_arround = 0; 
    var->speed = 6;
    var->rotation_speed = (M_PI / 180) * 3;
    var->rays = NULL;
    var->nbr_rays = 0;
    var->fov = (M_PI / 180) * 60;
    if (c == 'E')
        var->rotation_angle = M_PI / 2; 
    if (c == 'W')
        var->rotation_angle = M_PI + (M_PI / 2);
    if (c == 'N')
        var->rotation_angle = M_PI ;
    if (c == 'S')
        var->rotation_angle = 0;
    return (var);
}


mlx_texture_t *safe_load(char *path)
{
    mlx_texture_t *img;

    img = mlx_load_png(path);
    if(!img)
    {
        ft_putstr_fd(path, 2);
        panic ("load png failed !\n");
    }
    return img ;
}

t_bonus *init_bonus(t_main_s *main)
{
    t_bonus *var;

    var = (t_bonus *)malloc(sizeof(t_bonus));
    if (!var)
        panic("malloc faild! \n");
    var->gun_in_hand =  safe_load("../assets/textures/shoot1.png");
    var->door = NULL;
    var->img = NULL;
    var->key = NULL;
    var->mouse_x = (main->window_width * square_len) / 2;
    return (var);
}

t_mini_map *init_mini_map(void *mlx, int width, int height)
{
    t_mini_map *var;

    var = malloc(sizeof(t_mini_map));
    if (!var)
        panic("malloc faild !\n");
    var->mini_square_len = 32;
    var->minimap_height = 32 * 5;
    var->minimap_width = 32 * 7;
    var->p_y = var->minimap_height / 2;
    var->p_x = var->minimap_width / 2;
    var->img3 = mlx_new_image(mlx, var->minimap_width, var->minimap_height);
    // var->img3.img = mlx_new_image(mlx, var->minimap_width, var->minimap_height);
    // var->img3.addr = mlx_get_data_addr(var->img3.img, &var->img3.bits_per_pixel, &var->img3.line_length, &var->img3.endian);
    (void)height;
    (void)width;
    return var;
}

/***
 * images stored in array in a strict order 
 * following real direction N -> E -> S -> W 
*/


void print_pixesl(t_text *img)
{
    int i ,j ;

    i = 0;
    while(i < img->hieght)
    {
        j= 0;
        while(j < img->width)
        {
            printf("pix[%d][%d] |%d|\n",i , j , img->pixels[i][j]);
            j++;
        }
        i++;
    }
}
t_text *init_textures(t_main_s *var)
{
    t_text *text;
    mlx_texture_t *img;

    text = malloc(sizeof(t_text) * 4);
    if(!text)
        panic("malloc failed !\n");
    // texture duplicate : mlx_texture_t => t_text
    printf("");
    img = safe_load(var->parse->tex_no);
    text[0] = *get_image(img);
    // print_pixesl(text);
    img = safe_load(var->parse->tex_ea);
    text[1] = *get_image(img);
    img = safe_load(var->parse->tex_so);
    text[2] = *get_image(img);
    img = safe_load(var->parse->tex_we);
    text[3] = *get_image(img);
    return text;
    // safe_load();
    // safe_load();
    // safe_load();
        
    // var->text.height = 64;
    // var->text.width = 64;
    // var->text.img_hor = mlx_xpm_file_to_image(var->mlx, "", &var->text.width, &var->text.height);
    // var->text.img_ver = mlx_xpm_file_to_image(var->mlx, "", &var->text.width, &var->text.height);
    // var->text.img_hor = NULL;
    // var->text.img_ver = NULL;
}



t_main_s *init_main_var(t_parse_data *parse)
{
    t_main_s *var;
    var = malloc(sizeof(*var));
    if (!var)
        panic("malloc failed !\n");
    var->window_height = 800;
    var->window_width = 1400;
    var->p_infos = NULL;
    var->parse = parse;
    var->map = parse->map;

    var->map_hight = ft_dstr_len(var->map);
    var->map_width = ft_strlen(var->map[0]);

    var->mlx = mlx_init(var->window_width,  var->window_height, "cub3D", false);
   
    var->img = mlx_new_image(var->mlx, (10  * square_len * scale_of_minimap), (var->map_hight * scale_of_minimap * square_len));
   
    var->img2 = mlx_new_image(var->mlx, var->window_width, var->window_height);

    var->mini_map = init_mini_map(var->mlx, var->window_width, var->window_height);
    var->text = init_textures(var);

    var->bonus = init_bonus(var);
    //  BONUS PART :: 
    // var->mouse_x = (var->window_width * square_len) / 2;
    // init_textures(var);
    return var;
}

t_ray_info *init_rays(t_main_s *ptr, double ray_angle, double angle_incremet)
{
    int i = 0;
    t_ray_info *var;
    var = malloc(sizeof(*var) * ptr->p_infos->nbr_rays);
    if (!var)
        panic("malloc failed !\n");
    while (i <  ptr->p_infos->nbr_rays)
    {
        var[i].angle = 0;
        var[i].distance = 0;
        var[i].horzt_or_vert = 0;
        var[i].facing_left = false;
        var[i].facing_right = false;
        var[i].x_last_intersection = 0;
        var[i].y_last_intersection = 0;
        var[i].wall_dir = 0;
        i++;
        ray_angle += angle_incremet; 
    }
    return var;
}

t_walls *init_walls(t_main_s *ptr)
{
    t_walls *var;

    var = malloc(sizeof(*var));
    if (!var)
        panic("malloc failed !\n");
    // var->distance_prj_plane = ((ptr->map_width * square_len) / 2) / tan(ptr->p_infos->fov / 2);
    var->distance_prj_plane = (ptr->window_width / 2) / tan(ptr->p_infos->fov / 2);
    var->wall_hight = 0;
    return var;
}