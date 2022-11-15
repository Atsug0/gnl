/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hmoulard <hmoulard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:19:58 by atsug0            #+#    #+#             */
/*   Updated: 2022/11/11 23:27:55 by hmoulard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*res;
	int		i;
	int		j;

	i = -1;
	j = -1;
	if (s1 == 0)
		return (NULL);
	res = malloc(ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1);
	if (!res)
		return (NULL);
	while (s1[++i])
		res[i] = s1[i];
	while (s2[++j])
		res[i + j] = s2[j];
	res[i + j] = '\0';
	return (res);
}

char	*ft_strchr(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (&s[i]);
		i++;
	}
	return (NULL);
}

void	*ft_calloc(size_t count)
{
	char	*res;
	size_t	i;

	i = 0;
	res = malloc(count);
	if (!res)
		return (NULL);
	while (i < count)
	{
		res[i] = '\0';
		i++;
	}
	return (res);
}
