/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing_things_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:54:23 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/18 21:54:27 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

void	draw_v_sides(t_main_s *var, int width, int height, int frame_width)
{
	t_xy_i	xy;

	xy.x = 0;
	xy.y = 0;
	while (xy.y < height)
	{
		xy.x = 0;
		if ((xy.y >= 0 && xy.y < 0 + frame_width) || (xy.y > height
				- (frame_width + 1) && xy.y <= height - 1))
		{
			while (xy.x < width)
			{
				mlx_put_pixel(var->img2, xy.x + 20, xy.y + var->window_height
					- 60, 0xFFFFFFFF);
				xy.x++;
			}
		}
		xy.y++;
	}
}

void	draw_h_sides(t_main_s *var, int width, int height, int frame_width)
{
	t_xy_i	xy;

	xy.x = 0;
	xy.y = 0;
	while (xy.x < width)
	{
		xy.y = 0;
		while (xy.y < height)
		{
			if ((xy.x >= 0 && xy.x < 0 + frame_width) || (xy.x < width
					&& xy.x >= width - frame_width))
				mlx_put_pixel(var->img2, xy.x + 20, xy.y + var->window_height
					- 60, 0xFFFFFFFF);
			xy.y++;
		}
		xy.x++;
	}
}

void	draw_health_frame(t_main_s *var, int width, int height)
{
	int	frame_width;

	frame_width = 4;
	draw_v_sides(var, width, height, frame_width);
	draw_h_sides(var, width, height, frame_width);
}

void	reset_values(t_health_bar *bar, t_player_infos *p_var)
{
	bar->y = 0;
	bar->x = 0;
	bar->end = (int)floor((double)bar->width * ((double)p_var->health
				/ (double)p_var->max_health));
	if (bar->health_str)
		free(bar->health_str);
	bar->health_str = ft_itoa(p_var->health);
	bar->health_str = _ft_strjoin(bar->health_str, " % ", 3);
	if (!bar->health_str)
		panic("health str failed to allocated \n");
}

void	draw_health_bar(t_main_s *var, t_health_bar *bar)
{
	while (bar->y < bar->height)
	{
		bar->x = 0;
		while (bar->x < bar->end)
		{
			mlx_put_pixel(var->img2, bar->x + 20, bar->y + var->window_height
				- 60, 0xFF3333FF);
			bar->x++;
		}
		bar->y++;
	}
	reset_values(bar, var->p_infos);
	draw_health_frame(var, bar->width, bar->height);
	if (bar->health_img)
	{
		mlx_delete_image(var->mlx, bar->health_img);
	}
	bar->health_img = mlx_put_string(var->mlx, bar->health_str, 150,
			var->window_height - 65);
	mlx_resize_image(bar->health_img, 70, 35);
}
