/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom_part2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:39:37 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/19 23:39:39 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

void	free_minimap(t_main_s *var, t_mini_map *mini_map)
{
	mlx_delete_image(var->mlx, (mini_map)->img3);
	mini_map->img3 = NULL;
	free(mini_map);
}

void	free_health_bar(t_main_s *var, t_health_bar *bar)
{
	if (bar->health_img)
		mlx_delete_image(var->mlx, bar->health_img);
	if (bar->health_str)
		free(bar->health_str);
	bar->health_str = NULL;
	bar->health_img = NULL;
	free(bar);
}

void	free_p_bonus(t_main_s *var, t_player_bonus *player_b)
{
	free(player_b->obj);
	player_b->obj = NULL;
	free(player_b->enemy);
	player_b->enemy = NULL;
	if (player_b->h_bar)
		free_health_bar(var, player_b->h_bar);
	free(player_b);
}

void	free_rays_bonus(t_ray_info *var)
{
	if (var->bonus_rays)
	{
		if (var->bonus_rays->door)
			free(var->bonus_rays->door);
	}
	var->bonus_rays->door = NULL;
}

void	free_rays(t_main_s *var)
{
	int	i;

	i = 0;
	if (!var->p_infos->rays)
		return ;
	while (i < var->p_infos->nbr_rays)
	{
		free_rays_bonus(&var->p_infos->rays[i]);
		free(var->p_infos->rays[i].bonus_rays);
		i++;
	}
	free(var->p_infos->rays);
}
