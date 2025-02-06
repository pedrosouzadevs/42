/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:38:13 by pdro              #+#    #+#             */
/*   Updated: 2025/02/06 15:27:17 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_edge_wall(t_game *game, int x, int y)
{
	if (y == 0 || y == game->map.height - 1)
		if (x >= 0 && x <= game->map.width - 1)
			if (game->map.map[y][x] != '1')
				return (1);
	if (y > 0 && y < (game->map.height - 1))
		if (x == 0 || x == game->map.width - 1)
			if (game->map.map[y][x] != '1')
				return (1);
	return (0);
}

void	verify_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			count_exit_colllectibles_player(game, x, y);
			x++;
		}
		y++;
	}
	if (game->map.exit == 0 || game->map.collectibles == 0
		|| game->map.player == 0)
			error_none_player_exit_colec();
	if (game->map.exit > 1 || game->map.player > 1)
	{
		printf("Error\nMap must have no more than one exit and one player\n");
		exit(EXIT_FAILURE);
	}
	verify_lines_map(game);
	is_map_retangle(game);
}

void	count_exit_colllectibles_player(t_game *game, int x, int y)
{
	if (game->map.map[y][x] == 'E')
		game->map.exit++;
	if (game->map.map[y][x] == 'C')
		game->map.collectibles++;
	if (game->map.map[y][x] == 'P')
		game->map.player++;
	if (is_edge_wall(game, x, y))
		error_wall();
}

void	find_player_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'P')
			{
				game->player.x = x * TILE_SIZE;
				game->player.y = y * TILE_SIZE;
				return ;
			}
			x++;
		}
		y++;
	}
}

void	verify_lines_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
			x++;
		if ((x - 1) != game->map.width)
		{
			printf("Error\nMap must have the same width in all lines\n");
			exit(EXIT_FAILURE);
		}
		y++;
	}
	is_route_valid(game);
}
