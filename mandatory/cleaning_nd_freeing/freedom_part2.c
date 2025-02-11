#include "../includes/ps.h"

void free_minimap(t_main_s *var ,t_mini_map *mini_map)
{
    mlx_delete_image(var->mlx, (mini_map)->img3);
    mini_map->img3 = NULL;
    free(mini_map);
}

void        free_p_bonus(t_player_bonus* player_b)
{
    free(player_b->obj);
    player_b->obj = NULL;
    free(player_b->enemy);
    player_b->enemy = NULL;
    free(player_b);
}

void free_p_info(t_player_infos *player, t_main_s *var)
{
    if (!player)
        return;
    if (player->walls)
    {
        free(player->walls);
        player->walls = NULL;
    }
    if (player->rays)
    {
        free_rays(var);
        player->rays = NULL;
    }
    if (player->p_bonus)
    {
        free_p_bonus(player->p_bonus);
        player->p_bonus = NULL;
    }
    free(player);
    player = NULL;
}

void free_rays_bonus(t_ray_info *var)
{
    if (var->bonus_rays)
    {
        if (var->bonus_rays->door)
            free(var->bonus_rays->door);
        if (var->bonus_rays->enemy)
            free(var->bonus_rays->enemy);
        if (var->bonus_rays->obj)
            free(var->bonus_rays->obj);
    }
    var->bonus_rays->door = NULL;
    var->bonus_rays->enemy = NULL;
    var->bonus_rays->obj = NULL;
}

void free_rays(t_main_s *var)
{
    int i;
    
    i = 0;
    
    if (!var->p_infos->rays)
        return;
    while (i < var->p_infos->nbr_rays)
    {
        free_rays_bonus(&var->p_infos->rays[i]);
        free(var->p_infos->rays[i].bonus_rays);
        i++;
    }
    free(var->p_infos->rays);
}
