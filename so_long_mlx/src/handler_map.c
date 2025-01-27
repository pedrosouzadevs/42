/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pdro <pdro@student.42.fr>                  #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025-01-26 18:59:32 by pdro              #+#    #+#             */
/*   Updated: 2025-01-26 18:59:32 by pdro             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

char **read_map(char **argv, t_game *game)
{
    int fd;
	int line_count;
    char *line;
    int i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	game->map.width = ft_line_length(fd);
	line_count = ft_count_lines(fd);
	game->map.height = line_count;
	game->map.map = malloc(sizeof(char *) * (line_count + 1));
	if (!game->map.map)
	{
		perror("Error\nInvalid map_path/map\n");
		exit(EXIT_FAILURE);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		printf("Error\nmap has to be .ber\n");
		exit(EXIT_FAILURE);
	}
    while ((line = get_next_line(fd))) { // Lê linha por linha usando gnl
        game->map.map[i++] = line; // Armazena a linha no array de strings
    }
    game->map.map[i] = NULL; // Finaliza a matriz com NULL
    close(fd);
    return game->map.map;
}

void	exit_error(void)
{
	printf("Error\nwrong map dimensions\n");
	exit(EXIT_FAILURE);
}

int	ft_count_lines(int fd)
{
	char	*line;
	int		linecount;

	linecount = 1;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		if (ft_strlen(line) == 1 && *line != '\n')
		{
			free(line);
			exit_error();
		}
		else
		{
			free(line);
			linecount++;
		}
	}
	return (linecount);
}
int	ft_line_length(int fd)
{
	char	buffer[1];
	int		length;
	int		bytes;

	buffer[0] = '\0';
	bytes = 1;
	length = 0;
	while (bytes == 1)
	{
		bytes = read(fd, buffer, 1);
		if (buffer[0] != '\n')
			length++;
		else
			break ;
	}
	return (length);
}
