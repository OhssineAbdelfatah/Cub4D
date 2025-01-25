#ifndef GAME_STRUCTS_H
#define GAME_STRUCTS_H

#include <stdbool.h>
#include "parsing.h"
#include "ps.h"
#include "../../lib/mlx/include/MLX42/MLX42.h"

typedef struct s_main_struct t_main_s;
typedef struct s_player_infos t_player_infos;
typedef struct	s_data t_data;
typedef struct s_test t_test;
typedef struct s_ray_info t_ray_info ;
typedef struct s_casting t_casting;
typedef struct s_walls_rendering t_walls;
typedef struct s_mini_map t_mini_map;
typedef struct s_textures_imgs t_textures_img;
typedef struct s_x_and_y_d t_x_and_y_d;
typedef struct s_bonus t_bonus;



/* TEXTURES */

typedef struct s_img t_img;
typedef struct s_text t_text;

struct s_img {
    double x_img;
    double y_img;
};

struct s_text {
    int **pixels;
    char* name;
    int width;
    int hieght;
};

int     create_trgb(int t, int r, int g, int b);
int     calc_x_img(int hor_or_ver, t_ray_info *ray, double wall_hiegt, double img_w);
int     calc_y_img(int y_proj ,int wall_hiegt , int img_h);
t_text  *get_images(mlx_texture_t* text);
int     gettt_rgba(uint8_t *color);


/***************************/

struct s_x_and_y_d
{
    double x;
    double y; 
};



struct s_bonus
{
    int mouse_x;
    mlx_texture_t *img;
    mlx_texture_t *door;
    mlx_texture_t *key;
    mlx_texture_t *gun_in_hand;
    // mlx_image_t *door;
};

struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
};

struct s_test
{
    int img_width;
    int img_hight;
    int img1_width;
    int img1_hight;
    void *mlx;
    void *win;
    t_data img;
    t_data img1;
};

struct s_mini_map
{
    int p_x;
    int p_y;
    int minimap_width;
    int minimap_height;
    int mini_square_len;
    // t_data img3;
    mlx_image_t *img3;
};


struct s_ray_info
{
    bool facing_up;
    bool facing_left;
    bool facing_right;
    bool facing_down;
    double x_last_intersection;
    double y_last_intersection;
    int x_hor;
    int y_ver;
    int horzt_or_vert;
    double distance;
    double angle;
    char wall_dir;
};

struct s_player_infos
{
    int pov;
    int move_up_down;
    int move_left_right;
    int turn_arround;
    int nbr_rays;
    double x;
    double y;
    double speed;
    double rotation_speed;
    double rotation_angle;
    double fov;
    t_ray_info *rays;
};

struct s_textures_imgs
{
    int height;
    int width;
    void *img_ver;
    void *img_hor;
};

struct s_main_struct
{
    int window_width;
    int window_height;
    int map_hight;
    int map_width;

    char **map;// eq alo.map
    mlx_t *mlx;
    void *img_ver;
    void *img_hor;
    mlx_image_t *img;
    mlx_image_t *img2;
    t_text **text;
    t_mini_map *mini_map;
    t_player_infos *p_infos;
    t_parse_data *parse;
    t_bonus *bonus;
    /***********/
    //bonus
    /***********/
  
};


struct s_casting
{
    double distance;
    double xsteps;
    double ysteps;
    double xintersection;
    double yintersection;
    double tan_angle;
};


struct s_walls_rendering
{
    double distance_prj_plane;
    double wall_hight;
};

#endif