/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:02:39 by aohssine          #+#    #+#             */
/*   Updated: 2025/02/17 16:59:27 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

void	**safe__malloc(void)
{
	void	**dt;

	dt = malloc(sizeof(void *));
	if (!dt)
		exit(1);
	return (dt);
}

void	*safe_malloc(void)
{
	void	**dt;

	dt = malloc(sizeof(void));
	if (!dt)
		exit(1);
	return (dt);
}

int	safe_open(char *file, t_pre_data *dt)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		free(dt->data);
		free(dt);
		ft_putstr_fd("Error open map\n", 2);
		exit(1);
	}
	return (fd);
}
