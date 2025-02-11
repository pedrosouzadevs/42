/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:38:45 by pdro              #+#    #+#             */
/*   Updated: 2025/02/11 16:18:18 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	read_map(char **argv, t_game *game)
{
	int		fd;
	int		line_count;
	char	*line;
	int		i;

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
	map_is_not_ber(argv);
	line = NULL;
	create_map(game, line, i, fd);
	close(fd);
}

void	map_is_not_ber(char **argv)
{
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		ft_printf("Error\nMap has to be .ber\n");
		exit(EXIT_FAILURE);
	}
}

void	create_map(t_game *game, char *line, int i, int fd)
{
	while (1)
	{
		line = get_next_line(fd);
		if (line)
			game->map.map[i++] = line;
		else
			break ;
	}
	game->map.map[i] = NULL;
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
