#include "../includes/parsing.h"

void	free_map(t_map_lst *list)
{
	t_map_lst	*tmp;

	while (list != NULL)
	{
		tmp = list->next;
		free(list->value);
		free(list);
		list = tmp;
	}
}

void	clean_map_updown(t_map_lst **map)
{
	t_map_lst	*tmp;

	tmp = *map;
	while (tmp ) 
	{
		if (map && *map && tmp && tmp->value && (only_spaces(tmp->value)
				|| ft_strlen(tmp->value) == 0))
		{
			(*map) = (*map)->next;
			if(*map)
				(*map)->prev = NULL;
			free(tmp->value);
			tmp->next = NULL;
			tmp->prev = NULL;
			free(tmp);
			if(*map)
				tmp = (*map);
		}
		else
			break ;
	}
	while (*map && (*map)->next)
		*map = (*map)->next;
	return ;
}

void	clean_map_downup(t_map_lst **map)
{
	t_map_lst	*tmp;

	tmp = *map;
	while (tmp)
	{
		if (*map && tmp->value && (only_spaces(tmp->value)
				|| ft_strlen(tmp->value) == 0))
		{
			(*map) = (*map)->prev;
			(*map)->next = NULL;
			free(tmp->value);
			tmp->next = NULL;
			tmp->prev = NULL;
			free(tmp);
			tmp = (*map);
		}
		else
			break ;
	}
	while (*map && (*map)->prev)
		*map = (*map)->prev;
	return ;
}

char	**list_to_array(t_map_lst *map_lst)
{
	char	**map_arr;
	int		lst_size;
	int		i;

	lst_size = list_size(map_lst);
	map_arr = malloc((lst_size + 1) * sizeof(char *));
	if (!map_arr)
		return (NULL);
	i = 0;
	while (map_lst)
	{
		map_arr[i] = ft_strdup(map_lst->value);
		map_lst = map_lst->next;
		i++;
	}
	map_arr[i] = NULL;
	free_map(map_lst);
	return (map_arr);
}

int	list_size(t_map_lst *list)
{
	int	i;

	i = 0;
	while (list)
	{
		i++;
		list = list->next;
	}
	return (i);
}
