/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies_tools_part2_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:56:36 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/19 23:56:37 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

int	is_sorted(t_obj *obj, t_enemy *enemy, int max)
{
	int	i;

	i = 0;
	if (obj)
	{
		while (i < max)
		{
			if (i + 1 < max)
				if (obj[i].distance < obj[i + 1].distance)
					return (1);
			i++;
		}
		return (0);
	}
	while (i < max)
	{
		if (i + 1 < max)
			if (enemy[i].distance < enemy[i + 1].distance)
				return (1);
		i++;
	}
	return (0);
}

void	swap_enemy(t_enemy *one, t_enemy *two)
{
	t_enemy	tmp;

	tmp = *one;
	*one = *two;
	*two = tmp;
}

void	adjust_rank_enemies(t_enemy *enemy, int max)
{
	int	i;

	i = 0;
	while (is_sorted(NULL, enemy, max))
	{
		i = 0;
		while (i < max)
		{
			if (i + 1 < max)
			{
				if (enemy[i].distance < enemy[i + 1].distance)
					swap_enemy(&enemy[i], &enemy[i + 1]);
			}
			i++;
		}
	}
}
