/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:43:38 by ilaasri           #+#    #+#             */
/*   Updated: 2024/01/18 16:43:44 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

void	freedom(char **zoom, char **chyata, char **res, int howmany)
{
	if (howmany == 1 || howmany == 2 || howmany == 3)
	{
		free(*chyata);
		*chyata = NULL;
	}
	if (howmany == 2 || howmany == 3 || howmany == 5)
	{
		free(*zoom);
		*zoom = NULL;
	}
	if (howmany == 3)
	{
		free(*res);
		*res = NULL;
	}
}

char	*fabor(struct s_next2 *var, char **chyata, int whichone)
{
	if (whichone == 1)
	{
		var->res = ft_strjoin(var->res, *chyata, var->nlpos + 1);
		freedom(&var->zoom, chyata, &var->res, 1);
		return (var->res);
	}
	else
	{
		if (ft_strlen(var->res) != 0)
		{
			return (free(var->zoom), var->res);
		}
		else
		{
			return (freedom(&var->zoom, chyata, &var->res, 3), NULL);
		}
	}
}

char	*lecture2(struct s_next2 *var, char **chyata, int fd)
{
	while (var->readed)
	{
		var->nlpos = find_nl(var->zoom);
		var->len = ft_strlen(var->zoom);
		if (var->nlpos != BUFFER_SIZE)
		{
			var->res = ft_strjoin(var->res, var->zoom, var->nlpos + 1);
			if (!ft_strlen(var->res))
				return (freedom(&var->zoom, chyata, &var->res, 3), NULL);
			*chyata = ft_substr(var->zoom, var->nlpos + 1, var->len
					- (var->nlpos + 1));
			if (ft_strlen(*chyata) == 0)
				freedom(&var->zoom, chyata, &var->res, 1);
			return (var->res);
		}
		var->res = ft_strjoin(var->res, var->zoom, BUFFER_SIZE);
		if (!var->res)
			return (freedom(&var->zoom, chyata, &var->res, 3), NULL);
		var->readed = read(fd, var->zoom, BUFFER_SIZE);
		var->zoom[var->readed] = 0;
	}
	if (ft_strlen(var->res))
		return (freedom(&var->zoom, chyata, &var->res, 5), var->res);
	return (var->res);
}

char	*elso2(char *res, char **chyata, int nlpos, char *zoom)
{
	res = ft_strjoin(res, *chyata, nlpos + 1);
	if (!res)
		return (freedom(&zoom, chyata, &res, 2), NULL);
	*chyata = ft_substr(*chyata, nlpos + 1, ft_strlen(*chyata) - (nlpos + 1));
	if (!*chyata)
		freedom(&zoom, chyata, &res, 1);
	return (free(zoom), res);
}

char	*get_next_line(int fd)
{
	struct s_next2	var;
	static char		*chyata2[OPEN_MAX];

	if (fd > OPEN_MAX || fd < 0)
		return (NULL);
	var.zoom = (char *)malloc(BUFFER_SIZE + 1);
	if (!var.zoom)
		return (freedom(&var.zoom, &chyata2[fd], &var.res, 1), NULL);
	if (BUFFER_SIZE <= 0 || read(fd, var.zoom, 0) != 0)
		return (freedom(&var.zoom, &chyata2[fd], &var.res, 2), NULL);
	var.res = NULL;
	if (ft_strlen(chyata2[fd]))
	{
		var.nlpos = find_nl(chyata2[fd]);
		var.len = ft_strlen(chyata2[fd]);
		if (var.nlpos == var.len)
			var.res = fabor(&var, &chyata2[fd], 1);
		else
			return (elso2(var.res, &chyata2[fd], var.nlpos, var.zoom));
	}
	var.readed = read(fd, var.zoom, BUFFER_SIZE);
	var.zoom[var.readed] = 0;
	if (var.readed != 0)
		return (lecture2(&var, &chyata2[fd], fd));
	return (fabor(&var, &chyata2[fd], 2));
}
