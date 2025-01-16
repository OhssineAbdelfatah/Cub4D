/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacksniper <blacksniper@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:39:59 by aohssine          #+#    #+#             */
/*   Updated: 2025/01/16 01:08:56 by blacksniper      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

/*  print   test    only    */

void	print_type(int type)
{
	if (type == FLOOR)
		printf("FLOOR\n");
	else if (type == CEILEING)
		printf("CEILEING\n");
	else if (type == IMG_SO)
		printf("IMG_SO\n");
	else if (type == IMG_WE)
		printf("IMG_WE\n");
	else if (type == IMG_NO)
		printf("IMG_NO\n");
	else if (type == IMG_EA)
		printf("IMG_EA\n");
	else if (type == NO_TYPE)
		printf("NO TYPE\n");
	else if (type == MAP_LINE)
		printf("MAP LINE\n");
	else if (type == NEW_LINE)
		printf("NEW LINE\n");
	else
		printf("NON TYPE\n");
}

void	print_map(t_map_lst *head, char dir)
{
	if (dir == 'd')
	{
		while (head)
		{
			print_type(head->type);
			printf("[%s]\n", head->value);
			printf("*****************\n");
			head = head->next;
		}
	}
	else if (dir == 'u')
	{
		while (head)
		{
			print_type(head->type);
			printf("value [%s]\n", head->value);
			printf("*****************\n");
			head = head->prev;
		}
	}
}
/*  print   test    only    */

/* TEST ONLY**************************************************************/
void	print_node(t_map_lst *nd)
{
	if (nd)
	{
		printf("value [%s]\n", nd->value);
		print_type(nd->type);
		nd = nd->next;
	}
}


void print_str(char *str, char *type)
{
	if(!str)
		exit(printf("str %s null\n", type));
	else 
		printf("str %s %s\n", type, str);
}

void print_data(t_parse_data* data)
{
	// int oi = 0 ;
	if(!data)
		printf("data null \n");
	print_str(data->tex_ea,"EA");
	print_str(data->tex_we,"WE");
	print_str(data->tex_so,"SO");
	print_str(data->tex_no,"NO");
	printf("DIR %c\n", data->dir);
	printf("\n");
	int i = 0;
	while(data->map && i < ft_strslen(data->map))
	{
		printf("%s\n",data->map[i]);
		i++;
	}
	printf("\n");
	printf(" color floor %d-%d-%d\n",data->clr_f[0], data->clr_f[1], data->clr_f[2]);
	printf(" color cieling %d-%d-%d\n", data->clr_c[0], data->clr_c[1], data->clr_c[2]);
	printf(" player pos x_hor[%d] y_ver[%d]\n", data->pos->x_hor, data->pos->y_ver);
}
/* TEST ONLY***************************************************************/
