/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 14:37:40 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/11/13 18:18:56 by pedro-hm         ###   ########.fr       */
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
# define BUFFER_SIZE 1
# endif

char	*get_next_line(int fd);
void	*ft_memmove(void *dest, const void *src, size_t n);
int	ft_strlen(const char *s);
char	*ft_strdup(const char *src);
char	**ft_split(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strchr(const char *str, int c);
int	ft_count_char(int fd, char *buffer);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, const char *src, unsigned int size);
int get_n_times(int fd);
int get_substring_size(int fd);
char **get_string_array(char *buffer, int fd,char **stack);
char	*ft_read_file(char *buffer, char *read_line, int fd);
char *ft_extract_line(char *read_line);
char	*ft_verify_and_copy(int fd, char *buffer, char *read_line, int *br);
char *ft_free(char *read_line);
int	ft_check(int bytes_read, char *read_line);
char	*ft_copy(char *read_line, char *buffer, int bytes_read);
#endif
