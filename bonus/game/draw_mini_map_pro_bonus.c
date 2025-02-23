/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_mini_map_pro_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:53:54 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/18 21:53:56 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

int	is_there_enemy(t_main_s *var, double x, double y)
{
	int	new_enemy_x;
	int	new_enemy_y;
	int	i;

	i = var->bonus->nbr_enemies - 1;
	while (i >= 0)
	{
		new_enemy_x = (int)floor(var->p_infos->p_bonus->enemy[i].x
				/ SQ_LEN);
		new_enemy_y = (int)floor(var->p_infos->p_bonus->enemy[i].y
				/ SQ_LEN);
		if (new_enemy_x == x && new_enemy_y == y)
		{
			if (var->p_infos->p_bonus->enemy[i].alive)
				return (1);
			else
				return (2);
		}
		i--;
	}
	return (0);
}

int	init_pixel_nd_check(t_main_s *var, t_check_pixel *func, int x, int y)
{
	func->diff_x = (x - var->mini_map->p_x) * 2;
	func->diff_y = (y - var->mini_map->p_y) * 2;
	func->diff_x = ((int)floor(var->p_infos->y) + func->diff_x);
	func->diff_y = ((int)floor(var->p_infos->x) + func->diff_y);
	if (func->diff_x < 0 || func->diff_y < 0)
		return (1);
	func->diff_x /= SQ_LEN;
	func->diff_y /= SQ_LEN;
	return (0);
}

int	check_the_pixel(t_main_s *var, int x, int y)
{
	t_check_pixel	func;

	if (init_pixel_nd_check(var, &func, x, y))
		return (-1);
	if (func.diff_y >= var->map_hight)
		return (-1);
	if (func.diff_x >= (int)ft_strlen(var->map[func.diff_y]))
		return (-1);
	func.square = var->map[func.diff_y][func.diff_x];
	if (func.square == '1')
		return (1);
	if (func.square == '\n' || func.square == 32)
		return (-1);
	if (func.square == 'O')
		return (-2);
	if (func.square == 'D')
		return (-3);
	func.enemy_there = is_there_enemy(var, func.diff_x, func.diff_y);
	if (func.enemy_there == 1)
		return (mlx_put_pixel(var->mini_map->img3, x, y, 0xD82020FF), -4);
	else if (func.enemy_there == 2)
		return (mlx_put_pixel(var->mini_map->img3, x, y, 0xCC6600FF), -5);
	return (0);
}

void	draw_the_pixel_for_minimap(t_main_s *var, int x, int y)
{
	int	check;

	check = check_the_pixel(var, x, y);
	if (check == 0)
		mlx_put_pixel(var->mini_map->img3, x, y, 0xC0C0C0FF);
	else if (check == 1)
		mlx_put_pixel(var->mini_map->img3, x, y, 0x000000FF);
	else if (check == -1)
		mlx_put_pixel(var->mini_map->img3, x, y, 0x606060FF);
	else if (check == -2)
		mlx_put_pixel(var->mini_map->img3, x, y, 0x66CC00FF);
	else if (check == -3)
		mlx_put_pixel(var->mini_map->img3, x, y, 0x5EC4D4FF);
}

int	draw_mini_map_42(t_main_s *var)
{
	t_draw_mini_map	func;

	func.x = 0;
	func.y = 0;
	while (func.x < var->mini_map->minimap_width)
	{
		while (func.y < var->mini_map->minimap_height)
		{
			draw_the_pixel_for_minimap(var, func.x, func.y);
			func.y++;
		}
		func.y = 0;
		func.x++;
	}
	func.new_x = var->mini_map->p_x + sin(var->p_infos->rotation_angle) * 30;
	func.new_y = var->mini_map->p_y + cos(var->p_infos->rotation_angle) * 30;
	draw_disk(var->mini_map->img3, var->mini_map->p_x, var->mini_map->p_y,
		0x000000FF);
	draw_a_line2(var, func, 0x00F0FFFF, var->mini_map->img3);
	return (0);
}
