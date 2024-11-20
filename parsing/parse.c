/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:39:59 by aohssine          #+#    #+#             */
/*   Updated: 2024/11/20 21:35:53 by aohssine         ###   ########.fr       */
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
    else    if(type == IMG_NO)
        printf("IMG_NO\n");
    else    if(type == IMG_EA)
        printf("IMG_EA\n");
    else        
        printf("MAP LINE\n");
}

void print_map(t_map_lst* head)
{
    while(head){
        printf("************************************\n");
        printf("value [%s]\n", head->value);
        print_type(head->type);
        printf("value [%s]\n", head->value);
        printf("************************************\n\n");
    }
}
/*  print   test    only    */

int check_ext(char *ext)
{
    int last;
    int four;
    char base_ext[4] = ".cub";
    four = 4;
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
    return 0;
}

int cube(char *ext)
{
    t_map_lst **list;
    
    if(check_ext(ext))
        return 1;
    list = read_map(ext);
    if(!list)
        return 1;
    print_map(*list);
        return 1;
    return 0;
}

int main(int ac, char **av)
{
    if(ac == 2){
        if(cube(av[1])){
            write(2, "Error\n", 6);
            return 0;
        }
        write(1, "valid map name\n", 15);
    }
    else{  
        write(2, "Error\n", 6);
    } 
    return 0;
}