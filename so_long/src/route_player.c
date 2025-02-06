/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   route_player.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 11:54:17 by pedro-hm          #+#    #+#             */
/*   Updated: 2025/02/06 15:34:14 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	flood_fill(t_game *game, int x, int y)
{
	if (game->map.map_route[y][x] == '0' || game->map.map_route[y][x] == 'C' || game->map.map_route[y][x] == 'E' || game->map.map_route[y][x] == 'P')
	{
		game->map.map_route[y][x] = 'V';
		flood_fill(game, x + 1, y);
		flood_fill(game, x - 1, y);
		flood_fill(game, x, y + 1);
		flood_fill(game, x, y - 1);
	}
}

void	is_route_valid(t_game *game)
{
	int	i;
	int	j;

	find_player_position(game);
	flood_fill(game, game->player.x / TILE_SIZE, game->player.y / TILE_SIZE);
	i = 0;
	while (game->map.map_route[i])
	{
		j = 0;
		while (game->map.map_route[i][j])
		{
			printf("%c", game->map.map_route[i][j]);
			if (game->map.map_route[i][j] == 'E' || game->map.map_route[i][j] == 'C')
			{
				ft_printf("Error\nInvalid route\n");
				exit(EXIT_FAILURE);
			}
			j++;
		}
		i++;
	}
}

void	read_map_route(char **argv, t_game *game)
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	fd = 0;
	game->map.map_route = malloc(sizeof(char *) * (game->map.height + 1));
	if (!game->map.map_route)
	{
		perror("Error\nInvalid map_path/map\n");
		exit(EXIT_FAILURE);
	}
	close(fd);
	fd = open(argv[1], O_RDONLY);
	line = NULL;
	create_map_route(game, line, i, fd);
	close(fd);
}

void	create_map_route(t_game *game, char *line, int i, int fd)
{
	while (1)
	{
		line = get_next_line(fd);
		if (line)
			game->map.map_route[i++] = line;
		else
			break ;
	}
	game->map.map_route[i] = NULL;
}
