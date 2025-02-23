/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/14 22:12:08 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/15 21:51:11 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

int	ft_dstr_len(char **av)
{
	int	i;

	i = 0;
	if (!av)
		return (0);
	while (av[i])
		i++;
	return (i);
}

int	is_it_the_player(char c)
{
	if (c == 'W' || c == 'N' || c == 'S' || c == 'E')
		return (1);
	return (0);
}

void	panic(char *s)
{
	if (s)
		perror(s);
	exit(1);
}

double	adjust_angle(double angle)
{
	if (angle > (2 * M_PI))
		return (angle - (2 * M_PI));
	if (angle < 0)
		return ((2 * M_PI) + angle);
	return (angle);
}

void	paintit(mlx_image_t *img, int color, t_xy_i *start, t_xy_i *till)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < till->y)
	{
		while (j < till->x)
		{
			mlx_put_pixel(img, j + start->x, i + start->y, color);
			j++;
		}
		j = 0;
		i++;
	}
}
