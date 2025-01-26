/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacksniper <blacksniper@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:22:54 by aohssine          #+#    #+#             */
/*   Updated: 2025/01/26 21:39:48 by blacksniper      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

/*

◦ The map must be closed/surrounded by walls, if not the program must return
	an error.


◦ Except for the map content, each type of element can be separated by one or
	more empty line(s).


◦ Except for the map content which always has to be the last, each type of
	element can be set in any order in the file.


◦ Except for the map, each type of information from an element can be separated
	by one or more space(s).


◦ The map must be parsed as it looks in the file. Spaces are a valid part of the
	map and are up to you to handle. You must be able to parse any kind of map,
	as long as it respects the rules of the map.

*/

int	check_unicty_infos(t_map_lst *list)
{
	t_map_lst	*tmp;

	if (list_size(list) != 6)
		return (1);
	while (list)
	{
		tmp = list->next;
		while (tmp)
		{
			if (list->type > 5 || list->type == tmp->type)
				return (1);
			tmp = tmp->next;
		}
		list = list->next;
	}
	return (0);
}

t_map_lst	*get_map_infos(int fd_map)
{
	t_map_info	dt;

	dt.count = 0;
	dt.map_lst = NULL;
	dt.tail = NULL;
	while (dt.count < 6)
	{
		dt.line = get_next_line(fd_map);
		if (dt.line == NULL)
			break ;
		if (dt.line && dt.line[0] == '\n')
		{
			free(dt.line);
			continue ;
		}
		dt.line = delete_nl(dt.line);
		dt.type = get_type(dt.line);
		if (dt.type == NO_TYPE)
			return (free_map(dt.map_lst), free(dt.line), get_next_line(-1),
				NULL);
		dt.count++;
		dt.nd = create_node(dt.line, dt.type);
		add_back(&dt.map_lst, &dt.tail, dt.nd);
	}
	return (dt.map_lst);
}

void	fill_data(t_pre_data *dt)
{
	char	***sets;
	char	*set1;
	char	*set2;
	int		count;

	count = 0;
	dt->data->tex_ea = fetch_index_splited(find_info_value(IMG_EA, dt->info), 1,
			' ');
	dt->data->tex_so = fetch_index_splited(find_info_value(IMG_SO, dt->info), 1,
			' ');
	dt->data->tex_we = fetch_index_splited(find_info_value(IMG_WE, dt->info), 1,
			' ');
	dt->data->tex_no = fetch_index_splited(find_info_value(IMG_NO, dt->info), 1,
			' ');
	dt->data->pos = malloc(sizeof(t_pos));
	find_pos(dt->data->map, dt->data->pos);
	dt->data->dir = dt->data->map[dt->data->pos->y_ver][dt->data->pos->x_hor];
	sets = (char ***)malloc(2 * sizeof(char **));
	set1 = fetch_index_splited(find_info_value(FLOOR, dt->info), 1, ' ');
	sets[0] = ft_split(set1, ',');
	set2 = fetch_index_splited(find_info_value(CEILEING, dt->info), 1, ' ');
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
}

t_pre_data	* read_file(char *file)
{
	int			fd_map;
	t_pre_data	*dt;

	dt = (t_pre_data *)malloc(sizeof(t_pre_data));
	dt->data = (t_parse_data *)malloc(sizeof(t_parse_data));
	if (!dt || !dt->data)
		return (NULL);
	fd_map = safe_open(file, dt);
	dt->info = get_map_infos(fd_map);
	if (check_unicty_infos(dt->info))
		return (free_map(dt->info), free(dt->data), free(dt),
			printf("unicty err\n"), NULL);
	if (dt->info)
	{
		dt->map = check_map(fd_map);
		if (!dt->map)
			return (close(fd_map), free_map(dt->info), free(dt->data),
				free_map(dt->map), free(dt), NULL);
		if (parse_map(dt->map))
			return (close(fd_map), free_map(dt->info), free(dt->data),
				free_map(dt->map), free(dt), NULL);
		dt->data->map = list_to_array(dt->map);
		if (!dt->data->map)
			return (free_split(dt->data->map), free(dt->data), close(fd_map),
				free_map(dt->info), free_map(dt->map), free(dt), NULL);
		if (valid_map(dt->data->map))
			return (free_split(dt->data->map), free(dt->data), close(fd_map),
				free_map(dt->info), free_map(dt->map), free(dt), NULL);
	}
	return (fill_data(dt), free_map(dt->map), close(fd_map), dt);
}

// here check the mfc map
/***
 * 1 : walls no escape
 * 2 : objects (1 , 0 or (N,S,W,E) once , space inside map error , outside dayz)
 *      and others
 */

/*
	free linked list ,should return 2d array of map instead .
	list ( rest of file ) is just for read the file
	undefined length
*/
