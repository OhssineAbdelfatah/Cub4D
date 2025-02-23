/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 23:50:14 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/14 23:50:16 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

void	cast_horz_doors(t_main_s *var, t_x_and_y_d *h_xy_door, t_casting *cst,
		int i)
{
	double	up_down;

	up_down = 1;
	if (var->p_infos->rays[i].facing_up)
		up_down = -1;
	if (hit_a_door(var, cst->xintersection + up_down, cst->yintersection, i)
		&& !h_xy_door->hit_a_door)
	{
		h_xy_door->hit_a_door = true;
		h_xy_door->y = cst->xintersection;
		h_xy_door->x = cst->yintersection;
		h_xy_door->distance = sqrt(pow((cst->xintersection - var->p_infos->x),
					2) + pow((cst->yintersection - var->p_infos->y), 2));
	}
}

double	cast_horizontally(t_main_s *var, int i, t_x_and_y_d *xy,
		t_x_and_y_d *h_xy_door)
{
	double		up_down;
	t_casting	cst;

	init_cst_horiz(&cst, var, i);
	up_down = 1;
	if (var->p_infos->rays[i].facing_up)
		up_down = -1;
	while (cst.xintersection >= 0 && cst.yintersection >= 0)
	{
		cast_horz_doors(var, h_xy_door, &cst, i);
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

void	cast_vert_doors(t_main_s *var, int i, t_x_and_y_d *v_xy_door,
		t_casting *cst)
{
	double	left_right;

	left_right = 1;
	if (var->p_infos->rays[i].facing_left)
		left_right = -1;
	if (hit_a_door(var, cst->xintersection, cst->yintersection + left_right, i)
		&& !v_xy_door->hit_a_door)
	{
		v_xy_door->hit_a_door = true;
		v_xy_door->y = cst->xintersection;
		v_xy_door->x = cst->yintersection;
		v_xy_door->distance = sqrt(pow((cst->xintersection - var->p_infos->x),
					2) + pow((cst->yintersection - var->p_infos->y), 2));
	}
}

double	cast_vertically(t_main_s *var, int i, t_x_and_y_d *xy,
		t_x_and_y_d *v_xy_door)
{
	t_casting	cst;
	double		left_right;

	init_cst_vert(&cst, var, i);
	left_right = 1;
	if (var->p_infos->rays[i].facing_left)
		left_right = -1;
	while (cst.xintersection >= 0.00 && cst.yintersection >= 0.00)
	{
		cast_vert_doors(var, i, v_xy_door, &cst);
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
