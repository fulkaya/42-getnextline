/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulkaya <fulkaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:28:20 by fulkaya           #+#    #+#             */
/*   Updated: 2026/04/21 22:24:19 by fulkaya          ###   ########.fr       */
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

static char	*extract_line(char **stash, t_line *t)
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

static void	fill_stash(int fd, char **stash, t_line *t)
{
	t->readed = read(fd, t->buffer, BUFFER_SIZE);
	if (t->readed <= 0)
		return ;
	t->buffer[t->readed] = '\0';
	if (*stash == NULL)
		*stash = ft_strdup("");
	t->temp = ft_strjoin(*stash, t->buffer);
	free(*stash);
	*stash = t->temp;
}

static char	*get_remaining(char **stash, t_line *t)
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
		fill_stash(fd, &stash[fd], &t);
		if (t.readed == -1)
		{
			free(t.buffer);
			free(stash[fd]);
			return (stash[fd] = NULL);
		}
		if (ft_strchr(stash[fd], '\n') != NULL)
		{
			t.result = malloc(ft_strchr2(stash[fd], '\n') + 2);
			return (extract_line(&stash[fd], &t));
		}
	}
	return (get_remaining(&stash[fd], &t));
}
