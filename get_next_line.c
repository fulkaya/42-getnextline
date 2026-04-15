/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulkaya <fulkaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:28:20 by fulkaya           #+#    #+#             */
/*   Updated: 2026/04/16 01:30:29 by fulkaya          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*stash;
	char		*result;
	char		*temp;
	int			i;
	int			j;
	ssize_t		readed;

	i = 0;
	j = 0;
	readed = 1;
	buffer = malloc(BUFFER_SIZE + 1);
	while (readed > 0)
	{
		readed = read(fd, buffer, BUFFER_SIZE);
		if (readed == -1)
			return (NULL);
		buffer[readed] = '\0';
		if (stash == NULL)
			stash = malloc(BUFFER_SIZE + 1);
		temp = ft_strjoin(stash, buffer);
		free(stash);
		stash = temp;
		if (ft_strchr(stash, '\n') != NULL)
		{
			result = malloc(ft_strchr2(stash, '\n') + 1);
			while (stash[i] != '\n')
			{
				result[j] = stash[i];
				i++;
				j++;
			}
			result[j] = '\0';
			temp = ft_strdup(ft_strchr(stash, '\n') + 1);
			free(stash);
			stash = temp;
			free (buffer);
			return (result);
		}
	}
	free (buffer);
	free(stash);
	return (NULL);
}

#include <stdio.h>
#include <fcntl.h>

int	main(void)
{
	char	*str;
	int		fd;

	fd = open("test.txt", O_RDWR);
	if (fd == -1)
		return (1);
	str = get_next_line(fd);
	while (str != NULL)
	{
		printf("%s\n", str);
		free(str);
		str = get_next_line(fd);
	}
	close(fd);
	return (0);
}
