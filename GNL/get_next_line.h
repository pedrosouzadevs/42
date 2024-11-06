/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:37:40 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/11/06 13:19:58 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

#include <stddef.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

# ifndef BUFFER_SIZE
# define BUFFER_SIZE 4098
# endif

char	*get_next_line(int fd);
void	*ft_memmove(void *dest, const void *src, size_t n);
size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
int	ft_count_char(int fd, char *buffer);
#endif
