/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:47:26 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/11/13 18:25:34 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char	*ft_verify_and_copy(int fd, char *buffer, char *read_line, int *br)
{
	*br = read(fd, buffer, BUFFER_SIZE);
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (buffer == NULL)
	{
		free(buffer);
		return (NULL);
	}
	if (read_line == NULL)
		read_line = ft_strdup("");
	return (read_line);
}

char	*ft_extract_line(char *read_line)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (read_line[i] && read_line[i] != '\n')
		i++;
	if (read_line[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	j = 0;
	while (j < i)
	{
		line[j] = read_line[j];
		j++;
	}
	line[j] = '\0';
	return (line);
}
char	*get_next_line(int fd)
{
    static char		*read_line;
    char			*buffer;
    char			*line;
    char			*temp;
    int				bytes_read;

    buffer = (char *)malloc((BUFFER_SIZE + 1));
    if (!buffer)
        return (NULL);
    read_line = ft_verification_and_copy(fd, buffer, read_line);
    if (!read_line)
    {
        free(buffer);
        return (NULL);
    }
    while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0)
    {
        buffer[bytes_read] = '\0';
        temp = ft_strjoin(read_line, buffer);
        free(read_line);
        read_line = temp;
        if (ft_strchr(read_line, '\n'))
            break ;
    }
    free(buffer);
    if (ft_check(bytes_read, read_line))
    {
        free(read_line);
        read_line = NULL;
        return (NULL);
    }
    line = ft_extract_line(read_line);
    temp = ft_strdup(read_line + ft_strlen(line));
    free(read_line);
    read_line = temp;
    return (line);
}

int	ft_check(int bytes_read, char *read_line)
{
    return (bytes_read < 0 || (bytes_read == 0 && (!read_line || read_line[0] == '\0')));
}
char	*ft_free(char *read_line)
{
	free(read_line);
	return (NULL);
}
