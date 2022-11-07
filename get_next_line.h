/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: atsug0 <atsug0@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/27 15:18:07 by atsug0            #+#    #+#             */
/*   Updated: 2022/10/04 12:22:58 by atsug0           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE
#define GET_NEXT_LINE

# include<unistd.h>
# include<stdlib.h>
# include <fcntl.h>
# include <stdio.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

char *ft_strchr(char *s, int c);
char *ft_strjoin(char *s1, char *s2);
int ft_strlen(char *str);



#endif