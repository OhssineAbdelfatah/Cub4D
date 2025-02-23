/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_parse_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:22:54 by aohssine          #+#    #+#             */
/*   Updated: 2025/02/21 00:12:32 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing_bonus.h"

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

t_pre_data	*read_file(char *file)
{
	t_pre_data	*dt;
	int			fd_map;

	dt = (t_pre_data *)malloc(sizeof(t_pre_data));
	dt->data = (t_parse_data *)malloc(sizeof(t_parse_data));
	if (!dt || !dt->data)
		return (NULL);
	fd_map = safe_open(file, dt);
	dt->info = get_map_infos(fd_map);
	if (check_unicty_infos(dt->info))
		return (free_error(dt, 0, 0));
	if (dt->info)
	{
		dt->map = check_map(fd_map);
		if (!dt->map)
			return (close(fd_map), free_error(dt, 1, 0));
		if (parse_map(dt->map))
			return (close(fd_map), free_error(dt, 1, 0));
		dt->data->map = list_to_array(dt->map);
		if (!dt->data->map)
			return (close(fd_map), free_error(dt, 1, 1));
		if (valid_map(dt->data->map))
			return (close(fd_map), free_error(dt, 1, 1));
	}
	return (fill_data(dt), free_map(dt->map), close(fd_map), dt);
}

char	**split2(char *base)
{
	char	**strs;
	char	**new;

	new = NULL;
	strs = ft_split(base, 32);
	if (!strs)
		return (NULL);
	if (ft_strslen(strs) == 1)
	{
		new = (char **)malloc(sizeof(char *) * 2);
		if (!new)
			return (NULL);
		new[0] = ft_strdup(strs[0]);
		new[1] = NULL;
	}
	else if (ft_strslen(strs) > 1)
	{
		new = (char **)malloc(sizeof(char *) * 3);
		if (!new)
			return (NULL);
		new[0] = ft_strdup(strs[0]);
		new[1] = ft_strdup(ft_strchr(base, strs[1][0]));
		new[2] = NULL;
	}
	return (free_split(strs), new);
}
