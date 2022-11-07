/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsug0 <atsug0@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:19:15 by atsug0            #+#    #+#             */
/*   Updated: 2022/10/19 00:14:10 by atsug0           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_free(char *str)
{
	free(str);
	return (NULL);
}

char	*ft_save(char *save)
{
	char	*res;
	int		len;
	int		i;

	i = 0;
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
		return (ft_free(save));
	res = malloc(sizeof(char) * (ft_strlen(save) - i + 1));
	if (!res)
		return (ft_free(save));
	len = 0;
	i++;
	while (save[i])
		res[len++] = save[i++];
	res[len] = '\0';
	free(save);
	return (res);
}

char	*ft_read(int fd, char *save)
{
	char	*buff;
	int		size_read;

	size_read = 1;
	buff = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buff)
		return (NULL);
	while (!ft_strchr(save, '\n') && size_read != 0)
	{
		size_read = read(fd, buff, BUFFER_SIZE);
		if (size_read == -1)
		{
			free(buff);
			return (NULL);
		}
		buff[size_read] = '\0';
		save = ft_strjoin(save, buff);
	}
	free(buff);
	return (save);
}

char	*ft_get_line(char *save)
{
	int		i;
	char	*res;

	i = 0;
	if (!save[i])
		return (NULL);
	while (save[i] && save[i] != '\n')
		i++;
	res = malloc(sizeof(char) * (i + 2));
	if (!res)
		return (NULL);
	i = 0;
	while (save[i] && save[i] != '\n')
	{
		res[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		res[i++] = '\n';
	res[i] = '\0';
	return (res);
}

char	*get_next_line(int fd)
{
	static char	*save;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (NULL);
	save = ft_read(fd, save);
	if (!save)
		return (NULL);
	if (save[0] == '\n')
	{
		save = ft_save(save);
		return (line);
	}
	line = ft_get_line(save);
	save = ft_save(save);
	return (line);
}

int	main(int argc, char *argv[])
{
	(void)argc;
	char *ar;
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (0);
	ar = get_next_line(fd);
	printf("1-%s",ar);
	close(fd);
	free(ar);
	return (1);
}