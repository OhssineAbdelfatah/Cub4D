/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacksniper <blacksniper@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:30:04 by aohssine          #+#    #+#             */
/*   Updated: 2025/01/04 11:12:51 by blacksniper      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

char	*delete_nl(char *line)
{
	char	*cln_line;

	cln_line = ft_strndup(line, ft_strlen(line) - 1);
	if (!cln_line)
		return (NULL);
	free(line);
	return (cln_line);
}

int	__space(int c)
{
	return ((c >= 9 && c <= 13) || c == 32);
}

int	only_spaces(char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
	{
		if (!__space(str[i]))
			return (0);
		i++;
	}
	if (i == (int)ft_strlen(str))
		return (1);
	return (0);
}

int	get_type_map(char *line)
{
	if (only_spaces(line))
		return (NEW_LINE);
	else
		return (MAP_LINE);
}

t_map_lst	*check_map(int fd_map)
{
	t_map_info	dt;

	dt.count = 0;
	dt.map_lst = NULL;
	dt.tail = NULL;
	while (1)
	{
		dt.line = get_next_line(fd_map);
		if (dt.line == NULL)
			break ;
		dt.type = get_type_map(dt.line);
		if (ft_strchr(dt.line, '\n') != NULL)
			dt.line = delete_nl(dt.line);
		dt.nd = create_node(dt.line, dt.type);
		add_back(&dt.map_lst, &dt.tail, dt.nd);
	}
	if (!dt.map_lst)
		return (get_next_line(-1), dt.map_lst);
	clean_map_updown(&(dt.map_lst));
	clean_map_downup(&(dt.map_lst));
	return (get_next_line(-1), dt.map_lst);
}
