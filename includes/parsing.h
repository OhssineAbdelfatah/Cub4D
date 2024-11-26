/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:39:01 by aohssine          #+#    #+#             */
/*   Updated: 2024/11/26 02:29:25 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
#define PARSING_H

/*  COLORS  */

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"



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
typedef struct s_map_lst t_map_lst;

/*TEST*/
void print_type(int type);
void print_map(t_map_lst* head);
/*TEST*/

typedef enum s_type {
    IMG_WE,
    IMG_NO,
    IMG_EA,
    IMG_SO,
    CEILEING,
    FLOOR,
    NO_TYPE,
    MAP_LINE,
    NEW_LINE,
}   t_type ;


/* GET INFOS NORM*/
typedef struct s_map_info{
    t_map_lst *map_lst ;
    t_map_lst *tail ;
    t_map_lst *nd ;
    int count ;
    char *line;
    int type ;
} t_map_info;

struct s_map_lst {
    char *value;
    int type;
    t_map_lst *next;
};

/*  MAP */
t_map_lst *read_map(char *file);
void free_map(t_map_lst *list);
int check_ext(char *ext, char* base_ext);
// void add_back(t_map_lst** lst, t_map_lst* nd);
char *delete_nl(char *line);
int get_type(char *line);
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

int __type_color(int type);
int __type_tex(int type);


/* MAP ARR */
t_map_lst *check_map(int fd_map);


/*  MAP LIST  */
void free_map(t_map_lst *list);


#endif