/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacksniper <blacksniper@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:30:04 by aohssine          #+#    #+#             */
/*   Updated: 2024/12/01 17:54:43 by blacksniper      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/parsing.h"

// char *skip_newlines(int fd_map)
// {
//     char *line;
//     while(1){
//         line = get_next_line(fd_map);
//         if(line && line[0] == '\n')
//         {
//             free(line);
//             continue;
//         }else{
//             return line;
//         }
//     }
//     return NULL;
// }

int __space(int c)
{
    return ( (c >= 9 && c <= 13) || c == 32);   
}

int get_type_map(char *line)
{
    if(only_spaces(line))
        return NEW_LINE;
    else
        return MAP_LINE;
}

/**
 *
 * return 1 if string is full of spaces and newline at end 
 * return 0 if not
 *  
**/

int only_spaces(char *str)
{
    int i;

    i = 0 ;
    while(str && str[i])
    {
        if( !__space(str[i])) // 1 if whitespace
        if( !__space(str[i]))
            return 0;
        i++;
    }    
    if( i == (int)ft_strlen(str))
        return 1;
    return 0;
}

void clean_map_downup(t_map_lst **map)
{
    t_map_lst *tmp;

    tmp = *map;
    // value here without newline
    while(tmp)
    {
        if(tmp->value && ( only_spaces(tmp->value) || ft_strlen(tmp->value) == 0 ) )
        {
            (*map) = (*map)->prev;
            (*map)->next = NULL;
            free(tmp->value);
            tmp->next = NULL ;
            tmp->prev = NULL ;
            free(tmp);
            tmp = (*map); 
        }
        else
            break;
    }  
    while((*map)->prev)
        *map = (*map)->prev;  
    return ;
}


void clean_map_updown(t_map_lst **map)
{
    t_map_lst *tmp;

    tmp = *map;
    // value here without newline
    while(tmp)
    {
        if( tmp->value && ( only_spaces(tmp->value) || ft_strlen(tmp->value) == 0 ) )
        {
            (*map) = (*map)->next;
            (*map)->prev = NULL;
            free(tmp->value);
            tmp->next = NULL ;
            tmp->prev = NULL ;
            free(tmp);
            tmp = (*map); 
        }
        else
            break;
    }    
    while((*map)->next)
        *map = (*map)->next;
    return ;
}

t_map_lst *check_map(int fd_map)
{
    t_map_info dt;
    // int curr;
    
    dt.count = 0 ;
    dt.map_lst = NULL;
    dt.tail = NULL;

    /***
     * handle lines in first before first map line
     * soultion : get_type_map
    */
//    curr = 0;
//    curr = 0;
    while(1)
    {
        dt.line = get_next_line(fd_map);
        if(dt.line == NULL)
            break;
        dt.type = get_type_map(dt.line);
        // dt.line = delete_nl(dt.line);
        dt.nd = create_node(dt.line, dt.type);
        add_back(&dt.map_lst ,&dt.tail ,dt.nd);
        free(dt.line);
    }
    // print_map(dt.map_lst);
    clean_map_updown(&(dt.map_lst));
    clean_map_downup(&(dt.map_lst));
    print_map(dt.map_lst,'d');
    printf("size [%d]\n", list_size(dt.map_lst));
    return (get_next_line(-1), dt.map_lst);
}
