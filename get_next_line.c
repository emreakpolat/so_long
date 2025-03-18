/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: makpolat <makpolat@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/17 13:42:05 by makpolat          #+#    #+#             */
/*   Updated: 2025/03/18 11:36:19 by makpolat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*retention(char *s, char c)
{
	char	*str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (s[i] && s[i] != c)
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	str = (char *)malloc((ft_strlen_forgnl(s) - i) + 1);
	if (!str)
		return (NULL);
	i++;
	while (s[i])
		str[j++] = s[i++];
	str[j] = '\0';
	free(s);
	return (str);
}

static char	*readfunc(char *s, char c)
{
	char	*str;
	int		i;

	i = 0;
	if (!s[i])
		return (NULL);
	while (s[i] != '\0' && s[i] != c)
		i++;
	str = (char *)malloc(sizeof(char) * (i + 2));
	if (!str)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != c)
	{
		str[i] = s[i];
		i++;
	}
	if (s[i] == c)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*linefunc(int fd, char *s)
{
	char	*buf;
	int		i;

	buf = (char *)malloc(sizeof(char) * (size_t)BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	i = 1;
	while (!ft_strchr(s, '\n') && i != 0)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[i] = '\0';
		s = ft_strjoin(s, buf);
	}
	free(buf);
	return (s);
}

char	*get_next_line(int fd)
{
	char		*str;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = linefunc(fd, line);
	if (!line)
		return (NULL);
	str = readfunc(line, '\n');
	line = retention(line, '\n');
	if (line && *line == '\0')
	{
        free(line);
        line = NULL;
	}
	return (str);
}

char	**gnl_read(int fd, char **av)
{
	int		i;
	int		line_count;
	char	*line;
	char	**map;

	line_count = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		free(line);
		line_count++;
	}
	close(fd);
	map =(char **)malloc(sizeof(char *) * (line_count + 1));
	fd = open(av[1], O_RDONLY);
	i = 0;
	while ((line = get_next_line(fd)) != NULL)
	{
		map[i] = line;
		i++;
	}
	map[i] = NULL;
	return (map);
}
