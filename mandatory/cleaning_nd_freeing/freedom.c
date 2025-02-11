#include "../includes/ps.h"



void free_all(t_main_s *var)
{
    if (!var)
        return;
    if (var->p_infos)
        free_p_info(var->p_infos, var);
    if (var->img2)
        mlx_delete_image(var->mlx,var->img2);
    if (var->text)
        free_texts(var->text);
    if (var->map)
        free_d_arr(var->map);
    if (var->bonus)
        free_main_bonus(var->bonus, var);
    if (var->parse)
        free_data(var->parse);
    if (var->mini_map)
        free_minimap(var, var->mini_map);
    mlx_terminate(var->mlx);
    reset_them_all(var);
    free(var);
}