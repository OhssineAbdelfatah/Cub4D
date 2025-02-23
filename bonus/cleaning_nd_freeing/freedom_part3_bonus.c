/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   freedom_part3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:39:43 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/19 23:39:45 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

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

void	free_main_bonus(t_bonus *var, t_main_s *main)
{
	if (var->door)
		free_text(var->door);
	if (var->dead_enemy_text)
		free_text(var->dead_enemy_text);
	if (var->enemy_text)
		free_text(var->enemy_text);
	if (var->floor_text)
		free_text(var->floor_text);
	if (var->sky_text)
		free_text(var->sky_text);
	if (var->obj_img)
		free_text(var->obj_img);
	mlx_delete_image(main->mlx, var->crosshair_img);
	free(var);
}

void	reset_them_all(t_main_s *var)
{
	var->map = NULL;
	var->mlx = NULL;
	var->img2 = NULL;
	var->text = NULL;
	var->mini_map = NULL;
	var->p_infos = NULL;
	var->bonus = NULL;
}
