/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 19:08:37 by pdro              #+#    #+#             */
/*   Updated: 2025/02/04 16:32:37 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void enemy_move(t_game *game)
{
    double current_time;
    current_time = mlx_get_time();

    if (current_time - game->enemy.last_move_time > 0.8)
    {
        calculate_distance_enemy_to_wall(game);

        if (g_enemy_moving_up)
        {
            if (game->enemy.dist_up > 0 && !is_wall(game, game->enemy.x, game->enemy.y - TILE_SIZE))
            {
                game->enemy.y -= TILE_SIZE;
                game->enemy.dist_up -= TILE_SIZE;
            }
            else
                g_enemy_moving_up = false;
        }
        else
        {
            if (game->enemy.dist_down > 0 && !is_wall(game, game->enemy.x, game->enemy.y + TILE_SIZE))
            {
                game->enemy.y += TILE_SIZE;
                game->enemy.dist_down -= TILE_SIZE;
            }
            else
                g_enemy_moving_up = true;
        }

        game->enemy.last_move_time = current_time;

        // Atualiza a posição do inimigo sem recriar a imagem
        game->map.enemy_img->instances[0].x = game->enemy.x;
        game->map.enemy_img->instances[0].y = game->enemy.y;
    }

    refresh_player(game); // Garante que o player seja redesenhado corretamente
}
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
				game->enemy.x = x * TILE_SIZE;
				game->enemy.y = y * TILE_SIZE;
				return ;
			}
			x++;
		}
		y++;
	}
}
void	calculate_distance_enemy_to_wall(t_game *game)
{
	while (game->map.map[(game->enemy.y - game->enemy.dist_up) / TILE_SIZE]
		[(game->enemy.x) / TILE_SIZE] != '1')
		game->enemy.dist_up += TILE_SIZE;
	while (game->map.map[(game->enemy.y + game->enemy.dist_down) / TILE_SIZE]
		[(game->enemy.x) / TILE_SIZE] != '1')
		game->enemy.dist_down += TILE_SIZE;
}
