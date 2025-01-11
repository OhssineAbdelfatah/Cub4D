/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:00:24 by aohssine          #+#    #+#             */
/*   Updated: 2025/01/10 18:01:24 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	check_ext(char *ext, char *base_ext)
{
	int	last;
	int	four;

	four = ft_strlen(base_ext);
	if (ft_strlen(ext) == 0)
		return (1);
	last = ft_strlen(ext);
	while (four-- != 0)
	{
		last--;
		if (base_ext[four] != ext[last])
			return (1);
	}
	return (0);
}

int	cube(char *ext)
{
	t_pre_data	*dt;

	if (check_ext(ext, ".cub"))
		return (1);
	dt = read_file(ext);
	if (!dt)
		return (free(dt), 1);
	if (!dt->info)
		return (free_map(dt->info), free(dt), 1);
	return (free_map(dt->info), free(dt), 0);
}

void	ff(void)
{
	system("leaks -q cub3D ");
}

int	main(int ac, char **av)
{
	atexit(ff);
	if (ac == 2)
	{
		if (cube(av[1]))
		{
			ft_putstr_fd("\033[0;31m Error\033[0m \n", 2);
			return (0);
		}
		ft_putstr_fd("\033[0;32mvalid infos name\033[0m\n", 2);
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
	}
	return (0);
}
