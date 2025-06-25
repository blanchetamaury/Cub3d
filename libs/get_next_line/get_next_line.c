/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amblanch <amblanch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 13:03:58 by amblanch          #+#    #+#             */
/*   Updated: 2025/06/25 11:40:33 by amblanch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_memset_gnl(char *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		s[i] = c;
		i++;
	}
	return (s);
}

static size_t	ft_strlcpy_gnl(char *dst, char *src, size_t size)
{
	size_t	i;

	i = 0;
	if (dst == 0 || src == 0)
		return (0);
	if (size)
	{
		while (*src && i < size)
		{
			*dst++ = *src++;
			i++;
		}
		*dst = '\0';
	}
	return (ft_strlen_gnl(src) + i);
}

static char	*ft_rest(char *line, char *buf, int bytesread, int i)
{
	static char	rest[BUFFER_SIZE];
	int			len;

	if (ft_strlen_gnl(rest) > 0)
	{
		len = ft_strchr_gnl(rest, '\n');
		if (len > 0)
		{
			line = ft_strjoin_gnl(line, rest, len);
			ft_strlcpy_gnl(rest, &rest[len], BUFFER_SIZE - len);
			free(buf);
			return (line);
		}
		else
		{
			line = ft_strjoin_gnl(line, rest, BUFFER_SIZE);
			ft_memset_gnl(rest, 0, BUFFER_SIZE);
		}
	}
	if (bytesread > 0)
		ft_strlcpy_gnl(rest, &buf[i], bytesread);
	return (line);
}

static char	*ft_line(char *buf, char *line, int fd)
{
	int	bytesread;
	int	len;

	bytesread = read(fd, buf, BUFFER_SIZE);
	while (bytesread > 0)
	{
		buf[bytesread] = '\0';
		len = ft_strchr_gnl(buf, '\n');
		if (len >= 0)
		{
			line = ft_strjoin_gnl(line, buf, len);
			ft_rest(line, buf, BUFFER_SIZE - len, len);
			free(buf);
			return (line);
		}
		else
			line = ft_strjoin_gnl(line, buf, BUFFER_SIZE);
		bytesread = read(fd, buf, BUFFER_SIZE);
	}
	if (bytesread == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}

char	*get_next_line(int fd)
{
	char		*buf;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (0);
	buf = ft_calloc_gnl(BUFFER_SIZE + 1, sizeof(char));
	if (buf == 0)
		return (0);
	line = ft_calloc_gnl(BUFFER_SIZE, sizeof(char));
	if (line == 0)
		return (0);
	line = ft_rest(line, buf, 0, 0);
	if (ft_strchr_gnl(line, '\n') > 0)
		return (line);
	line = ft_line(buf, line, fd);
	if (ft_strchr_gnl(line, '\n') > 0)
		return (line);
	free(buf);
	if (ft_strlen_gnl(line) > 0)
		return (line);
	free(line);
	return (NULL);
}
