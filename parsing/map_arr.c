/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 23:30:04 by aohssine          #+#    #+#             */
/*   Updated: 2024/11/26 17:53:58 by aohssine         ###   ########.fr       */
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

int only_spaces(char *str)
{
    int i;

    i = 0 ;
    while(str && str[i])
    {
        if( !__space(str[i]))
            return 0;
        i++;
    }    
    if( i == (int)ft_strlen(str))
        return 1;
    return 0;
}

t_map_lst *check_map(int fd_map)
{
    t_map_info dt;
    int curr;
    
    dt.count = 0 ;
    dt.map_lst = NULL;
    dt.tail = NULL;

    /***
     * handle lines in first before first map line
     * soultion : get_type_map
    */
   curr = 0;
    while(1)
    {
        dt.line = get_next_line(fd_map);
        if(dt.line == NULL)
            break;
        dt.type = get_type_map(dt.line);
        if(dt.type == MAP_LINE)
            curr = 1;
        // if(dt.type == NO_TYPE)
        //     return (free_map(dt.map_lst),free(dt.line) , get_next_line(-1), NULL);
        if((ft_strlen(dt.line) == 0 ||  dt.line[0] == '\n' || only_spaces(dt.line)) && curr)
        {
            free(dt.line);
            free_map(dt.map_lst);
            return NULL;
            break;
        }
        dt.line = delete_nl(dt.line);
        dt.nd = create_node(dt.line, dt.type);
        add_back(&dt.map_lst ,&dt.tail ,dt.nd);
        free(dt.line);
    }
    print_map(dt.map_lst);
    printf("size [%d]\n", list_size(dt.map_lst));
    return (get_next_line(-1), dt.map_lst);
}
