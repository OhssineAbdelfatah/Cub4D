/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 23:50:14 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/14 23:50:16 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

double	cast_horizontally(t_main_s *var, int i, t_x_and_y_d *xy)
{
	double		up_down;
	t_casting	cst;

	init_cst_horiz(&cst, var, i);
	up_down = 1;
	if (var->p_infos->rays[i].facing_up)
		up_down = -1;
	while (cst.xintersection >= 0 && cst.yintersection >= 0)
	{
		if (hit_a_wall(var, cst.xintersection + up_down, cst.yintersection, i))
		{
			xy->y = cst.xintersection;
			xy->x = cst.yintersection;
			break ;
		}
		cst.xintersection += (cst.xsteps * up_down);
		cst.yintersection += cst.ysteps;
	}
	cst.distance = sqrt(pow((cst.xintersection - var->p_infos->x), 2)
			+ pow((cst.yintersection - var->p_infos->y), 2));
	return (cst.distance);
}

double	cast_vertically(t_main_s *var, int i, t_x_and_y_d *xy)
{
	t_casting	cst;
	double		left_right;

	init_cst_vert(&cst, var, i);
	left_right = 1;
	if (var->p_infos->rays[i].facing_left)
		left_right = -1;
	while (cst.xintersection >= 0.00 && cst.yintersection >= 0.00)
	{
		if (hit_a_wall(var, cst.xintersection, cst.yintersection + left_right,
				i))
		{
			xy->y = cst.xintersection;
			xy->x = cst.yintersection;
			break ;
		}
		cst.xintersection += cst.xsteps;
		cst.yintersection += cst.ysteps;
	}
	cst.distance = sqrt(pow((cst.xintersection - var->p_infos->x), 2)
			+ pow(cst.yintersection - var->p_infos->y, 2));
	return (cst.distance);
}
