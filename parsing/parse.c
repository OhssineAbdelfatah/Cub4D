/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:39:59 by aohssine          #+#    #+#             */
/*   Updated: 2024/11/20 13:49:28 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"../includes/parsing.h"

int ft_strlen(char *str){
    int i = 0;
    if(!str)
        return 0;
    while(*str)
        i++;
    return i;
}

int main(int ac, char **av)
{
    if(ac == 2)
        write(1, "cube3D\n", 7);
    else{  
        write(2, "Error\n", 6);
    } 

}