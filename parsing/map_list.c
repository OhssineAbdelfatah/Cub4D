/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 18:32:35 by aohssine          #+#    #+#             */
/*   Updated: 2024/11/20 21:47:16 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/parsing.h"

t_map_lst *create_node(char *value, int type)
{
    t_map_lst *node;

    node = (t_map_lst *)malloc(sizeof(t_map_lst));
    if(!node)
        return NULL ;
    node->value = ft_strdup(value);
    node->type = type ;
    node->next = NULL;
    
    return (node);    
}

void add_back(t_map_lst** lst, t_map_lst* nd)
{
    t_map_lst* tmp ;    
    if( !nd )
        return ;
    if(lst )
        *lst = nd;
    tmp = *lst;

    while(tmp->next != NULL)
        tmp = tmp->next;
    tmp->next = nd ;
    return ;   
}

// void	add_back(t_map_lst **head, t_map_lst **tail, t_map_lst *arg)
// {
// 	if (*head == NULL)
// 		*head = arg;
// 	else
// 		(*tail)->next = arg;
// }