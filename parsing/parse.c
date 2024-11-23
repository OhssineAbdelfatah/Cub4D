/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:39:59 by aohssine          #+#    #+#             */
/*   Updated: 2024/11/22 19:35:37 by aohssine         ###   ########.fr       */
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
    else        
        printf("MAP LINE\n");
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
        // printf("base[%c] == test[%c]\n", base_ext[four], ext[last]);
        if(base_ext[four] != ext[last])
            return 1;
    }
    printf("ext valid\n");
    return 0;
}

int cube(char *ext)
{
    t_map_lst *list;
    
    if(check_ext(ext, ".cub"))
        return 1;
    list = read_map(ext);
    if(!list)
        return 1;
    // print_map(list);
    free_map(list);
    return 0;
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
            write(2, "\033[0;31m Error\033[0m \n", 26);
            return 0;
        }
        write(1, "valid map name\n", 15);
    }
    else{  
        write(2, "Error\n", 6);
    } 
    return 0;
}