/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   png_to_text_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/19 23:25:34 by ilaasri           #+#    #+#             */
/*   Updated: 2025/02/19 23:25:35 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ps_bonus.h"

mlx_texture_t	*safe_load(char *path)
{
	mlx_texture_t	*img;

	img = mlx_load_png(path);
	if (!img)
	{
		ft_putstr_fd(path, 2);
		panic("load png failed !\n");
	}
	return (img);
}

int	**gat_pixles(mlx_texture_t *img, int w, int h)
{
	int	**pixs;
	int	i;
	int	j;

	i = 0;
	pixs = malloc(sizeof(int *) * h);
	if (!pixs)
		panic("malooc in pix int** failed\n");
	while (i < h)
	{
		j = 0;
		pixs[i] = (int *)malloc(sizeof(int) * w);
		if (!pixs)
			panic("malooc in pix int* failed\n");
		while (j < w)
		{
			pixs[i][j] = gettt_rgba(&img->pixels[((i * w) + j) * 4]);
			j++;
		}
		i++;
	}
	return (pixs);
}

t_text	*get_image(char *path)
{
	t_text			*img;
	mlx_texture_t	*text;

	text = safe_load(path);
	img = malloc(sizeof(t_text));
	if (!img)
		return (NULL);
	img->pixels = gat_pixles(text, text->width, text->height);
	img->hieght = text->height;
	img->width = text->width;
	mlx_delete_texture(text);
	return (img);
}
