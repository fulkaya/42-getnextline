/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulkaya <fulkaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 19:15:11 by fulkaya           #+#    #+#             */
/*   Updated: 2026/04/15 22:40:32 by fulkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE

#  define BUFFER_SIZE 42

# endif

char	*ft_strjoin(char *str1, char *str2);
char	*ft_strchr(char *s, int c);
char	*ft_strdup(char *s);

int		ft_strlen(char *str);
int		ft_strchr2(char *s, int c);

void	ft_putstr_fd(char *s, int fd);

#endif
