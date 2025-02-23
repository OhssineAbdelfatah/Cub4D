/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_tools_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/16 15:48:52 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/16 15:48:53 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

bool	check_doors_for_obj_rendering(t_main_s *var, t_player_bonus *ptr, int i,
		int ray_to_inspect)
{
	double	door_dis;

	door_dis = var->p_infos->rays[ray_to_inspect].bonus_rays->door->distance;
	if (var->p_infos->rays[ray_to_inspect].bonus_rays->hit_a_door
		&& door_dis < ptr->obj[i].distance)
		return (false);
	return (true);
}
