#include "../includes/ps.h"



t_walls *init_walls(t_main_s *ptr)
{
    t_walls *var;

    var = malloc(sizeof(*var));
    if (!var)
        panic("malloc failed !\n");
    var->distance_prj_plane = (ptr->window_width / 2) / tan(((M_PI / 180) * 60 )/ 2);
    var->wall_hight = 0;
    var->prj_plane_height = square_len / 2;
    return var;
}

t_ray_hit_obj *init_obj()
{
    t_ray_hit_obj *ret;

    ret  = (t_ray_hit_obj *)malloc(sizeof(t_ray_hit_obj));
    if (!ret)
        panic("malloc failed !\n");
    ret->distance = 0;
    ret->from = 0;
    ret->x_intersection = 0;
    ret->y_intersection = 0;
    return ret;
}

t_ray_hit_door *init_door()
{
    t_ray_hit_door *ret;

    ret  = (t_ray_hit_door *)malloc(sizeof(t_ray_hit_door));
    if (!ret)
        panic("malloc failed !\n");
    ret->distance = 0;
    ret->from = 0;
    ret->x_intersection = 0;
    ret->y_intersection = 0;
    return ret;
}

t_rays_bonus *init_bonus_rays()
{
    t_rays_bonus *ret;

    ret = (t_rays_bonus *)malloc(sizeof(t_rays_bonus));
    if (!ret)
        panic("malloc failed !\n");
    ret->hit_a_door = false;
    ret->hit_an_obj = false;
    ret->hit_an_enemy = false;
    ret->door = init_door();
    ret->enemy = NULL;
    ret->obj = init_obj();
    // ret->obj = init_obj();
    return ret;
}

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

t_player_infos *init_player_struct(t_main_s *ptr,char c, int x, int y)
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
    var->speed = 10;
    var->rotation_speed = (M_PI / 180) * 4;
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
    var->walls = init_walls(ptr);
    // var->walls = NULL;


    /******BONUS*****/
    var->jump_kneel = 0;
    var->look_up_down = 0;
    var->up_down_offset = 0;
    var->alive = true;
    var->health = 100;
    var->max_health = var->health;
    // printf("x >>> %f\n", var->p_infos->x);

    var->p_bonus = init_player_bonus(ptr, var);
    (void)ptr;
    return (var);
}


mlx_texture_t *safe_load(char *path)
{
    mlx_texture_t *img;

    img = mlx_load_png(path);
    if(!img)
    {
        ft_putstr_fd(path, 2);
        panic (" ,load png failed !\n");
    }
    return img ;
}

t_bonus *init_bonus(t_main_s *main)
{
    t_bonus *var;

    var = (t_bonus *)malloc(sizeof(t_bonus));
    if (!var)
        panic("malloc faild! \n");
    // var->gun_in_hand =  safe_load("../assets/textures/shoot1.png");
    var->gun_in_hand =  safe_load("../assets/textures/w0_b.png");
    var->floor = safe_load("../assets/floor/Brick/Brick_18-128x128.png");
    var->enemy_mlx_tex = safe_load("../assets/textures/AGAHA1.png");
    var->dead_enemy_mlx_tex = safe_load("../assets/textures/AGAHL0.png");
    var->enemy_text = get_image(var->enemy_mlx_tex);
    var->dead_enemy_text = get_image(var->dead_enemy_mlx_tex);
    // var->floor = safe_load("../assets/floor/Tile/Tile_14-128x128.png");
    // var->floor = safe_load("../assets/textures/2d.png");
    // var->sky = safe_load("../assets/textures/nightsky.png");
    var->sky = safe_load("../assets/sky/Fuzzy Sky/Fuzzy_Sky-Sunset_04-1024x512.png");
    var->door = NULL;
    var->img = NULL;
    var->key = NULL;
    var->mouse_x = (main->window_width) / 2;
    var->mouse_y = (main->window_height) / 2;
    var->gun_in_hand_text = get_image(var->gun_in_hand);
    var->floor_text = get_image(var->floor);
    var->sky_text = get_image(var->sky);
    printf("sky W :%d , sky H : %d\n",var->sky_text->width, var->sky_text->hieght );
    // var->pillar_tex = safe_load("../assets/textures/MBPKA0.png");
    // var->pillar_tex = safe_load("../assets/textures/Sprite-removebg.png");
    // var->pillar_tex = safe_load("../assets/textures/pilaar2.png");
    // var->pillar_tex = safe_load("../assets/textures/Wolf3Dfinalpillar.png");
    // var->pillar_tex = safe_load("../assets/textures/AGAHA1.png");
    // var->pillar_img = get_image(var->pillar_tex);
    var->pillar_tex = safe_load("../assets/textures/EHEDC0.png");
    // var->pillar_tex = safe_load("../assets/textures/EHEDA0.png");
    var->pillar_img = get_image(var->pillar_tex);
    var->gun_in_hands_img = mlx_texture_to_image(main->mlx, var->gun_in_hand);
    mlx_resize_image(var->gun_in_hands_img, main->window_width / 2, main->window_height / 2);
    // var->gun_in_hands_img->enabled= false;
    var->nbr_enemies = 0;
    var->nbr_obj = 0;
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
t_text **init_textures(t_main_s *var)
{
    t_text **text;
    mlx_texture_t *img;
    mlx_texture_t *img1;
    mlx_texture_t *img2;
    mlx_texture_t *img3;

    text = malloc(sizeof(t_text*) * 4);
    if(!text)
        panic("malloc failed !\n");
    // texture duplicate : mlx_texture_t => t_text
    // img = safe_load("./assets/textures/hitler.png");
    img = safe_load(var->parse->tex_no);
    text[0] = get_image(img);
    // img1 = safe_load("./assets/textures/ss.png");// aka north
    img1 = safe_load(var->parse->tex_ea);
    text[1] = get_image(img1);
    // img2 = safe_load("./assets/textures/brick.png");
    img2 = safe_load(var->parse->tex_so);
    text[2] = get_image(img2);
    // img3 = safe_load("./assets/textures/red_wall.png");
    img3 = safe_load(var->parse->tex_we);
    text[3] = get_image(img3);
    (void)var;
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
    // var->img = mlx_new_image(var->mlx, (10  * square_len * scale_of_minimap), (var->map_hight * scale_of_minimap * square_len));
   
    var->img2 = mlx_new_image(var->mlx, var->window_width, var->window_height);

    var->mini_map = init_mini_map(var->mlx, var->window_width, var->window_height);
    var->text = init_textures(var);

    var->bonus = init_bonus(var);
    var->start_frame = get_time_mil();
    // gettimeofday(&var->tv, NULL);
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
        var[i].bonus_rays = init_bonus_rays();
        // var[i].bonus_rays = NULL;
        i++;
        ray_angle += angle_incremet; 
    }
    return var;
}
