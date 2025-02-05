/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:08:37 by pdro              #+#    #+#             */
/*   Updated: 2025/02/05 16:14:38 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	find_enemy_position(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map.map[y])
	{
		x = 0;
		while (game->map.map[y][x])
		{
			if (game->map.map[y][x] == 'T')
			{
				game->enemy.x = x;
				game->enemy.y = y;
				game->map.map[y][x] = '0';
				game->map.enemies++;
			}
			x++;
		}
		y++;
	}
}

// void	is_enemy(t_game *game, int x, int y)
// {
// 	int	enemy_x1;
// 	int	enemy_y1;
// 	int	enemy_x2;
// 	int	enemy_y2;

// 	enemy_x1 = x / TILE_SIZE;
// 	enemy_y1 = y / TILE_SIZE;
// 	enemy_x2 = (x + TILE_SIZE - 1) / TILE_SIZE;
// 	enemy_y2 = (y + TILE_SIZE - 1) / TILE_SIZE;
// 	return (game->map.map[enemy_y1][enemy_x1] == 'T' ||
// 			game->map.map[enemy_y1][enemy_x2] == 'T' ||
// 			game->map.map[enemy_y2][enemy_x1] == 'T' ||
// 			game->map.map[enemy_y2][enemy_x2] == 'T');
// }
