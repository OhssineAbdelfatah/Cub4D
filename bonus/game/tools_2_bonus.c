/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 21:56:06 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/18 21:56:07 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

void	func(void *param)
{
	t_main_s	*var;

	var = (t_main_s *)param;
	free_all(var);
	exit(0);
	return ;
}

int	gettt_rgba(uint8_t *color)
{
	return (color[0] << 24 | color[1] << 16 | color[2] << 8 | color[3]);
}

long long	get_time_mil(void)
{
	long long	res;
	t_time		tp;

	gettimeofday(&tp, NULL);
	res = (tp.tv_sec * 1000) + (tp.tv_usec / 1000);
	return (res);
}
