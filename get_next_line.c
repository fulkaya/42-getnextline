/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulkaya <fulkaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:28:20 by fulkaya           #+#    #+#             */
/*   Updated: 2026/04/18 16:09:46 by fulkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
	static char	*stash;
	t_line		t;

	t.i = 0;
	t.j = 0;
	t.readed = 1;
	t.buffer = malloc(BUFFER_SIZE + 1);
	if (!t.buffer)
		return (NULL);
	while (t.readed > 0)
	{
		helper2(fd, &stash, &t);
		if (t.readed == -1)
		{
			free(t.buffer);
			free(stash);
			return (NULL);
		}
		if (ft_strchr(stash, '\n') != NULL)
		{
			t.result = malloc(ft_strchr2(stash, '\n') + 2);
			return (helper(&stash, &t));
		}
	}
	return (helper3(&stash, &t));
}
