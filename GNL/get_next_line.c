/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 13:47:26 by pedro-hm          #+#    #+#             */
/*   Updated: 2024/11/06 13:44:20 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>

char *get_next_line(int fd)
{
	static char buffer[BUFFER_SIZE + 1];
	static char *rest;
	char *line;
	char *temp;
	int bytes_read;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	while (!line)
	{
		if (!rest)
		{
			bytes_read = read(fd, buffer, BUFFER_SIZE);
			if (bytes_read <= 0)
				return (NULL);
			buffer[bytes_read] = '\0';
			rest = ft_strdup(buffer);
		}
		temp = ft_strchr(rest, '\n');
		if (temp)
		{
			*temp = '\0';
			line = ft_strdup(rest);
			ft_memmove(rest, temp + 1, ft_strlen(temp + 1) + 1);
		}
		else
		{
			line = ft_strdup(rest);
			rest = NULL;
		}
	}
	return (line);
}


// int main(void) {
// 	int fd;
// 	char *line;

// 	fd = open("teste.txt", O_RDONLY);
// 	if (fd == -1) {
// 		perror("Erro ao abrir arquivo");
// 		return 1;
// 	}

// 	line = get_next_line(fd);
// 	printf("Linha 1: %s\n", line ? line : "(null)");
// 	free(line);

// 	line = get_next_line(fd);
// 	printf("Linha 2: %s\n", line ? line : "(null)");
// 	free(line);

// 	line = get_next_line(fd);
// 	printf("Linha 3: %s\n", line ? line : "(null)");
// 	free(line);

// 	line = get_next_line(fd);
// 	printf("Linha 4: %s\n", line ? line : "(null)");
// 	free(line);

// 	line = get_next_line(fd);
// 	printf("Linha 5: %s\n", line ? line : "(null)");
// 	free(line);

// 	line = get_next_line(fd);
// 	printf("Linha 6: %s\n", line);
// 	free(line);

// 	close(fd);
// 	return 0;
// }
