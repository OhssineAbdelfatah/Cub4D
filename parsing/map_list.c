/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacksniper <blacksniper@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:32:35 by aohssine          #+#    #+#             */
/*   Updated: 2024/12/01 16:02:39 by blacksniper      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/parsing.h"

void free_map(t_map_lst *list)
{
    t_map_lst *tmp;
    
    while(list != NULL)
    {
        tmp = list->next;
        free(list->value);
        free(list);
        list = tmp;
    }    
}

t_map_lst *create_node(char *value, int type)
{
    t_map_lst *node;

    node = (t_map_lst *)malloc(sizeof(t_map_lst));
    if(!node)
        return NULL ;
    node->value = ft_strdup(value);
    node->type = type ;
    node->next = NULL;
    node->prev = NULL;
    
    return (node);    
}

void    add_back(t_map_lst** lst ,t_map_lst** tail ,t_map_lst* nd )
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


// void	add_back(t_map_lst **head, t_map_lst **tail, t_map_lst *arg)
// {
// 	if (*head == NULL)
// 		*head = arg;
// 	else
// 		(*tail)->next = arg;
// }