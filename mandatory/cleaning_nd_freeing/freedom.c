/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:21:59 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/19 20:22:01 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	free_p_info(t_player_infos *player, t_main_s *var)
{
	if (!player)
		return ;
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
	free(player);
	player = NULL;
}

void	free_all(t_main_s *var)
{
	if (!var)
		return ;
	if (var->p_infos)
		free_p_info(var->p_infos, var);
	if (var->img2)
		mlx_delete_image(var->mlx, var->img2);
	if (var->text)
		free_texts(var->text);
	if (var->parse)
		free_data(var->parse);
	mlx_terminate(var->mlx);
	reset_them_all(var);
	free(var);
}
