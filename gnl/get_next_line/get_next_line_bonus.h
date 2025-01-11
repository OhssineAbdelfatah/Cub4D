/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilaasri <ilaasri@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 16:44:45 by ilaasri           #+#    #+#             */
/*   Updated: 2024/01/18 16:44:47 by ilaasri          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include <limits.h>
# include <stdlib.h>
# include <unistd.h>

struct		s_my2
{
	int		i;
	int		j;
	int		x;
	int		s2len;
	int		s1len;
	char	*res;
};
struct		s_next2
{
	int		readed;
	int		nlpos;
	int		len;
	char	*zoom;
	char	*res;
};
char		*fabor(struct s_next2 *var, char **chyata, int whichone);
void		freedom(char **zoom, char **chyata, char **res, int howmany);
char		*elso2(char *res, char **chyata, int nlpos, char *zoom);
char		*lecture2(struct s_next2 *var, char **chyata, int fd);
int			ft_strlen(char *s);
int			find_nl(char *s);
char		*ft_substr(char *s, int start, int len);
char		*ft_strjoin(char *s1, char *s2, int len);
char		*get_next_line(int fd);

#endif
