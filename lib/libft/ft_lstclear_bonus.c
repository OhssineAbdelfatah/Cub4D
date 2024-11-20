/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 18:40:28 by aohssine          #+#    #+#             */
/*   Updated: 2024/01/03 16:09:18 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (lst && *lst && del)
	{
		while (*lst != NULL)
		{
			temp = *lst;
			*lst = (*lst)->next;
			del(temp->content);
			free(temp);
		}
	}
	*lst = NULL;
}
