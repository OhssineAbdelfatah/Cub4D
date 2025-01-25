/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:00:24 by aohssine          #+#    #+#             */
/*   Updated: 2025/01/23 13:47:38 by aohssine         ###   ########.fr       */
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

int	cube(char *ext, t_parse_data** data)
{
	t_pre_data	*dt;

	if (check_ext(ext, ".cub") ) 
		return (printf("ext err\n"),1);
	dt = read_file(ext);
		// return ((printf("alo\n")), 1);
	if (!dt)
		return (free(dt), printf("read file dt NULL\n"),1);
	if (!dt->info)
		return (free_map(dt->info), free(dt), 1);
	*data = dt->data;
	free_map(dt->info);
	free(dt);
	return 0;
	// return (free_map(dt->info), free(dt), 0);
}



void free_data(t_parse_data* data)
{
	free(data->tex_ea);
	free(data->tex_so);
	free(data->tex_we);
	free(data->tex_no);
	free(data->clr_c);
	free(data->clr_f);
	free(data->pos);
	free_split(data->map);
	free(data);
	return ;
}

// int is_file_exist()

t_parse_data	*parse(int ac, char **av)
{
	t_parse_data **data;
	t_parse_data *data1;
	// data = (t_parse_data *)safe_malloc();
	data = (t_parse_data**)safe__malloc();
	if (ac == 2)
	{
		if (cube(av[1], data))
		{
			ft_putstr_fd("\033[0;31m Error\033[0m \n", 2);
			// free_da	ta(data);
			// free(data);
			exit(1);
		}
		data1 = *data;
		free(data);
		return data1;
	
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

	}else
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
	exit(0);
}
