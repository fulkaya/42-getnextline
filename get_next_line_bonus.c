/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulkaya <fulkaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:28:20 by fulkaya           #+#    #+#             */
/*   Updated: 2026/04/18 16:09:48 by fulkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*helper(char **stash, t_line *t)
{
	if (!t->result)
	{
		free(t->buffer);
		free(*stash);
		return (NULL);
	}
	while ((*stash)[t->i] != '\n')
		t->result[t->j++] = (*stash)[t->i++];
	t->result [t->j++] = '\n';
	t->result[t->j] = '\0';
	t->temp = ft_strdup(ft_strchr(*stash, '\n') + 1);
	free(*stash);
	*stash = t->temp;
	free (t->buffer);
	return (t->result);
}

void	helper2(int fd, char **stash, t_line *t)
{
	t->readed = read(fd, t->buffer, BUFFER_SIZE);
	t->buffer[t->readed] = '\0';
	if (*stash == NULL)
		*stash = ft_strdup("");
	t->temp = ft_strjoin(*stash, t->buffer);
	free(*stash);
	*stash = t->temp;
}

char	*helper3(char **stash, t_line *t)
{
	free (t->buffer);
	if (*stash != NULL && **stash != '\0')
	{
		t->result = ft_strdup(*stash);
		*stash[0] = '\0';
		return (t->result);
	}
	free(*stash);
	return (NULL);
}

char	*get_next_line(int fd)
{
	static char	*stash[MAX_FD];
	t_line		t;

	if (fd < 0 || fd >= MAX_FD || BUFFER_SIZE <= 0)
		return (NULL);
	t = (t_line){NULL, NULL, NULL, 0, 0, 1};
	t.buffer = malloc(BUFFER_SIZE + 1);
	if (!t.buffer)
		return (NULL);
	while (t.readed > 0)
	{
		helper2(fd, &stash[fd], &t);
		if (t.readed == -1)
		{
			free(t.buffer);
			free(stash[fd]);
			return (stash[fd] = NULL);
		}
		if (ft_strchr(stash[fd], '\n') != NULL)
		{
			t.result = malloc(ft_strchr2(stash[fd], '\n') + 2);
			return (helper(&stash[fd], &t));
		}
	}
	return (helper3(&stash[fd], &t));
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*f1;
	char	*f2;
	int		fd1;
	int		fd2;

	fd1 = open("test.txt", O_RDONLY);
	fd2 = open("test2.txt", O_RDONLY);
	f1 = get_next_line(fd1);
	f2 = get_next_line(fd2);
	while (f1 != NULL || f2 != NULL)
	{
		if (f1)
		{
			printf("Dosya-1: %s", f1);
			free(f1);
			f1 = get_next_line(fd1);
		}
		if (f2)
		{
			printf("Dosya-2: %s", f2);
			free(f2);
			f2 = get_next_line(fd2);
		}
	}
	close(fd1);
	close(fd2);
	return (0);
}
