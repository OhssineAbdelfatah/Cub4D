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

int	handel_file(char *path)
{
	if (check_ext(path, ".png")) // tsawer bach biti tkhdem abatal
	{
		printf("texture ext error\n");
		return (1);
	}
	if (access(path, R_OK) != 0)
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
	if (__type_color(type))
	{
		if (valid_set(tokens[1]))
			type = NO_TYPE;
	}
	return (free_split(tokens), type);
}
