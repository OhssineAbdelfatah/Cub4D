#include "../includes/ps.h"


void free_text(t_text *text)
{
    if (!text)
        return;
    int i= 0;
    while (i < (text->hieght))
    {
        free((text->pixels[i]));
        text->pixels[i] = NULL;
        i++;
    }
    free(text->pixels);
    text->pixels = NULL;
    free(text);
}

void free_texts(t_text **text)
{
    int i;
    
    i = 0;
    if (!text)
        return;
    while (i < 4)
    {
        free_text(text[i]);
        text[i] = NULL;
        i++;
    }
    free(text);
}

void free_d_arr(char **av)
{
    if (!av)
        return;
    int i;
    i = 0;
    while (av[i])
    {
        free(av[i]);
        av[i] = NULL;
        i++;
    }
    free(av);
}

void free_main_bonus(t_bonus *var, t_main_s *main)
{
    int i;

    i = 0;
    if (var->dead_enemy_text)
        free_text(var->dead_enemy_text);
    if (var->enemy_text)
        free_text(var->enemy_text);
    if (var->floor_text)
        free_text(var->floor_text);
    if (var->sky_text)
        free_text(var->sky_text);
    if (var->gun_in_hand_text0)
        free_text(var->gun_in_hand_text0);
    if (var->pillar_img)
        free_text(var->pillar_img);
    while (i <  4)
    {
        mlx_delete_image(main->mlx , var->gun_in_hands_img[i]);
        mlx_delete_texture(var->gun_in_hand[i]);
        i++;
    }
    mlx_delete_texture(var->crosshair);
    mlx_delete_image(main->mlx, var->crosshair_img);
    free(var);
}

void reset_them_all(t_main_s * var)
{
    var->map = NULL;
    var->mlx = NULL;
    var->img2 = NULL;
    var->text = NULL;
    var->mini_map = NULL;
    var->p_infos  =NULL;
    var->bonus = NULL;
}