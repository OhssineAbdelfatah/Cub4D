/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:22:54 by aohssine          #+#    #+#             */
/*   Updated: 2024/11/20 21:46:40 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/parsing.h"
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
int verify_obj()
{
    
    return 0;
}

int return_type(char *tokens)
{
    int type;
    int i;

    i = 0;
    type = NO_TYPE;
    if(!ft_strncmp(tokens, "F", 1))
        type = FLOOR;
    else    if(!ft_strncmp(tokens, "C",1))
        type = CEILEING;
    else    if(!ft_strncmp(tokens, "SO",2))
        type = IMG_SO;
    else    if(!ft_strncmp(tokens, "NO",2))
        type = IMG_NO;
    else    if(!ft_strncmp(tokens, "EA",2))
        type = IMG_EA;
    else    if(!ft_strncmp(tokens, "EA",2))
        type = IMG_WE;
    else
        type = MAP_LINE;
    return type;
}

int get_type(char *line)
{
    char **tokens;
    int type ;
    
    type = NO_TYPE;
    tokens = ft_split(line, ' ');
    if(!tokens)
        return type ;
    if(tokens[0])
        type = return_type(tokens[0]);
    return type;
}


t_map_lst **read_map(char *file)
{
    int fd_map;
    t_map_lst **map_lst ;
    char *line;
    
    map_lst = NULL;
    fd_map = open(file, O_RDONLY);
    if(fd_map == -1 )
        return NULL;
    while(1)
    {
        line = get_next_line(fd_map);
        if(line == NULL)
            break;
        // get_line(line) NO_TYPE handle it
        if(line && line[0] == '\n')
        {
            free(line);
            continue;
        }
        add_back(map_lst, create_node(line, get_type(line)));
        free(line);
    }
    return map_lst;
}
