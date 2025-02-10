/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedro-hm <pedro-hm@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 17:36:09 by pdro              #+#    #+#             */
/*   Updated: 2025/02/10 16:22:23 by pedro-hm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long_bonus.h"

void	refresh_player(t_game *game)
{
	if (game->player.collected == game->map.collectibles)
	{
		if (game->player.image)
			mlx_delete_image(game->mlx, game->player.image);
		animate_player_evolution(game);
		mlx_image_to_window(game->mlx, game->player.image,
			game->player.x, game->player.y);
	}
	else
	{
		if (game->player.image)
			mlx_delete_image(game->mlx, game->player.image);
		animate_player(game);
		mlx_image_to_window(game->mlx, game->player.image,
			game->player.x, game->player.y);
	}
}

void	exit_open(t_game *game)
{
	if (game->player.collected == game->map.collectibles)
	{
		if (game->map.exit_close_img)
			mlx_delete_image(game->mlx, game->map.exit_close_img);
		mlx_image_to_window(game->mlx, game->map.exit_open_img,
			game->map.exit_x * TILE_SIZE, game->map.exit_y * TILE_SIZE);
		game->map.exit_opened = true;
	}
}
