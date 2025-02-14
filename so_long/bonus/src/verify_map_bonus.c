/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verify_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:35:49 by pdro              #+#    #+#             */
/*   Updated: 2025/02/14 17:58:11 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

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
		error_none_player_exit_colec(game);
	if (game->map.exit > 1 || game->map.player > 1)
		error_more_player_exit(game);
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
	if (game->map.map[y][x] == 'T')
		game->map.enemies++;
	if (is_edge_wall(game, x, y))
		error_wall(game);
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
			error_width_map(game);
		y++;
	}
	is_route_valid(game);
}
