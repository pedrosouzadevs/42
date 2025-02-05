/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movimentation.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:38:39 by pdro              #+#    #+#             */
/*   Updated: 2025/02/05 16:09:34 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_wall(t_game *game, int x, int y)
{
	int	map_x1;
	int	map_y1;
	int	map_x2;
	int	map_y2;

	map_x1 = x / TILE_SIZE;
	map_y1 = y / TILE_SIZE;
	map_x2 = (x + TILE_SIZE - 1) / TILE_SIZE;
	map_y2 = (y + TILE_SIZE - 1) / TILE_SIZE;
	return (game->map.map[map_y1][map_x1] == '1' ||
			game->map.map[map_y1][map_x2] == '1' ||
			game->map.map[map_y2][map_x1] == '1' ||
			game->map.map[map_y2][map_x2] == '1');
}

void	calculate_movement(t_game *game)
{
	int		x;
	int		y;

	x = abs(game->player.x - game->player.prev_x);
	y = abs(game->player.y - game->player.prev_y);
	game->player.dist_traveled += x + y;
	if (game->player.dist_traveled >= TILE_SIZE)
	{
		game->player.dist_traveled = 0;
		game->player.count++;
		ft_printf("count: %d\n", game->player.count);
	}
}

void	movement_with_collision(t_game *game)
{
	next_tile(game);
	if (game->map.exit_opened && game->player.x == game->map.exit_x * TILE_SIZE
		&& game->player.y == game->map.exit_y * TILE_SIZE)
	{
		ft_printf("\nYou win the game\n");
		mlx_close_window(game->mlx);
	}
	if (game->map.map[game->player.y / TILE_SIZE]
		[game->player.x / TILE_SIZE] == 'C')
	{
		game->player.collected++;
		game->map.map[game->player.y / TILE_SIZE]
		[game->player.x / TILE_SIZE] = '0';
		render_map(game);
	}
	player_key_move(game);
}

void	next_tile(t_game *game)
{
	game->player.north = game->map.map[(game->player.y - MOVE_SIZE) / TILE_SIZE]
	[(game->player.x) / TILE_SIZE];
	game->player.south = game->map.map[(game->player.y + MOVE_SIZE
			+ (TILE_SIZE - MOVE_SIZE)) / TILE_SIZE]
	[(game->player.x) / TILE_SIZE];
	game->player.east = game->map.map[(game->player.y) / TILE_SIZE]
	[(game->player.x + MOVE_SIZE + (TILE_SIZE - MOVE_SIZE)) / TILE_SIZE];
	game->player.west = game->map.map[(game->player.y) / TILE_SIZE]
	[(game->player.x - MOVE_SIZE) / TILE_SIZE];
}

void	player_key_move(t_game *game)
{
	if (mlx_is_key_down(game->mlx, MLX_KEY_W)
		&& !is_wall(game, game->player.x, game->player.y - MOVE_SIZE))
		game->player.y -= MOVE_SIZE;
	if (mlx_is_key_down(game->mlx, MLX_KEY_S)
		&& !is_wall(game, game->player.x, game->player.y + MOVE_SIZE))
		game->player.y += MOVE_SIZE;
	if (mlx_is_key_down(game->mlx, MLX_KEY_A)
		&& !is_wall(game, game->player.x - MOVE_SIZE, game->player.y))
		game->player.x -= MOVE_SIZE;
	if (mlx_is_key_down(game->mlx, MLX_KEY_D)
		&& !is_wall(game, game->player.x + MOVE_SIZE, game->player.y))
		game->player.x += MOVE_SIZE;
}
