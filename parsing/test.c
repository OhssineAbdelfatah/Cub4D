/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/20 13:39:59 by aohssine          #+#    #+#             */
/*   Updated: 2025/01/01 05:50:29 by aohssine         ###   ########.fr       */
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
			printf("%s]\n", head->value);
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
/* TEST ONLY***************************************************************/
