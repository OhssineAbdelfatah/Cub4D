/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:22:54 by aohssine          #+#    #+#             */
/*   Updated: 2024/11/21 23:42:15 by aohssine         ###   ########.fr       */
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
    if(!ft_strncmp(tokens, "F", 1) && ft_strlen(tokens)== 1)
        type = FLOOR;
    else    if(!ft_strncmp(tokens, "C",1) && ft_strlen(tokens)== 1)
        type = CEILEING;
    else    if(!ft_strncmp(tokens, "SO",2) && ft_strlen(tokens)== 2)
        type = IMG_SO;
    else    if(!ft_strncmp(tokens, "NO",2) && ft_strlen(tokens)== 2)
        type = IMG_NO;
    else    if(!ft_strncmp(tokens, "EA",2) && ft_strlen(tokens)== 2)
        type = IMG_EA;
    else    if(!ft_strncmp(tokens, "WE",2) && ft_strlen(tokens)== 2)
        type = IMG_WE;
    else
        type = NO_TYPE;
    return type;
}

int check_color(char *set)
{
    
    return 0;    
}

int handel_file(char *path)
{
    if(check_ext(path, ".png")) // tsawer bach biti tkhdem abatal
        return 1;
    if(access(path, R_OK) == 1)
        return 1;
    return 0;
}
int __type_color(int type)
{
    return (type == CEILEING ||   type == FLOOR);
}

int __type_tex(int type)
{
    return ( type == IMG_EA ||   type == IMG_NO ||  type == IMG_SO || type == IMG_WE );
}

int get_type(char *line)
{
    char **tokens;
    int type ;
    
    type = NO_TYPE;
    tokens = ft_split(line, ' ');
    if(!tokens)
        return type ;
    if(ft_strslen(tokens) != 2){
        free_split(tokens);
        return type ;
    }
    if(tokens[0])
        type = return_type(tokens[0]);
    if( __type_tex(type) && handel_file(tokens[1]))
        type = NO_TYPE;
    // check color set
    if( __type_color(type)  && check_color(tokens[1]) )
        type = NO_TYPE;
    free_split(tokens);
    return type;
}

void print_node(t_map_lst *nd)
{
    if(nd){
        printf("value [%s]\n", nd->value);
        print_type(nd->type);
        nd=nd->next;
    }
}
char *delete_nl(char *line)
{
    char *cln_line;

    cln_line = ft_strndup(line, ft_strlen(line)-1);
    if(!cln_line)
        return NULL;
    free(line);
    return cln_line;
}

t_map_lst* get_map_infos(int fd_map)
{
    t_map_lst *map_lst ;
    t_map_lst *tail ;
    t_map_lst *nd ;
    int count ;
    char *line;
    int type ;
    
    count = 0 ;
    map_lst = NULL;
    tail = NULL;
    while(count < 6)
    {
        line = get_next_line(fd_map);
        if(line == NULL)
            break;
        if(line && line[0] == '\n')
        {
            free(line);
            continue;
        }
        line = delete_nl(line);
        type = get_type(line);
        if(type == NO_TYPE)
        {
            free_map(map_lst);
            free(line);
            get_next_line(-1);
            return NULL ;
        }
        count++;
        nd = create_node(line, type);
        add_back(&map_lst ,&tail ,nd);
        free(line);
    }
    get_next_line(-1);
    return map_lst;
}

t_map_lst *read_map(char *file)
{
    int fd_map;
    t_map_lst *map_lst ;
    
    fd_map = open(file, O_RDONLY);
    if(fd_map == -1 )
        return NULL;
    map_lst = get_map_infos(fd_map);
    close(fd_map);
    printf("readed map valid\n");
    return map_lst;
}
