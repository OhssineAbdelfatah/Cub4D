/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   infos_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: blacksniper <blacksniper@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 18:02:25 by aohssine          #+#    #+#             */
/*   Updated: 2025/01/26 21:37:56 by blacksniper      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/parsing.h"

int	valid_set(char *set)
{
	char	**sets;
	int		i;

	sets = ft_split(set, ',');
	if (!sets)
		return (1);
	if (count_occ(set, ',') != 2 || ft_strslen(sets) != 3)
		return (free_split(sets), 1);
	if (chcek_set_len(sets))
		return (free_split(sets), 1);
	i = 0;
	while (sets[i])
	{
		if (ft_atoi(sets[i]) > 255 || ft_atoi(sets[i]) < 0)
			return (free_split(sets), 1);
		i++;
	}
	free_split(sets);
	return (0);
}

// tsawer bach biti tkhdem abatal
int	handel_file(char *texture)
{
	if (check_ext(texture, ".png"))
	{
		printf("texture ext error\n");
		return (1);
	}
	if (file_exist(texture))
	{
		printf("texture permission error\n");
		return (1);
	}
	return (0);
}

int	__type_color(int type)
{
	return (type == CEILEING || type == FLOOR);
}

int	__type_tex(int type)
{
	return (type == IMG_EA || type == IMG_NO || type == IMG_SO
		|| type == IMG_WE);
}

	/*
		u caan split textures chcek and colors sets
	*/
	// texture name with spaces should handeld here in second if
int	get_type(char *line)
{
	char	**tokens;
	int		type;

	type = NO_TYPE;
	tokens = ft_split(line, ' ');
	if (!tokens)
		return (type);
	if (ft_strslen(tokens) != 2)
		return (free_split(tokens), type);
	if (tokens[0])
		type = return_type(tokens[0]);
	if (__type_tex(type))
	{
		if (handel_file(tokens[1]))
			type = NO_TYPE;
	}
	else if (__type_color(type))
	{
		if (valid_set(tokens[1]))
			type = NO_TYPE;
	}
	return (free_split(tokens), type);
}
