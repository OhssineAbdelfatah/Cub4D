/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move_hooks.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:55:15 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/18 21:55:16 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	turnning_around(mlx_key_data_t key, t_main_s *ptr)
{
	if (key.key == L_ARROW)
	{
		if (key.action)
			ptr->p_infos->turn_arround = 1;
		else
			ptr->p_infos->turn_arround = 0;
	}
	if (key.key == R_ARROW)
	{
		if (key.action)
			ptr->p_infos->turn_arround = -1;
		else
			ptr->p_infos->turn_arround = 0;
	}
}

void	moving_around(mlx_key_data_t key, t_main_s *ptr)
{
	if (key.key == S || key.key == W)
	{
		if (key.action && key.key == S)
			ptr->p_infos->move_up_down = -1;
		else if (key.action && key.key == W)
			ptr->p_infos->move_up_down = 1;
		else if (!key.action)
			ptr->p_infos->move_up_down = 0;
	}
	if (key.key == A)
	{
		if (key.action)
			ptr->p_infos->move_left_right = 1;
		else
			ptr->p_infos->move_left_right = 0;
	}
	if (key.key == D)
	{
		if (key.action)
			ptr->p_infos->move_left_right = -1;
		else
			ptr->p_infos->move_left_right = 0;
	}
}

void	key_hook(mlx_key_data_t key, void *var)
{
	t_main_s	*ptr;

	ptr = (t_main_s *)var;
	if (key.key == MLX_KEY_ESCAPE)
	{
		free_all(var);
		exit(0);
	}
	turnning_around(key, ptr);
	moving_around(key, ptr);
}
