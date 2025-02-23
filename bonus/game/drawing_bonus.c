/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:54:08 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/18 21:54:09 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

void	draw_disk(mlx_image_t *img, int x_c, int y_c, int color)
{
	int	x;
	int	y;

	y = -P_RADIUS;
	while (y <= P_RADIUS)
	{
		x = -P_RADIUS;
		while (x <= P_RADIUS)
		{
			if (x * x + y * y <= P_RADIUS * P_RADIUS)
			{
				if ((x_c + x >= 0 && x_c + x < (int)img->width) && (y_c
						+ y < (int)img->height && y_c + y >= 0))
					mlx_put_pixel(img, x_c + x, y_c + y, color);
			}
			x++;
		}
		y++;
	}
}

void	init_draw_line(t_main_s *var, t_draw_line *func,
		t_draw_mini_map minimap)
{
	func->s_x = var->mini_map->p_x;
	func->s_y = var->mini_map->p_y;
	func->f_x = minimap.new_x;
	func->f_y = minimap.new_y;
	func->dx = abs(func->f_x - func->s_x);
	func->dy = abs(func->f_y - func->s_y);
	if (func->s_x < func->f_x)
		func->sx = 1;
	else
		func->sx = -1;
	if (func->s_y < func->f_y)
		func->sy = 1;
	else
		func->sy = -1;
	func->err = func->dx - func->dy;
}

void	draw_a_line2(t_main_s *var, t_draw_mini_map minimap, int color,
		mlx_image_t *img)
{
	t_draw_line	func;

	init_draw_line(var, &func, minimap);
	while (1)
	{
		if (func.s_x == func.f_x && func.s_y == func.f_y)
			break ;
		if (func.s_x < 0 || func.s_y < 0)
			break ;
		if (var->window_height <= func.s_y || var->window_width <= func.s_x)
			break ;
		mlx_put_pixel(img, func.s_x, func.s_y, color);
		func.e2 = 2 * func.err;
		if (func.e2 > -func.dy)
		{
			func.err -= func.dy;
			func.s_x += func.sx;
		}
		if (func.e2 < func.dx)
		{
			func.err += func.dx;
			func.s_y += func.sy;
		}
	}
}

// void	draw_a_line(t_main_s *var, int s_x, int func.s_y, int func.f_x,
		// int f_y,
// 		int color, mlx_image_t *img)
// {
// 	int dx;
// 	int dy;
// 	float m;

// 	dx = func.f_x -s_x;
// 	dy = f_y - s_y;
// 	if (dx)
// 		m = dy / dx;
// 	(void)var;
// 	(void)img;
// 	// (void)line;
// };

// void	draw_a_line2(t_main_s *var, int s_x, int s_y, int f_x, int f_y,
// 		int color, mlx_image_t *img)
// {
// 	int	dx;
// 	int	dy;
// 	int	sx;
// 	int	sy;
// 	int	err;
// 	int	e2;

// 	dx = abs(f_x - s_x);
// 	dy = abs(f_y - s_y);
// 	if (s_x < f_x)
// 		sx = 1;
// 	else
// 		sx = -1;
// 	if (s_y < f_y)
// 		sy = 1;
// 	else
// 		sy = -1;
// 	err = dx - dy;
// 	while (1)
// 	{
// 		if (s_x == f_x && s_y == f_y)
// 			break ;
// 		if (s_x < 0 || s_y < 0)
// 			break ;
// 		if (var->window_height <= s_y || var->window_width <= s_x)
// 			break ;
// 		mlx_put_pixel(img, s_x, s_y, color);
// 		e2 = 2 * err;
// 		if (e2 > -dy)
// 		{
// 			err -= dy;
// 			s_x += sx;
// 		}
// 		if (e2 < dx)
// 		{
// 			err += dx;
// 			s_y += sy;
// 		}
// 	}
// }
