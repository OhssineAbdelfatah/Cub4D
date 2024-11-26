/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:30:04 by aohssine          #+#    #+#             */
/*   Updated: 2024/11/26 02:45:43 by aohssine         ###   ########.fr       */
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

t_map_lst *check_map(int fd_map)
{
    t_map_info dt;
    
    dt.count = 0 ;
    dt.map_lst = NULL;
    dt.tail = NULL;
    while(1)
    {
        dt.line = get_next_line(fd_map);
        if(dt.line == NULL)
            break;
        dt.line = delete_nl(dt.line);
        // dt.type = get_type(dt.line);
        // if(dt.type == NO_TYPE)
        //     return (free_map(dt.map_lst),free(dt.line) , get_next_line(-1), NULL);
        if(ft_strlen(dt.line) == 0)
        {
            free(dt.line);
            continue;
        }
        dt.nd = create_node(dt.line, dt.type);
        add_back(&dt.map_lst ,&dt.tail ,dt.nd);
        free(dt.line);
    }
    return (get_next_line(-1), dt.map_lst);
}
