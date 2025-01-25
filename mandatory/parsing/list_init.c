/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:32:35 by aohssine          #+#    #+#             */
/*   Updated: 2025/01/10 18:02:32 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

t_map_lst	*create_node(char *value, int type)
{
	t_map_lst	*node;

	node = (t_map_lst *)malloc(sizeof(t_map_lst));
	if (!node)
		return (NULL);
	node->value = ft_strdup(value);
	free(value);
	node->type = type;
	node->next = NULL;
	node->prev = NULL;
	return (node);
}

void	add_back(t_map_lst **lst, t_map_lst **tail, t_map_lst *nd)
{
	if (*lst == NULL)
		*lst = nd;
	else
	{
		(*tail)->next = nd;
		nd->prev = *tail;
	}
	*tail = nd;
}
