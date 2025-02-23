/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shooting_animation_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:55:42 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/18 21:55:44 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

void	display_shooting(t_main_s *var)
{
	static int	i = 1;

	if (i == 4)
	{
		var->bonus->gun_img[i - 1]->enabled = false;
		i = 1;
	}
	if (i < 4 && i != 0)
	{
		var->bonus->gun_img[i]->enabled = true;
		var->bonus->gun_img[i - 1]->enabled = false;
		i++;
	}
}

void	redisplay_the_gun(t_main_s *var)
{
	int	i;

	i = 3;
	while (i > 0)
	{
		var->bonus->gun_img[i]->enabled = false;
		i--;
	}
	var->bonus->gun_img[i]->enabled = true;
}

void	shoot_them_mfs(t_main_s *var)
{
	int	i;
	int	max_range;
	int	min_range;

	i = var->bonus->nbr_enemies - 1;
	display_shooting(var);
	while (i >= 0)
	{
		max_range = (var->window_width / 2)
			+ (var->p_infos->p_bonus->enemy[i].enemy_width / 4);
		min_range = (var->window_width / 2)
			- (var->p_infos->p_bonus->enemy[i].enemy_width / 4);
		if (var->p_infos->p_bonus->enemy[i].x_screen > min_range
			&& var->p_infos->p_bonus->enemy[i].x_screen < max_range)
		{
			if (abs(var->p_infos->up_down_offset) <= 30)
			{
				var->p_infos->p_bonus->enemy[i].alive = false;
				return ;
			}
		}
		i--;
	}
}

void	mouse_hook(mouse_key_t button, action_t action, modifier_key_t mods,
		void *param)
{
	t_main_s	*var;

	var = (t_main_s *)param;
	if (button == 0)
	{
		if (action == 1)
			shoot_them_mfs(var);
		if (action == 0)
			redisplay_the_gun(var);
	}
	(void)mods;
}
