/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:39:01 by aohssine          #+#    #+#             */
/*   Updated: 2025/01/15 00:09:43 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

/*  COLORS  */

# define KNRM "\x1B[0m"
# define KRED "\x1B[31m"
# define KGRN "\x1B[32m"
# define KYEL "\x1B[33m"
# define KBLU "\x1B[34m"
# define KMAG "\x1B[35m"
# define KCYN "\x1B[36m"
# define KWHT "\x1B[37m"

///////////////////////////////////////////////////////////////////////

# include <errno.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

/*   LIB   */
# include "../lib/gnl/get_next_line.h"
# include "../lib/libft/libft.h"

/*   STRUCT MAP   */
typedef struct s_map_lst	t_map_lst;
typedef struct s_parse_data t_parse_data;
typedef enum s_type
{
	IMG_WE,
	IMG_NO,
	IMG_EA,
	IMG_SO,
	CEILEING,
	FLOOR,
	NO_TYPE,
	MAP_LINE,
	NEW_LINE,
}							t_type;

typedef struct s_pre_data
{
	t_map_lst				*info;
	t_map_lst				*map;
	t_parse_data			*data;
}							t_pre_data;

/* GET INFOS NORM*/
typedef struct s_map_info
{
	t_map_lst				*map_lst;
	t_map_lst				*tail;
	t_map_lst				*nd;
	int						count;
	char					*line;
	int						type;
}							t_map_info;

struct						s_map_lst
{
	char					*value;
	int						type;
	t_map_lst				*next;
	t_map_lst				*prev;
};


typedef struct s_pos
{
	int						x_hor;
	int						y_ver;
}							t_pos;

// typedef struct s_data
// {
// 	char					*tex_no;
// 	char					*tex_we;
// 	char					*tex_so;
// 	char					*tex_ea;
// 	t_color					set;
// 	double					dir;
// 	t_pos					*pos;
// 	char					**map;
// }							t_data;

struct s_parse_data
{
	char					**map;
	char					*tex_no;
	char					*tex_we;
	char					*tex_so;
	char					*tex_ea;
	t_pos					*pos;
	char					dir;
	int						*clr_f;
	int						*clr_c;
};
/////////////////////////////////////////////
/////////       FUNCTIONS          //////////
/////////////////////////////////////////////

/*  cub */
int							cube(char *ext, t_parse_data** data);
int							check_ext(char *ext, char *base_ext);

/*  inofs parse */
t_pre_data					*read_file(char *file);
t_map_lst					*get_map_infos(int fd_map);
int							check_unicty_infos(t_map_lst *list);

/*  inofs_utils */
int							get_type(char *line);
int							__type_tex(int type);
int							__type_color(int type);
int							handel_file(char *path);
int							valid_set(char *set);

int							chcek_set_len(char **sets);
int							count_occ(char *set, char c);
int							return_type(char *tokens);

/*  list init   */
t_map_lst					*create_node(char *value, int type);
void						add_back(t_map_lst **lst, t_map_lst **tail,
								t_map_lst *nd);

/*  list utils  */
int							list_size(t_map_lst *list);
char						**list_to_array(t_map_lst *map_lst);
void						clean_map_downup(t_map_lst **map);
void						clean_map_updown(t_map_lst **map);
void						free_map(t_map_lst *list);

/*  map check   */
t_map_lst					*check_map(int fd_map);
int							get_type_map(char *line);
int							only_spaces(char *str);
int							__space(int c);
char						*delete_nl(char *line);

/*  map parse   */
int							parse_map(t_map_lst *map_dbl);
int							verify_obj(char *arr, int *dir);
int							contain_line(char *line);
int							is_valid_obj(char c);
int							__direction(char c);

/*   valid map   */
int							valid_map(char **s_map_lst);

/*	safe functions	*/
void					*safe_malloc(void);
int						safe_open(char *file, t_pre_data *dt);
void					**safe__malloc(void);


/*	main func	*/
t_parse_data	*parse(int ac, char **av);

///////////////////////////////////////////////////////////////////////



/*TEST*/
void						print_type(int type);
void						print_map(t_map_lst *head, char dir);
void print_data(t_parse_data* data);
/*TEST*/
#endif