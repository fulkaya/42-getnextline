/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fulkaya <fulkaya@student.42kocaeli.com.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 19:49:30 by fulkaya           #+#    #+#             */
/*   Updated: 2026/04/16 01:22:01 by fulkaya          ###   ########.fr       */
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

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == '\0' && s[i] == (char)c)
		return ((char *)&s[i]);
	return (NULL);
}

int	ft_strchr2(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			return (i);
		i++;
	}
	if (s[i] == '\0' && s[i] == (char)c)
		return (i);
	return (-1);
}

int	ft_strlcpy(char *dst, char *src, int size)
{
	int	i;
	int	src_len;

	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	i = 0;
	while (src[i] && i < (size - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

int	ft_strlcat(char *dst, char *src, int size)
{
	int	i;
	int	dst_len;
	int	src_len;

	dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	i = 0;
	if (size == 0)
		return (src_len);
	if (dst_len >= size)
		return (src_len + size);
	while (src[i] && (dst_len + i) < size - 1)
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}

char	*ft_strjoin(char *str1, char *str2)
{
	char	*result;
	int		len;
	int		len2;

	if (!str1 || !str2)
		return (NULL);
	len = ft_strlen(str1);
	len2 = ft_strlen(str2);
	result = malloc(len + len2);
	if (!result)
		return (NULL);
	ft_strlcpy(result, str1, len + 1);
	ft_strlcat(result, str2, len + len2 + 1);
	return (result);
}

void	*ft_memcpy(void *dest, void *src, int n)
{
	unsigned char		*d;
	unsigned char		*s;
	int					i;

	if (!dest && !src)
		return (NULL);
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}

char	*ft_strdup(char *s)
{
	char	*dest;
	int		len;

	len = ft_strlen(s);
	dest = (char *)malloc(len + 1);
	if (dest == NULL)
		return (NULL);
	ft_memcpy(dest, s, len);
	dest[len] = '\0';
	return (dest);
}
