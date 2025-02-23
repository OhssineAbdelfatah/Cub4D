/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_parse2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/17 17:32:16 by aohssine          #+#    #+#             */
/*   Updated: 2025/02/17 17:56:29 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing_bonus.h"

void	fill_colors(t_pre_data *dt)
{
	char	***sets;
	char	*set1;
	char	*set2;
	int		count;

	count = 0;
	sets = (char ***)malloc(2 * sizeof(char **));
	set1 = fetch_index_splited(find_info_value(FLOOR, dt->info));
	sets[0] = ft_split(set1, ',');
	set2 = fetch_index_splited(find_info_value(CEILEING, dt->info));
	sets[1] = ft_split(set2, ',');
	dt->data->clr_f = malloc(3 * sizeof(int));
	dt->data->clr_c = malloc(3 * sizeof(int));
	while (count < 3)
	{
		dt->data->clr_f[count] = ft_atoi(sets[0][count]);
		dt->data->clr_c[count] = ft_atoi(sets[1][count]);
		count++;
	}
	free(set1);
	free(set2);
	free_split(sets[0]);
	free_split(sets[1]);
	free(sets);
	return ;
}

void	fill_data(t_pre_data *dt)
{
	dt->data->tex_ea = fetch_index_splited(find_info_value(IMG_EA, dt->info));
	dt->data->tex_so = fetch_index_splited(find_info_value(IMG_SO, dt->info));
	dt->data->tex_we = fetch_index_splited(find_info_value(IMG_WE, dt->info));
	dt->data->tex_no = fetch_index_splited(find_info_value(IMG_NO, dt->info));
	dt->data->pos = malloc(sizeof(t_pos));
	find_pos(dt->data->map, dt->data->pos);
	dt->data->dir = dt->data->map[dt->data->pos->y_ver][dt->data->pos->x_hor];
	fill_colors(dt);
	return ;
}

void	*free_error(t_pre_data *dt, int f_dt_map, int f_dt_data_map)
{
	free_map(dt->info);
	if (f_dt_map)
		free_map(dt->map);
	if (f_dt_data_map)
		free_split(dt->data->map);
	free(dt->data);
	free(dt);
	return (NULL);
}
