/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulkaya <fulkaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 19:15:11 by fulkaya           #+#    #+#             */
/*   Updated: 2026/04/16 05:09:30 by fulkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdlib.h>
# include <unistd.h>

# define MAX_FD 1024

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

typedef struct s_line
{
	char	*buffer;
	char	*result;
	char	*temp;
	int		i;
	int		j;
	ssize_t	readed;
}	t_line;

char	*ft_strjoin(char *str1, char *str2);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s);
char	*get_next_line(int fd);

int		ft_strlen(char *str);
int		ft_strchr2(char *s, int c);

void	ft_putstr_fd(char *s, int fd);

#endif
