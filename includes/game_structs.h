#ifndef GAME_STRUCTS_H
#define GAME_STRUCTS_H

#include <stdbool.h>
#include "../lib/mlx/include/MLX42/MLX42.h"

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

struct s_x_and_y_d
{
    double x;
    double y; 
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
    int mouse_x;
    char **map;
    mlx_t *mlx;
    // void *mlx;
    void *mlx_win;
    void *img_ver;
    void *img_hor;
    // t_data img;
    // t_data img2;
    mlx_image_t *img;
    mlx_image_t *img2;
    // t_data img3;
    t_textures_img text;
    t_mini_map *mini_map;
    t_player_infos *p_infos;
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