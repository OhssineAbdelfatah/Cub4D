/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting_tools_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 23:49:36 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/14 23:49:37 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

void	init_cst_vert(t_casting *cst, t_main_s *var, int i)
{
	double	left_right;
	double	angle;

	angle = var->p_infos->rays[i].angle - (M_PI / 2);
	angle = adjust_angle(angle);
	cst->tan_angle = tan(angle);
	left_right = 1;
	if (var->p_infos->rays[i].facing_left)
		left_right = -1;
	cst->yintersection = floor(var->p_infos->y / SQ_LEN) * SQ_LEN;
	if (left_right == 1)
		cst->yintersection += SQ_LEN;
	if (var->p_infos->rays[i].facing_up)
		cst->xintersection = var->p_infos->x - ((cst->yintersection
					- var->p_infos->y) * cst->tan_angle);
	else
		cst->xintersection = var->p_infos->x - ((cst->yintersection
					- var->p_infos->y) * cst->tan_angle);
	cst->ysteps = SQ_LEN;
	cst->xsteps = cst->ysteps * cst->tan_angle;
	if (var->p_infos->rays[i].facing_left)
		cst->ysteps *= -1;
	else
		cst->xsteps *= -1;
}

void	init_cst_horiz(t_casting *cst, t_main_s *var, int i)
{
	double	angle;

	angle = var->p_infos->rays[i].angle + (M_PI / 2.00);
	angle = adjust_angle(angle);
	cst->tan_angle = tan(angle);
	cst->xintersection = floor(var->p_infos->x / floor(SQ_LEN))
		* floor(SQ_LEN);
	if (var->p_infos->rays[i].facing_down)
		cst->xintersection += SQ_LEN;
	if (var->p_infos->rays[i].facing_right)
	{
		cst->yintersection = var->p_infos->y + ((var->p_infos->x
					- cst->xintersection) / cst->tan_angle);
	}
	else if (var->p_infos->rays[i].facing_left)
	{
		cst->yintersection = var->p_infos->y + ((var->p_infos->x
					- cst->xintersection) / cst->tan_angle);
	}
	cst->xsteps = SQ_LEN;
	cst->ysteps = cst->xsteps / cst->tan_angle;
	if (var->p_infos->rays[i].facing_down)
		cst->ysteps *= -1;
}

int	hit_a_door(t_main_s *var, double xintersection, double yintersection, int i)
{
	int	x;
	int	y;

	x = (int)floor(xintersection / SQ_LEN);
	y = (int)floor(yintersection / SQ_LEN);
	if (y < 0 || x < 0 || x >= var->map_hight
		|| y > (int)ft_strlen(var->map[x]))
		return (0);
	if (var->map[x][y] == 'D')
		return (1);
	(void)i;
	return (0);
}

int	hit_a_wall(t_main_s *var, double xintersection, double yintersection, int i)
{
	int	x;
	int	y;

	x = (int)floor(xintersection / SQ_LEN);
	y = (int)floor(yintersection / SQ_LEN);
	if (y < 0 || x < 0 || x >= var->map_hight
		|| y > (int)ft_strlen(var->map[x]))
		return (1);
	if (var->map[x][y] == '1')
		return (1);
	(void)i;
	return (0);
}
