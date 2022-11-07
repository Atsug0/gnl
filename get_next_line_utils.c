/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsug0 <atsug0@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:19:58 by atsug0            #+#    #+#             */
/*   Updated: 2022/09/27 20:27:09 by atsug0           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int ft_strlen(char *str)
{
    int i;

    i = 0;
    if (!str)
        return (0);
    while (str[i] != '\0')
        i++;
    return (i);
}

char *ft_strjoin(char *s1, char *s2)
{
	int	i;
	int j;
	char	*res;
	
    if (!s1)
    {
        s1 = malloc(sizeof(char) * 1);
        s1[0] = '\0';
    }
    if (!s1 || !s2)
        return (NULL);
	res = malloc(sizeof(char) * (ft_strlen((s1) + ft_strlen(s2) + 1)));
	if (!res)
		return (NULL);
    i = -1;
    j = 0;
    if (s1)
        while(s1[++i] != '\0')
            res[i] = s1[i];
    while (s2[j] != '\0')
        res[i++] = s2[j++];
    res[ft_strlen(s1) + ft_strlen(s2)] = 0;
    free(s1);
	return (res); 
}

char *ft_strchr(char *s, int c)
{
    int i;

    i = 0;
    if (!s)
        return (NULL);
    while (s[i])
    {
        if (s[i] == c)
            return (&s[i]);
        i++;
    }
    return (NULL);
}