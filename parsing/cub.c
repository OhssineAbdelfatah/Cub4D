/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacksniper <blacksniper@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:00:24 by aohssine          #+#    #+#             */
/*   Updated: 2025/01/12 23:55:27 by blacksniper      ###   ########.fr       */
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

int	cube(char *ext, t_parse_data* data)
{
	t_pre_data	*dt;

	(void)data;
	if (check_ext(ext, ".cub"))
		return (printf("ext err\n"),1);
	dt = read_file(ext);
		// return ((printf("alo\n")), 1);
	if (!dt)
		return (free(dt), printf("read file dt NULL\n"),1);
	if (!dt->info)
		return (free_map(dt->info), free(dt), 1);
	return (free_map(dt->info), free(dt), 0);
}

void	ff(void)
{
	system("leaks -q cub3D ");
}

// void free_data(t_parse_data* data)
// {
// 	(void)data;
// 	return ;
// }

t_parse_data	*parse(int ac, char **av)
{
	t_parse_data *data;
	// atexit(ff);
	data = (t_parse_data *)safe_malloc();
	if (ac == 2)
	{
		if (cube(av[1], data))
		{
			ft_putstr_fd("\033[0;31m Error\033[0m \n", 2);
			// free_data(data);
			exit(1);
		}
		
		// return parse data
		/*
				char					*tex_no;
				char					*tex_we;
				char					*tex_so;
				char					*tex_ea;
				t_color					set;
				double					dir;
				t_pos					*pos;
				char					**map;
		*/
	}
	else
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	exit(0);
}
