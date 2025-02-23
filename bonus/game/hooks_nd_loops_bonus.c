/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_nd_loops_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:54:52 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/18 21:54:53 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

void	need_update_first_check(t_main_s *main, t_player_infos *var,
		t_need_update *func)
{
	if (var->move_up_down != 0 || var->turn_arround != 0
		|| var->move_left_right != 0)
	{
		var->rotation_angle += var->turn_arround * var->rotation_speed;
		var->rotation_angle = adjust_angle(var->rotation_angle);
		func->tmp_angle = var->rotation_angle;
		if (var->move_left_right)
		{
			func->move_steps = var->move_left_right * var->speed;
			func->tmp_angle = adjust_angle(var->rotation_angle + (M_PI / 2));
		}
		func->new_x = var->x + cos(func->tmp_angle) * func->move_steps;
		func->new_y = var->y + sin(func->tmp_angle) * func->move_steps;
		if (var->move_left_right || var->move_up_down)
		{
			func->check = is_there_a_wall(func->new_x + (2 * (func->new_x
							- var->x)), func->new_y + (2 * (func->new_y
							- var->y)), main->map);
			if (!func->check && !check_teleportation(var, main->map))
			{
				var->x = func->new_x;
				var->y = func->new_y;
			}
		}
	}
}

int	need_update(t_main_s *main, t_player_infos *var)
{
	t_need_update	func;

	func.move_steps = var->move_up_down * var->speed;
	need_update_first_check(main, var, &func);
	if (var->look_up_down || var->move_up_down != 0 || var->turn_arround != 0
		|| var->move_left_right != 0)
	{
		if (var->look_up_down == 1)
			if (var->up_down_offset < (main->window_height / 3))
				var->up_down_offset += var->speed * var->look_up_down * 4;
		if (var->look_up_down == -1)
			if (var->up_down_offset > (main->window_height / 3) * -1)
				var->up_down_offset += var->speed * var->look_up_down * 4;
		return (1);
	}
	return (0);
}

int	check_player_health(t_main_s *var)
{
	t_xy_i	start;
	t_xy_i	end;

	start.x = 0;
	start.y = 0;
	end.x = var->window_width;
	end.y = var->window_height;
	if (var->p_infos->health <= 0)
	{
		var->p_infos->alive = false;
		paintit(var->img2, 0xFF3333FF, &start, &end);
		mlx_put_string(var->mlx, "GAME OVER", var->window_width / 2,
			var->window_height / 2);
		return (1);
	}
	return (0);
}

void	loop_hook(void *ptr)
{
	t_main_s	*var;
	long long	now;

	var = (t_main_s *)ptr;
	now = get_time_mil();
	if (check_player_health(var))
		return ;
	if (need_update(var, var->p_infos))
	{
		work_of_art(var, 1);
	}
	else if (now - var->start_frame > 25)
	{
		var->start_frame = now;
		work_of_art(var, 0);
	}
}

void	mlx_loops_and_hooks(t_main_s *var)
{
	mlx_close_hook(var->mlx, func, var);
	mlx_key_hook(var->mlx, key_hook, var);
	mlx_mouse_hook(var->mlx, mouse_hook, var);
	mlx_cursor_hook(var->mlx, cursor_func, var);
	mlx_loop_hook(var->mlx, loop_hook, var);
	mlx_loop(var->mlx);
}
