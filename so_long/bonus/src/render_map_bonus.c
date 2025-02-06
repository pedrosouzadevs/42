/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:36:00 by pdro              #+#    #+#             */
/*   Updated: 2025/02/06 17:04:12 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	render_map(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x] && (x < game->map.width))
		{
			if (game->map.map[y][x] == '1')
				render_map_wall_floor(game, x, y);
			else
				render_map_others(game, x, y);
			x++;
		}
		y++;
	}
	create_box(game);
}

void	render_map_wall_floor(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->map.wall_img,
		x * TILE_SIZE, y * TILE_SIZE);
}

void	render_map_others(t_game *game, int x, int y)
{
	mlx_image_to_window(game->mlx, game->map.floor_img,
		x * TILE_SIZE, y * TILE_SIZE);
	if (game->map.map[y][x] == 'E')
	{
		mlx_image_to_window(game->mlx, game->map.exit_close_img,
			x * TILE_SIZE, y * TILE_SIZE);
		game->map.exit_x = x;
		game->map.exit_y = y;
	}
	else if (game->map.map[y][x] == 'C')
		mlx_image_to_window(game->mlx, game->map.collectible_img,
			x * TILE_SIZE, y * TILE_SIZE);
	else if (game->map.map[y][x] == 'T')
		mlx_image_to_window(game->mlx, game->enemy.image,
			x * TILE_SIZE, y * TILE_SIZE);
}
