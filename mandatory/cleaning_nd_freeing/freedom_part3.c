/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom_part3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 20:22:19 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/19 20:22:21 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

void	free_text(t_text *text)
{
	int	i;

	if (!text)
		return ;
	i = 0;
	while (i < (text->hieght))
	{
		free((text->pixels[i]));
		text->pixels[i] = NULL;
		i++;
	}
	free(text->pixels);
	text->pixels = NULL;
	free(text);
}

void	free_texts(t_text **text)
{
	int	i;

	i = 0;
	if (!text)
		return ;
	while (i < 4)
	{
		free_text(text[i]);
		text[i] = NULL;
		i++;
	}
	free(text);
}

void	free_d_arr(char **av)
{
	int	i;

	if (!av)
		return ;
	i = 0;
	while (av[i])
	{
		free(av[i]);
		av[i] = NULL;
		i++;
	}
	free(av);
}

void	reset_them_all(t_main_s *var)
{
	var->map = NULL;
	var->mlx = NULL;
	var->img2 = NULL;
	var->text = NULL;
	var->p_infos = NULL;
}
