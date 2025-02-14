/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handler_map_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:36:18 by pdro              #+#    #+#             */
/*   Updated: 2025/02/14 18:35:26 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	read_map(char **argv, t_game *game)
{
	int		fd;
	int		line_count;
	char	*line;
	int		i;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		ft_printf("Error\nInvalid map_path/map\n");
		free_game_resources(game);
		exit(EXIT_FAILURE);
	}
	game->map.width = ft_line_length(fd);
	line_count = ft_count_lines(fd, game);
	game->map.height = line_count;
	game->map.map = malloc(sizeof(char *) * (line_count + 1));
	close(fd);
	fd = open(argv[1], O_RDONLY);
	map_is_not_ber(argv, game);
	line = NULL;
	create_map(game, line, i, fd);
	close(fd);
}

void	map_is_not_ber(char **argv, t_game *game)
{
	if (!game->map.map)
	{
		perror("Error\nInvalid map_path/map\n");
		free_game_resources(game);
		exit(EXIT_FAILURE);
	}
	if (ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])) == NULL)
	{
		ft_printf("Error\nMap has to be .ber\n");
		free_game_resources(game);
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

int	ft_count_lines(int fd, t_game *game)
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
			ft_printf("Error\nThere is no map in the file\n");
			free_game_resources(game);
			exit_error(game);
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
