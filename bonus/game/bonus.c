/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 23:14:22 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/19 23:40:28 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

void	count_obj_enemi(t_main_s *var)
{
	int	nbr_obj;
	int	nbr_enemies;
	int	x;
	int	y;

	x = 0;
	y = 0;
	nbr_enemies = 0;
	nbr_obj = 0;
	while (var->map[y])
	{
		x = 0;
		while (var->map[y][x])
		{
			if (var->map[y][x] == 'O')
				nbr_obj++;
			if (var->map[y][x] == 'e')
				nbr_enemies++;
			x++;
		}
		y++;
	}
	var->bonus->nbr_enemies = nbr_enemies;
	var->bonus->nbr_obj = nbr_obj;
}
