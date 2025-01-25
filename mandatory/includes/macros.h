#ifndef MACROS_H    
#define MACROS_H


// FOR macOS
// # define A 0
// # define D 2
// # define S 1
// # define W 13
// # define ESC 53
// #define right_arrow 124
// #define left_arrow 123

//for linux (debian)
// # define A 97
// # define D 100
// # define S 115
// # define W 119
// # define ESC 65307
// #define right_arrow  65363
// #define left_arrow  65361


// FOR NEW MLX
# define A 65
# define D 68
# define S 83
# define W 87
# define ESC 66
#define right_arrow  262
#define left_arrow  263

#define square_len 64
#define player_radius 5
#define scale_of_minimap 0.2
#define EPSILON 1e-6

typedef enum dir
{
    NONE,
    LEFT,
    RIGHT,
    UP,
    DOWN,
    UP_LEFT,
    UP_RIGHT,
    DOWN_LEFT, 
    DOWN_RIGHT
}t_direction;

#endif

