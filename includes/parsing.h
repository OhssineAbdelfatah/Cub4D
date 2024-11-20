/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:39:01 by aohssine          #+#    #+#             */
/*   Updated: 2024/11/20 21:46:51 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

#include<stdio.h>
#include<errno.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
#include<fcntl.h>

/*   LIB   */
#include"../lib/gnl/get_next_line.h"
#include"../lib/libft/libft.h"

/*   STRUCT MAP   */

typedef enum s_type {
    IMG_WE,
    IMG_NO,
    IMG_EA,
    IMG_SO,
    MAP_LINE,
    CEILEING,
    FLOOR,
    NEW_LINE,
    NO_TYPE
}   t_type ;

typedef struct s_map_lst t_map_lst;
struct s_map_lst {
    char *value;
    int type;
    t_map_lst *next;
};

/*  MAP */
t_map_lst **read_map(char *file);
void add_back(t_map_lst** lst, t_map_lst* nd);
// void	add_back(t_map_lst **head, t_map_lst **tail, t_map_lst *arg);
t_map_lst *create_node(char *value, int type);



#endif