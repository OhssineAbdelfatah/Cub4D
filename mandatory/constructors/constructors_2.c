/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   constructors_2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 21:03:12 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/19 21:03:14 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps.h"

int	**get_pixles(mlx_texture_t *img, int w, int h)
{
	int	**pixs;
	int	i;
	int	j;

	i = 0;
	pixs = malloc(sizeof(int *) * h);
	if (!pixs)
		return ((panic("malooc in pix int** failed\n")), NULL);
	while (i < h)
	{
		j = 0;
		pixs[i] = (int *)malloc(sizeof(int) * w);
		if (!pixs)
			return ((panic("malooc in pix int* failed")), NULL);
		while (j < w)
		{
			pixs[i][j] = gettt_rgba(&img->pixels[((i * w) + j) * 4]);
			j++;
		}
		i++;
	}
	return (pixs);
}

t_text	*get_image(mlx_texture_t *text)
{
	t_text	*img;

	img = malloc(sizeof(t_text));
	if (!img)
		return (NULL);
	img->pixels = get_pixles(text, text->width, text->height);
	img->hieght = text->height;
	img->width = text->width;
	mlx_delete_texture(text);
	return (img);
}

mlx_texture_t	*safe_load(char *path)
{
	mlx_texture_t	*img;

	img = mlx_load_png(path);
	if (!img)
	{
		ft_putstr_fd(path, 2);
		panic(" ,load png failed !\n");
	}
	return (img);
}

t_text	*safe_img_cnv(char *path_to_img)
{
	mlx_texture_t	*img;

	img = safe_load(path_to_img);
	return (get_image(img));
}

t_walls	*init_walls(t_main_s *ptr)
{
	t_walls	*var;

	var = malloc(sizeof(*var));
	if (!var)
		panic("malloc failed !\n");
	var->distance_prj_plane = (ptr->window_width / 2) / tan(((M_PI / 180) * 60)
			/ 2);
	var->wall_hight = 0;
	var->prj_plane_height = SQ_LEN / 2;
	return (var);
}
