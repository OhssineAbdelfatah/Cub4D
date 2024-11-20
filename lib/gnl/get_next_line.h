/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aohssine <aohssine@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/02 18:29:24 by ilaasri           #+#    #+#             */
/*   Updated: 2024/11/10 23:11:09 by aohssine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <stdlib.h>
# include <unistd.h>

struct		s_my
{
	int		i;
	int		j;
	int		x;
	int		s2len;
	int		s1len;
	char	*res;
};
struct		s_next
{
	int		readed;
	int		nlpos;
	int		len;
	char	*zoom;
	char	*res;
};
char		*fabor(struct s_next *var, char **chyata, int whichone);
void		_freedom(char **zoom, char **chyata, char **res, int howmany);
char		*elso2(char *res, char **chyata, int nlpos, char *zoom);
char		*lecture2(struct s_next *var, char **chyata, int fd);
// int			ft_strlen(char *s);
int			find_nl(char *s);
char		*_ft_substr(char *s, int start, int len);
char		*_ft_strjoin(char *s1, char *s2, int len);
char		*get_next_line(int fd);

#endif
