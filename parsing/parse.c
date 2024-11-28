/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:39:59 by aohssine          #+#    #+#             */
/*   Updated: 2024/11/26 23:57:29 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/parsing.h"

/*  print   test    only    */

void print_type(int type)
{
    if(type == FLOOR)
        printf("FLOOR\n");
    else    if(type == CEILEING)
        printf("CEILEING\n");
    else    if(type == IMG_SO)
        printf("IMG_SO\n");
    else    if(type == IMG_WE)
        printf("IMG_WE\n");
    else    if(type == IMG_NO)
        printf("IMG_NO\n");
    else    if(type == IMG_EA)
        printf("IMG_EA\n");
    else    if(type == NO_TYPE)
        printf("NO TYPE\n");
    else    if(type == MAP_LINE)
        printf("MAP LINE\n");
    else    if(type == NEW_LINE)
        printf("NEW LINE\n");
    else        
        printf("NON TYPE\n");
}

void print_map(t_map_lst* head)
{
    while(head){
        printf("************************************\n");
        printf("value [%s]\n", head->value);
        print_type(head->type);
        printf("************************************\n\n");
        head=head->next;
    }
}
/*  print   test    only    */

int check_ext(char *ext, char* base_ext)
{
    int last;
    int four;
    four =  ft_strlen(base_ext);
    if(ft_strlen(ext) == 0)
        return 1;
    last = ft_strlen(ext);
    while(four-- != 0 )
    {
        last--;
        if(base_ext[four] != ext[last])
            return 1;
    }
    return 0;
}

int list_size(t_map_lst *list)
{
    int  i ;

    i = 0 ;
    while(list)
    {
        i++;
        list = list->next ;
    }
    return i;
}

int check_unicty_infos(t_map_lst* list)
{
    t_map_lst* tmp;
    if(list_size(list) != 6)
        return ( 1);
    while(list)
    {
        tmp = list->next;
        while(tmp)
        {
            if( list->type > 5 || list->type == tmp->type )
                return (1);
            tmp = tmp->next;
        }
        list = list->next;    
    }
    return 0;
}

int cube(char *ext)
{
    t_pre_data *dt;

    if(check_ext(ext, ".cub"))
        return 1;
    dt = read_map(ext);
    if(!dt || !dt->info)
        return 1;
    return (free_map(dt->info), free(dt), 0);
}

void ff(void )
{
    system("leaks cub3D");
}

int main(int ac, char **av)
{
    atexit(ff);
    if(ac == 2){
        if(cube(av[1])){
            ft_putstr_fd("\033[0;31m Error\033[0m \n", 2);
            return 0;
        }
        ft_putstr_fd("\033[0;32mvalid infos name\033[0m\n", 2);
    }
    else{  
        ft_putstr_fd("Error\n", 2);
    } 
    return 0;
}