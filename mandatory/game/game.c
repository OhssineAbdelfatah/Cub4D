/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:54:43 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/18 21:54:45 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	paint_floor_celling(t_main_s *var)
{
	int		color;
	t_xy_i	start;
	t_xy_i	till;

	color = create_rgba(var->parse->clr_c[0], var->parse->clr_c[1],
			var->parse->clr_c[2]);
	till.x = var->window_width;
	till.y = (var->window_height) / 2;
	start.x = 0;
	start.y = 0;
	paintit(var->img2, color, &start, &till);
	start.y = var->window_height / 2;
	color = create_rgba(var->parse->clr_f[0], var->parse->clr_f[1],
			var->parse->clr_f[2]);
	paintit(var->img2, color, &start, &till);
}

void	first_part(t_main_s *var)
{
	t_work_of_art_part1	func;

	func.p_x = (var->parse->pos->y_ver * SQ_LEN) + (SQ_LEN / 2);
	func.p_y = (var->parse->pos->x_hor * SQ_LEN) + (SQ_LEN / 2);
	var->p_infos = init_player_struct(var, var->parse->dir, func.p_x, func.p_y);
}

void	work_of_art(t_main_s *var, int shoot)
{
	paint_floor_celling(var);
	if (var->p_infos == NULL)
	{
		mlx_image_to_window(var->mlx, var->img2, 0, 0);
		first_part(var);
	}
	if (shoot)
	{
		free_rays(var);
		shoot_the_rays(var);
	}
	wall_rendering(var);
}
