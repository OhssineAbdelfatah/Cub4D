/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 17:22:54 by aohssine          #+#    #+#             */
/*   Updated: 2024/11/26 02:48:58 by aohssine         ###   ########.fr       */
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

/* TEST ONLY**************************************************************/
void print_node(t_map_lst *nd)
{
    if(nd){
        printf("value [%s]\n", nd->value);
        print_type(nd->type);
        nd=nd->next;
    }
}
/* TEST ONLY***************************************************************/


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

int count_occ(char *set, char c)
{
    int i ;

    i = 0;
    while(set && *set )
    {
        if(*set == c)
            i++;
        set++;    
    }
    return i;
}

int chcek_set_len(char **sets)
{
    int i;
    int j;
    
    i = 0;
    while(sets[i])
    {
        j = 0;
        while(sets[i][j]){
            if(sets[i][j] && sets[i][j] != '0'){
                if(ft_strlen(&sets[i][j]) > 3)
                    return (1);
            }
            j++;
        }    
        i++;
    }
    return 0;
}

int valid_set(char *set)
{
    char **sets;
    int i ;

    sets = ft_split(set, ',');
    if(!sets)
        return 1;
    if(count_occ(set, ',') != 2 || ft_strslen(sets) != 3)
        return (free_split(sets) ,1);
    if(chcek_set_len(sets))
        return (free_split(sets) ,1);
    i = 0;
    while(sets[i])
    {
        if(ft_atoi(sets[i]) > 255 || ft_atoi(sets[i]) < 0 )
            return (free_split(sets) ,1);
        i++;
    }
    free_split(sets);
    return 0;
}

int handel_file(char *path)
{
    if(check_ext(path, ".png")) // tsawer bach biti tkhdem abatal
        return 1;
    if(access(path, R_OK) != 0)
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
    if(ft_strslen(tokens) != 2)
        return ( free_split(tokens), type) ;
    if(tokens[0])
        type = return_type(tokens[0]);
    if( __type_tex(type))
    {
        if(handel_file(tokens[1]))
            type = NO_TYPE;
    }
    if( __type_color(type))
    {
        if(valid_set(tokens[1]))
            type = NO_TYPE;
    } 
    return ( free_split(tokens), type);
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

// NORM
t_map_lst* get_map_infos(int fd_map)
{
    t_map_info dt;
    
    dt.count = 0 ;
    dt.map_lst = NULL;
    dt.tail = NULL;
    while(dt.count < 6)
    {
        dt.line = get_next_line(fd_map);
        if(dt.line == NULL)
            break;
        if(dt.line && dt.line[0] == '\n')
        {
            free(dt.line);
            continue;
        }
        dt.line = delete_nl(dt.line);
        dt.type = get_type(dt.line);
        if(dt.type == NO_TYPE)
            return (free_map(dt.map_lst),free(dt.line) , get_next_line(-1), NULL);
        dt.count++;
        dt.nd = create_node(dt.line, dt.type);
        add_back(&dt.map_lst ,&dt.tail ,dt.nd);
        free(dt.line);
    }
    // return (get_next_line(-1), dt.map_lst);
    return ( dt.map_lst);
}

t_map_lst *read_map(char *file)
{
    int fd_map;
    t_map_lst *map_infos ;
    t_map_lst *rest_of_file ;
    
    rest_of_file = NULL;
    fd_map = open(file, O_RDONLY);
    if(fd_map == -1 )
        return NULL;
    map_infos = get_map_infos(fd_map);
    if(map_infos)
    {
        rest_of_file = check_map(fd_map);
        // print_map(rest_of_file);
        if(!rest_of_file)
            return (close(fd_map), map_infos);
    }
    // here check the mfc map
    /***
     * 1 : walls no escape
     * 2 : objects (1 , 0 or (N,S,W,E) once , space inside map error , outside dayz)
     *      and others
    */
    free_map(rest_of_file);
    return (close(fd_map), map_infos);
}
