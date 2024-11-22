/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:39:01 by aohssine          #+#    #+#             */
/*   Updated: 2024/11/21 22:59:58 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

/*TEST*/
void print_type(int type);


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
t_map_lst *read_map(char *file);
void free_map(t_map_lst *list);
// void add_back(t_map_lst** lst, t_map_lst* nd);
void    add_back(t_map_lst** lst,t_map_lst** tail ,t_map_lst* nd );
t_map_lst *create_node(char *value, int type);

typedef struct s_color {
    int floor ;
    int ceiling ;
} t_color;

typedef struct s_pos {
    int x_hor ;
    int y_ver ;
} t_pos;

typedef struct s_dir {
    double n;
    double w;
    double s;
    double e;
} t_dir;

typedef struct s_data{
    char *tex_no;
    char *tex_we;
    char *tex_so;
    char *tex_ea;
    t_color set;
    t_dir dir;
    t_pos *pos;
    char **map;
} t_data;

#endif