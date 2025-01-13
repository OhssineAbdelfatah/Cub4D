/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacksniper <blacksniper@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:22:54 by aohssine          #+#    #+#             */
/*   Updated: 2025/01/13 01:16:26 by blacksniper      ###   ########.fr       */
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
	{
		printf("list size diff 6 error, len list %d\n",  list_size(list));
		return (1);
	}
	while (list)
	{
		tmp = list->next;
		while (tmp)
		{
			if (list->type > 5 || list->type == tmp->type)
				return (printf("more infos or err type\n") ,1);
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
			return (free_map(dt.map_lst), free(dt.line), get_next_line(-1),printf("no type err\n"),
				NULL);
		dt.count++;
		dt.nd = create_node(dt.line, dt.type);
		add_back(&dt.map_lst, &dt.tail, dt.nd);
	}
	return (dt.map_lst);
}

void	find_pos(char **map, t_pos *pos)
{
	int	i;
	int	j;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (__direction(map[i][j]))
			{
				pos->x_hor = i;
				pos->y_ver = j;
				return ;
			}
			j++;
		}
		i++;
	}
	return ;
}
// norm

t_pre_data	*read_file(char *file)
{
	int			fd_map;
	t_pre_data	*dt;
	// char		**map_arr;

	dt = (t_pre_data *)malloc(sizeof(t_pre_data));
	dt->data = (t_parse_data *)malloc(sizeof(t_parse_data));
	if(!dt || !dt->data)
		return NULL;
	// dt->data = (t_parse_data *)safe_malloc();
	// dt->data->map = NULL;
	fd_map = safe_open(file, dt);
	dt->info = get_map_infos(fd_map);
	if (check_unicty_infos(dt->info))
		return (free_map(dt->info), free(dt->map), free(dt),printf("unicty err\n"), NULL);
	if (dt->info)
	{
		dt->map = check_map(fd_map);
		if (!dt->map || parse_map(dt->map))
			return (close(fd_map), free_map(dt->info), free_map(dt->map),
				free(dt),printf("dt.map NULL or parse map err\n") ,NULL);
		dt->data->map = list_to_array(dt->map);
		if (!dt->data->map)
			return (free_split(dt->data->map), close(fd_map), free_map(dt->info),
				free_map(dt->map), free(dt),  printf("list to array NULL\n"),NULL);
		if (valid_map(dt->data->map))
			return (free_split(dt->data->map), close(fd_map), free_map(dt->info),
				free_map(dt->map), free(dt), printf("invalid map\n"),NULL);
			
	}
	return (free_map(dt->map), close(fd_map), dt);
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
