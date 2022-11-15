/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulard <hmoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:19:15 by atsug0            #+#    #+#             */
/*   Updated: 2022/11/11 23:17:28 by hmoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*ft_save(char *save)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	len = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (NULL);
	}
	res = ft_calloc(ft_strlen(save) - i + 1);
	if (!res)
		return (NULL);
	i++;
	while (save[i])
		res[len++] = save[i++];
	res[len] = 0;
	free(save);
	return (res);
}

static char	*ft_read(int fd, char *save)
{
	int		size_read;
	char	*buff;
	char	*line;

	size_read = 1;
	if (!save)
		save = ft_calloc(1);
	buff = ft_calloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (size_read > 0 && !ft_strchr(save, '\n'))
	{
		size_read = read(fd, buff, BUFFER_SIZE);
		if (size_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[size_read] = 0;
		line = ft_strjoin(save, buff);
		free(save);
		save = line;
	}
	free(buff);
	return (save);
}

static char	*ft_get_line(char *save)
{
	int		i;
	char	*res;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	res = ft_calloc(i + 2);
	if (!res)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		res[i] = save[i];
		i++;
	}
	if (save[i] && save[i] == '\n')
		res[i++] = '\n';
	res[i] = 0;
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	if (fd < 0 || BUFFER_SIZE < 1 || read(fd, 0, 0) < 0)
		return (NULL);
	save = ft_read(fd, save);
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}
