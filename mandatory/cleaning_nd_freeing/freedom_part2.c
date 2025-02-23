/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom_part2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:22:11 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/19 20:22:12 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	free_rays(t_main_s *var)
{
	if (!var->p_infos->rays)
		return ;
	free(var->p_infos->rays);
	var->p_infos->rays = NULL;
}
